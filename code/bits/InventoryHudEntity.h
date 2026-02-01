// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_INVENTORY_ACT_H
#define GLT_INVENTORY_ACT_H

#include <cstddef>

#include <gf2/core/Vec2.h>

#include <gf2/graphics/Entity.h>
#include <gf2/graphics/ShapeEntity.h>
#include <gf2/graphics/SpriteEntity.h>

namespace glt {

  class Game;
  struct WorldResources;

  class InventoryHudEntity : public gf::HudEntity {
  public:
    InventoryHudEntity(Game* game, const WorldResources& resources);

    void render(gf::RenderRecorder& recorder) override;
    void resize(gf::Vec2I surface_size) override;

  private:
    static gf::ShapeGroupBuffer compute_boxes(Game* game, const gf::Vec2F& screen_size);
    static gf::Vec2F compute_relative_mask_center(std::size_t index, std::size_t mask_count);

    Game* m_game = nullptr;

    gf::ShapeGroupEntity m_shapes;

    gf::SpriteEntity m_red_mask;
    gf::SpriteEntity m_red_mask_shaded;
    gf::SpriteEntity m_green_mask;
    gf::SpriteEntity m_green_mask_shaded;
    gf::SpriteEntity m_blue_mask;
    gf::SpriteEntity m_blue_mask_shaded;
    gf::SpriteEntity m_placeholder_mask;
  };

}

#endif // GLT_INVENTORY_ACT_H
