// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_MAP_GROUND_ENTITY_H
#define GLT_MAP_GROUND_ENTITY_H

#include <gf2/core/TiledMapResource.h>
#include <gf2/graphics/Entity.h>
#include <gf2/graphics/TiledMapGraphics.h>

#include "WorldResources.h"

namespace glt {
  class Game;

  class MapGroundEntity : public gf::Entity {
  public:
    MapGroundEntity(Game* game, const gf::TiledMapResource& resource);

    void render(gf::RenderRecorder& recorder) override;

  private:
    Game* m_game = nullptr;
    gf::TiledMapGraphics m_graphics;
    gf::RenderGeometry m_background;
    gf::RenderGeometry m_red_walls;
    gf::RenderGeometry m_green_walls;
    gf::RenderGeometry m_blue_walls;
    std::map<std::string, gf::RenderGeometry> m_masks;
  };

}

#endif // GLT_MAP_GROUND_ENTITY_H
