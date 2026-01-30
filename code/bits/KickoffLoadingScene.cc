// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffLoadingScene.h"

#include <gf2/core/Color.h>

#include "Game.h"

namespace gft {

  namespace {

    constexpr gf::Vec2F KickoffLoadingSceneSize = { 1600, 900 };

  }

  KickoffLoadingScene::KickoffLoadingScene(Game* game, const KickoffResources& resources)
  : m_game(game)
  , m_atlas({ 1024, 1024 }, game->render_manager())
  , m_loading_text(&m_atlas, resources.loading_text, game->render_manager(), game->resource_manager())
  {
    set_world_size(KickoffLoadingSceneSize);
    set_world_center(KickoffLoadingSceneSize / 2.0f);

    m_loading_text.set_location(KickoffLoadingSceneSize / 2.0f);
    m_loading_text.set_origin({ 0.5f, 0.5f });
    add_world_entity(&m_loading_text);
  }

  void KickoffLoadingScene::do_update([[maybe_unused]] gf::Time time)
  {
    if (m_game->world_loaded()) {
      m_game->start_world();
    }
  }

}
