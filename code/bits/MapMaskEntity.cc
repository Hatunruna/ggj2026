// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "MapMaskEntity.h"

#include <gf2/graphics/RenderRecorder.h>

#include "Game.h"

namespace glt {

  MapMaskEntity::MapMaskEntity(Game* game, const gf::TiledMapResource& resource)
  : m_graphics(resource, game->render_manager(), game->resource_manager())
  {
    // TODO: compute mask geometries
  }

  void MapMaskEntity::render(gf::RenderRecorder& recorder)
  {
    gf::RenderObject object = {};
    object.priority = priority();
    object.transform = gf::Identity3F;

    // TODO: display current mask
    // object.geometry = ;

    recorder.record(object);
  }

}
