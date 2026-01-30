// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#include "Game.h"

#include <filesystem>

#include <gf2/graphics/GamePaths.h>

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

    push_scene(&m_kickoff_act->menu_scene);
  }

  void Game::load_world()
  {
    using namespace std::literals;

    m_async.run_async([&]() {
      m_world_model.state.bind(m_world_model.data);

      gf::ResourceBundle world_bundle = m_world_resources.bundle(this);
      world_bundle.load_from(resource_manager());

      m_world_act = std::make_unique<WorldAct>(this, m_world_resources);
    });
  }

  bool Game::world_loaded()
  {
    return m_async.finished();
  }

  void Game::start_world()
  {
    replace_all_scenes(&m_world_act->base_scene);
  }

}
