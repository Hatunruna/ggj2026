// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#include "KickoffBackgroundScene.h"

#include <gf2/core/Vec2.h>

#include "Game.h"
#include "KickoffResources.h"

namespace glt {

  namespace {
    constexpr gf::Vec2F BackgroundSize = {3840, 2160};
    constexpr gf::Vec2F KickoffBackgroundSceneSize = { 1600, 900 };
  }

  KickoffBackgroundScene::KickoffBackgroundScene(Game* game, const KickoffResources& resources)
  : m_background(resources.background, game->render_manager(), game->resource_manager())
  {
    set_world_size(KickoffBackgroundSceneSize);
    set_world_center(KickoffBackgroundSceneSize / 2.0f);

    m_background.set_location(KickoffBackgroundSceneSize / 2.0f);
    m_background.set_origin({ 0.5f, 0.5f });
    m_background.set_scale(KickoffBackgroundSceneSize / BackgroundSize);

    add_world_entity(&m_background);
  }

}
