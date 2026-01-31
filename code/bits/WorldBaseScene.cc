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

namespace glt {

  WorldBaseScene::WorldBaseScene(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_ground_map(game, resources.tutorial_map)
  , m_hero(game, resources)
  , m_mask_map(game, resources.tutorial_map)
  , m_red_mask_sound(game->resource_manager()->get<gf::Sound>(resources.red_mask_audio.filename))
  , m_green_mask_sound(game->resource_manager()->get<gf::Sound>(resources.green_mask_audio.filename))
  , m_blue_mask_sound(game->resource_manager()->get<gf::Sound>(resources.blue_mask_audio.filename))
  {
    set_clear_color(gf::White);

    set_world_size(TileSize * 10);
    set_world_center(TileSize * 5);

    add_model(game->world_model());

    m_hero.set_location(TileSize * 5);
    add_world_entity(&m_ground_map);
    add_world_entity(&m_hero);
    add_world_entity(&m_mask_map);

    const gf::Time audio_time = game->audio_manager()->time();
    m_red_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));
    m_green_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));
    m_blue_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));

    m_red_mask_sound->set_looping(resources.red_mask_audio.data.loop);
    m_green_mask_sound->set_looping(resources.green_mask_audio.data.loop);
    m_blue_mask_sound->set_looping(resources.blue_mask_audio.data.loop);

    m_red_mask_sound->set_volume(0.0f);
    m_green_mask_sound->set_volume(0.0f);
    m_blue_mask_sound->set_volume(0.0f);

    m_red_mask_sound->start();
    m_green_mask_sound->start();
    m_blue_mask_sound->start();

    change_mask(game->world_state()->current_mask_color());
  }

  gf::ActionGroupSettings WorldBaseScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("up"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Up).add_scancode_control(gf::Scancode::W));
    settings.actions.emplace("down"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Down).add_scancode_control(gf::Scancode::S));
    settings.actions.emplace("left"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Left).add_scancode_control(gf::Scancode::A));
    settings.actions.emplace("right"_id, gf::continuous_action().add_keycode_control(gf::Keycode::Right).add_scancode_control(gf::Scancode::D));

    settings.actions.emplace("debug_switch_mask"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Tab));

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

    if (m_action_group.active("debug_switch_mask"_id)) {
      switch (m_game->world_state()->hero.mask_color) {
        case MaskColor::Red:
          change_mask(MaskColor::Blue);
          break;
        case MaskColor::Blue:
          change_mask(MaskColor::Green);
          break;
        case MaskColor::None:
        case MaskColor::Green:
          change_mask(MaskColor::Red);
          break;
      }
    }

    m_action_group.reset();
  }

  void WorldBaseScene::do_update([[maybe_unused]] gf::Time time)
  {
    const gf::Vec2F hero_location = m_game->world_state()->hero.world_location;
    set_world_center(hero_location);

    update_entities(time);
  }

  void WorldBaseScene::change_mask(MaskColor new_mask)
  {
    switch (m_game->world_state()->hero.mask_color) {
    case MaskColor::Red:
      m_red_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
      break;
    case MaskColor::Blue:
      m_blue_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
      break;
    case MaskColor::Green:
      m_green_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
      break;

    default:
      // nothing to do
      break;
    }

    switch (new_mask) {
    case MaskColor::Red:
      m_red_mask_sound->set_volume(1.0f);
      m_red_mask_sound->set_fade(0.0f, 1.0f, MaskAudioFade);
      break;
    case MaskColor::Blue:
      m_blue_mask_sound->set_volume(1.0f);
      m_blue_mask_sound->set_fade(0.0f, 1.0f, MaskAudioFade);
      break;
    case MaskColor::Green:
      m_green_mask_sound->set_volume(1.0f);
      m_green_mask_sound->set_fade(0.0f, 1.0f, MaskAudioFade);
      break;

    default:
      // nothing to do
      break;
    }

    m_game->world_state()->hero.mask_color = new_mask;
  }

}
