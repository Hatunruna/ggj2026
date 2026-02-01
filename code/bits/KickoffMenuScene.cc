// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffMenuScene.h"

#include "Game.h"

namespace glt {

  namespace {

    constexpr gf::Vec2F KickoffMenuSceneSize = { 1600, 900 };
    constexpr std::size_t MapCount = 5;

  }


  KickoffMenuScene::KickoffMenuScene(Game* game, const KickoffResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_atlas({ 1024, 1024 }, game->render_manager())
  , m_arrow_text(&m_atlas, resources.arrow_text, game->render_manager(), game->resource_manager())
  , m_tutorial_text(&m_atlas, resources.tutorial_text, game->render_manager(), game->resource_manager())
  , m_level01_text(&m_atlas, resources.level01_text, game->render_manager(), game->resource_manager())
  , m_level02_text(&m_atlas, resources.level02_text, game->render_manager(), game->resource_manager())
  , m_level03_text(&m_atlas, resources.level03_text, game->render_manager(), game->resource_manager())
  , m_level04_text(&m_atlas, resources.level04_text, game->render_manager(), game->resource_manager())
  {
    set_world_size(KickoffMenuSceneSize);
    set_world_center(KickoffMenuSceneSize / 2.0f);

    m_arrow_text.set_origin({ 1.0f, 0.5f });
    add_world_entity(&m_arrow_text);

    m_tutorial_text.set_origin({ 0.0f, 0.5f });
    m_tutorial_text.set_location(KickoffMenuSceneSize * gf::vec(0.4, 0.3));
    add_world_entity(&m_tutorial_text);

    m_level01_text.set_origin({ 0.0f, 0.5f });
    m_level01_text.set_location(KickoffMenuSceneSize * gf::vec(0.4, 0.4));
    add_world_entity(&m_level01_text);

    m_level02_text.set_origin({ 0.0f, 0.5f });
    m_level02_text.set_location(KickoffMenuSceneSize * gf::vec(0.4, 0.5));
    add_world_entity(&m_level02_text);

    m_level03_text.set_origin({ 0.0f, 0.5f });
    m_level03_text.set_location(KickoffMenuSceneSize * gf::vec(0.4, 0.6));
    add_world_entity(&m_level03_text);

    m_level04_text.set_origin({ 0.0f, 0.5f });
    m_level04_text.set_location(KickoffMenuSceneSize * gf::vec(0.4, 0.7));
    add_world_entity(&m_level04_text);

    compute_arrow_position();

    // m_main_title_text.set_location(KickoffMenuSceneSize / 2.0f);
    // m_main_title_text.set_origin({ 0.5f, 0.5f });
    // add_world_entity(&m_main_title_text);
  }

  gf::ActionGroupSettings KickoffMenuScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("next"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Down));
    settings.actions.emplace("prev"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Up));
    settings.actions.emplace("go"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Space));

    return settings;
  }

  void KickoffMenuScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void KickoffMenuScene::do_handle_actions()
  {
    const std::filesystem::path paths[] = {
      "map/tutorial.tmx",
      "map/level01.tmx",
      "map/level02.tmx",
      "map/level03.tmx",
      "map/level04.tmx",
    };

    static_assert(std::size(paths) == MapCount);

    using namespace gf::literals;

    if (m_action_group.active("next"_id)) {
      m_current_map = (m_current_map + 1) % MapCount;
      compute_arrow_position();
    }

    if (m_action_group.active("prev"_id)) {
      m_current_map = (m_current_map + MapCount - 1) % MapCount;
      compute_arrow_position();
    }

    if (m_action_group.active("go"_id)) {
       m_game->load_world(paths[m_current_map]);
       m_game->replace_scene(&m_game->kickoff_act()->loading_scene);
    }

    m_action_group.reset();
  }

  void KickoffMenuScene::compute_arrow_position()
  {
    m_arrow_text.set_location(KickoffMenuSceneSize * gf::vec(0.35f, 0.3f + (0.1f * static_cast<float>(m_current_map))));
  }


}
