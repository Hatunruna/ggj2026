// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffMenuScene.h"

#include "Game.h"

namespace glt {

  namespace {

    constexpr gf::Vec2F KickoffMenuSceneSize = { 1600, 900 };

  }


  KickoffMenuScene::KickoffMenuScene(Game* game, const KickoffResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_atlas({ 1024, 1024 }, game->render_manager())
  , m_main_title_text(&m_atlas, resources.main_title_text, game->render_manager(), game->resource_manager())
  {
    set_world_size(KickoffMenuSceneSize);
    set_world_center(KickoffMenuSceneSize / 2.0f);

    m_main_title_text.set_location(KickoffMenuSceneSize / 2.0f);
    m_main_title_text.set_origin({ 0.5f, 0.5f });
    add_world_entity(&m_main_title_text);
  }

  gf::ActionGroupSettings KickoffMenuScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("start"_id, gf::instantaneous_action().add_keycode_control(gf::Keycode::Space));

    return settings;
  }

  void KickoffMenuScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void KickoffMenuScene::do_handle_actions()
  {
    using namespace gf::literals;

    if (m_action_group.active("start"_id)) {
       m_game->load_world();
       m_game->replace_scene(&m_game->kickoff_act()->loading_scene);
    }

    m_action_group.reset();
  }

}
