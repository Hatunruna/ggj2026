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
#include "WorldState.h"
#include "gf2/graphics/Scene.h"

namespace glt {

  namespace {
    using namespace gf::literals;

    struct LevelSetting {
      gf::Id id;
      gf::Scancode scancode;
      std::size_t index;
    };

    constexpr LevelSetting LevelSettings[] = {
      { "mask0"_id, gf::Scancode::Num1, 0 },
      { "mask1"_id, gf::Scancode::Num2, 1 },
      { "mask2"_id, gf::Scancode::Num3, 2 },
      { "mask3"_id, gf::Scancode::Num4, 3 },
      { "mask4"_id, gf::Scancode::Num5, 4 },
      { "mask5"_id, gf::Scancode::Num6, 5 },
      { "mask6"_id, gf::Scancode::Num7, 6 },
      { "mask7"_id, gf::Scancode::Num8, 7 },
      { "mask8"_id, gf::Scancode::Num9, 8 },
      { "mask9"_id, gf::Scancode::Num0, 9 },
    };

  }

  WorldBaseScene::WorldBaseScene(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_inventory(game, resources)
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

    add_hud_entity(&m_inventory);

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

    for (const LevelSetting level_setting : LevelSettings) {
      settings.actions.emplace(level_setting.id, gf::instantaneous_action().add_scancode_control(level_setting.scancode));
    }

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

    for (const LevelSetting level_setting : LevelSettings) {
      if (m_action_group.active(level_setting.id)) {
        if (level_setting.index != state->map.current_mask && state->is_mask_available(level_setting.index)) {
          state->map.current_mask = level_setting.index;
          break;
        }
      }
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
