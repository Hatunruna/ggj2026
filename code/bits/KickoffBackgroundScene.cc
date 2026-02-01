// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#include "KickoffBackgroundScene.h"

#include <gf2/core/Vec2.h>

#include "Game.h"
#include "KickoffResources.h"

namespace glt {

  namespace {
    constexpr gf::Vec2F BackgroundSize = {3840, 2160};
    constexpr gf::Vec2F KickoffMenuSceneSize = { 1600, 900 };
  }

  KickoffBackgroundScene::KickoffBackgroundScene(Game* game, const KickoffResources& resources)
  : m_background(resources.background, game->render_manager(), game->resource_manager())
  {
    // m_background.set_scale(KickoffMenuSceneSize / BackgroundSize);

    add_world_entity(&m_background);
  }

}
