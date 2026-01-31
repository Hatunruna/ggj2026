// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "MapGroundEntity.h"

#include <gf2/graphics/RenderRecorder.h>

#include "Game.h"

namespace glt {

  MapGroundEntity::MapGroundEntity(Game* game, const gf::TiledMapResource& resource)
  : m_graphics(resource, game->render_manager(), game->resource_manager())
  {
    // TODO: compute ground geometries (background and walls)
  }

  void MapGroundEntity::render(gf::RenderRecorder& recorder)
  {
    gf::RenderObject object = {};
    object.priority = priority();
    object.transform = gf::Identity3F;

    object.geometry = m_background;
    recorder.record(object);

    // TODO: display walls according to current mask
  }

}
