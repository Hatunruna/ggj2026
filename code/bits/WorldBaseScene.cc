// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldBaseScene.h"

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

namespace glt {

  WorldBaseScene::WorldBaseScene(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_hero(resources.hero_animations, game->render_manager(), game->resource_manager())
  , m_red_mask_sound(game->resource_manager()->get<gf::Sound>(resources.red_mask_audio.filename))
  , m_green_mask_sound(game->resource_manager()->get<gf::Sound>(resources.green_mask_audio.filename))
  , m_blue_mask_sound(game->resource_manager()->get<gf::Sound>(resources.blue_mask_audio.filename))
  {
    set_clear_color(gf::White);

    set_world_size(TileSize * 10);
    set_world_center(TileSize * 5);

    add_model(game->world_model());

    m_hero.set_location(TileSize * 5);
    add_world_entity(&m_hero);

    const gf::Time audio_time = game->audio_manager()->time();
    m_red_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));
    m_green_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));
    m_blue_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));

    m_red_mask_sound->set_looping(resources.red_mask_audio.data.loop);
    m_green_mask_sound->set_looping(resources.green_mask_audio.data.loop);
    m_blue_mask_sound->set_looping(resources.blue_mask_audio.data.loop);

    m_red_mask_sound->set_volume(1.0f);
    m_green_mask_sound->set_volume(0.0f);
    m_blue_mask_sound->set_volume(0.0f);

    m_red_mask_sound->start();
    m_green_mask_sound->start();
    m_blue_mask_sound->start();
  }

  gf::ActionGroupSettings WorldBaseScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("up"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Up).add_scancode_control(gf::Scancode::W));
    settings.actions.emplace("down"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Down).add_scancode_control(gf::Scancode::S));
    settings.actions.emplace("left"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Left).add_scancode_control(gf::Scancode::A));
    settings.actions.emplace("right"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Right).add_scancode_control(gf::Scancode::D));

    return settings;
  }

  void WorldBaseScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void WorldBaseScene::do_handle_actions()
  {
    using namespace gf::literals;

    if (m_action_group.active("up"_id)) {
      m_game->world_state()->process_hero_move(gf::Direction::Up);
    } else if (m_action_group.active("down"_id)) {
      m_game->world_state()->process_hero_move(gf::Direction::Down);
    } else if (m_action_group.active("left"_id)) {
      m_game->world_state()->process_hero_move(gf::Direction::Left);
    } else if (m_action_group.active("right"_id)) {
      m_game->world_state()->process_hero_move(gf::Direction::Right);
    } else {
      m_game->world_state()->process_hero_move(gf::Direction::Center);
    }

    m_action_group.reset();
  }

  void WorldBaseScene::do_update([[maybe_unused]] gf::Time time)
  {
    using namespace gf::literals;

    const HeroState& hero = m_game->world_state()->hero;
    if (hero.direction == gf::Direction::Left) {
      if (hero.running) {
        m_hero.select("run_left"_id);
      } else {
        m_hero.select("pause_left"_id);
      }
    } else if (hero.direction == gf::Direction::Right) {
      if (hero.running) {
        m_hero.select("run_right"_id);
      } else {
        m_hero.select("pause_right"_id);
      }
    } else if (hero.direction == gf::Direction::Up) {
      if (hero.running) {
        m_hero.select("run_up"_id);
      } else {
        m_hero.select("pause_up"_id);
      }
    } else if (hero.direction == gf::Direction::Down) {
      if (hero.running) {
        m_hero.select("run_down"_id);
      } else {
        m_hero.select("pause_down"_id);
      }
    } else {
      m_hero.select("pause_left"_id);
    }

    m_hero.set_location(m_game->world_state()->hero.world_location);

    update_entities(time);
  }

}
