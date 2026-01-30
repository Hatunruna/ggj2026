// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldBaseScene.h"

#include <gf2/core/Color.h>
#include <gf2/core/Keycode.h>
#include <gf2/core/Log.h>
#include <gf2/core/Scancode.h>

#include "Constants.h"
#include "Game.h"

namespace gft {
  WorldBaseScene::WorldBaseScene(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_hero(resources.hero_shape, game->render_manager(), game->resource_manager())
  {
    set_clear_color(gf::White);

    set_window_size(TileSize * 10);
    set_world_center(TileSize * 5);

    m_hero.set_location(TileSize * 5);
    add_world_entity(&m_hero);
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
      m_game->world_model()->state.hero_location.y -= TileSize.h;
    }

    m_action_group.reset();
  }

}
