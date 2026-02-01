// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldBaseScene.h"

#include <gf2/core/ActionSettings.h>
#include <gf2/core/Color.h>
#include <gf2/core/Direction.h>
#include <gf2/core/Keycode.h>
#include <gf2/core/Log.h>
#include <gf2/core/Scancode.h>
#include <gf2/core/Time.h>

#include <gf2/audio/AudioManager.h>

#include "Constants.h"
#include "Game.h"
#include "MaskColor.h"
#include "WorldState.h"
#include "gf2/graphics/Scene.h"

namespace glt {

  WorldBaseScene::WorldBaseScene(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_ground_map(game, resources.map)
  , m_mask(game, resources)
  , m_hero(game, resources)
  , m_mask_map(game, resources.map)
  , m_sounds(game, resources)
  {
    set_clear_color(0xE8D99D);

    set_world_size(TileSize * 10);
    set_world_center(TileSize * 5);

    add_model(game->world_model());

    add_world_entity(&m_ground_map);
    add_world_entity(&m_mask);
    add_world_entity(&m_hero);
    add_world_entity(&m_mask_map);
    add_world_entity(&m_sounds);
  }

  gf::ActionGroupSettings WorldBaseScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("up"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Up).add_scancode_control(gf::Scancode::W));
    settings.actions.emplace("down"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Down).add_scancode_control(gf::Scancode::S));
    settings.actions.emplace("left"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Left).add_scancode_control(gf::Scancode::A));
    settings.actions.emplace("right"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Right).add_scancode_control(gf::Scancode::D));

    settings.actions.emplace("back"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Backspace));

    return settings;
  }

  void WorldBaseScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void WorldBaseScene::do_handle_actions()
  {
    using namespace gf::literals;

    WorldState* state = m_game->world_state();
    HeroState* hero = &state->hero;

    if (m_action_group.active("up"_id)) {
      hero->expected_direction = gf::Direction::Up;
    } else if (m_action_group.active("down"_id)) {
      hero->expected_direction = gf::Direction::Down;
    } else if (m_action_group.active("left"_id)) {
      hero->expected_direction = gf::Direction::Left;
    } else if (m_action_group.active("right"_id)) {
      hero->expected_direction = gf::Direction::Right;
    } else {
      hero->expected_direction = gf::Direction::Center;
    }

    if (m_action_group.active("back"_id)) {
      gf::BasicScene* scenes[] = { &m_game->kickoff_act()->common_scene, &m_game->kickoff_act()->welcome_scene };
      m_game->replace_all_scenes(scenes);
    }

    m_action_group.reset();
  }

  void WorldBaseScene::do_update([[maybe_unused]] gf::Time time)
  {
    const gf::Vec2F hero_location = m_game->world_state()->hero.world_location;
    set_world_center(hero_location);

    update_entities(time);
  }

}
