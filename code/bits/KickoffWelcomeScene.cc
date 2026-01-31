// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffWelcomeScene.h"

#include "Game.h"

namespace glt {

  namespace {

    constexpr gf::Vec2F KickoffWelcomeSceneSize = { 1600, 900 };

  }


  KickoffWelcomeScene::KickoffWelcomeScene(Game* game, const KickoffResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_atlas({ 1024, 1024 }, game->render_manager())
  , m_main_title_text(&m_atlas, resources.main_title_text, game->render_manager(), game->resource_manager())
  {
    set_world_size(KickoffWelcomeSceneSize);
    set_world_center(KickoffWelcomeSceneSize / 2.0f);

    m_main_title_text.set_location(KickoffWelcomeSceneSize / 2.0f);
    m_main_title_text.set_origin({ 0.5f, 0.5f });
    add_world_entity(&m_main_title_text);
  }

  gf::ActionGroupSettings KickoffWelcomeScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("menu"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Space));

    return settings;
  }

  void KickoffWelcomeScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void KickoffWelcomeScene::do_handle_actions()
  {
    using namespace gf::literals;

    if (m_action_group.active("menu"_id)) {
       m_game->replace_scene(&m_game->kickoff_act()->menu_scene);
    }

    m_action_group.reset();
  }

}
