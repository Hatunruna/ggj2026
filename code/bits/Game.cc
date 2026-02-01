// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#include "Game.h"

#include <filesystem>

#include <gf2/graphics/GamePaths.h>
#include <gf2/framework/ResourceSystem.h>

#include "config.h"

namespace glt {

  Game::Game(const std::filesystem::path& asset_directory)
  : gf::SceneSystem("Gelatine", { 1600, 900 }, asset_directory)
  , m_async(render_manager())
  {
#ifdef SDL_PLATFORM_LINUX
    resource_manager()->add_search_directory(glt::GameDataDirectory);
#endif
    resource_manager()->add_search_directory(gf::application_base_path());

    gf::ResourceBundle kickoff_bundle = m_kickoff_resources.bundle(this);
    kickoff_bundle.load_from(resource_manager());

    m_kickoff_act = std::make_unique<KickoffAct>(this, m_kickoff_resources);

    gf::BasicScene* scenes[] = { &m_kickoff_act->common_scene, &m_kickoff_act->background_scene, &m_kickoff_act->welcome_scene };
    push_scenes(scenes);
  }

  void Game::load_world(const std::filesystem::path& filename)
  {
    gf::ResourceBundle previous_bundle;

    if (m_world_act) {
      previous_bundle = m_world_resources.bundle(this);
      m_world_act.reset();
      m_world_model = {};
    }

    m_world_resources.map.filename = filename;

    using namespace std::literals;

    m_async.run_async([&,previous_bundle = std::move(previous_bundle)]() mutable {
      gf::ResourceBundle world_bundle = m_world_resources.bundle(this);
      world_bundle.load_from(resource_manager());
      previous_bundle.unload_from(resource_manager());

      m_world_model.data.load_map(m_world_resources.map, resource_manager());
      m_world_model.state.bind(m_world_model.data);

      m_world_act = std::make_unique<WorldAct>(this, m_world_resources);
    });
  }

  bool Game::world_loaded()
  {
    return m_async.finished();
  }

  void Game::start_world()
  {
    gf::BasicScene* scenes[] = { &m_world_act->common_scene, &m_world_act->base_scene };
    replace_all_scenes(scenes);
  }

}
