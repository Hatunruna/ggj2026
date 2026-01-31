// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_MAP_MASK_ENTITY_H
#define GLT_MAP_MASK_ENTITY_H

#include <gf2/core/TiledMapResource.h>
#include <gf2/graphics/Entity.h>
#include <gf2/graphics/TiledMapGraphics.h>

#include "WorldResources.h"

namespace glt {
  class Game;

  class MapMaskEntity : public gf::Entity {
  public:
    MapMaskEntity(Game* game, const gf::TiledMapResource& resource);

    void render(gf::RenderRecorder& recorder) override;

  private:
    gf::TiledMapGraphics m_graphics;
    std::map<std::string, gf::RenderGeometry> m_masks;
  };

}

#endif // GLT_MAP_MASK_ENTITY_H
