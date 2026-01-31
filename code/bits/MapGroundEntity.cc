// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "MapGroundEntity.h"

#include <cassert>

#include <gf2/core/TiledMap.h>
#include <gf2/graphics/RenderRecorder.h>

#include "Game.h"

namespace glt {

  MapGroundEntity::MapGroundEntity(Game* game, const gf::TiledMapResource& resource)
  : m_game(game)
  , m_graphics(resource, game->render_manager(), game->resource_manager())
  {
    const gf::TiledMap* tiled = game->resource_manager()->get<gf::TiledMap>(resource.filename);

    auto compute_geometry = [&](const gf::MapLayerStructure layer_structure) -> gf::RenderGeometry {
      std::vector<gf::RenderGeometry> geometries = m_graphics.select_geometry({ &layer_structure, 1 });

      if (geometries.empty()) {
        return {};
      }

      assert(geometries.size() == 1);
      return geometries.front();
    };

    for (const gf::MapLayerStructure layer_structure : tiled->layers) {
      if (layer_structure.type != gf::MapLayerType::Tile) {
        continue;
      }

      const gf::MapTileLayer& layer = tiled->tile_layers[layer_structure.layer_index];

      if (layer.layer.type == "red_walls") {
        m_red_walls = compute_geometry(layer_structure);
      } else if (layer.layer.type == "green_walls") {
        m_green_walls = compute_geometry(layer_structure);
      } else if (layer.layer.type == "blue_walls") {
        m_blue_walls = compute_geometry(layer_structure);
      } else if (layer.layer.type == "ground") {
        m_background = compute_geometry(layer_structure);
      }
    }
  }

  void MapGroundEntity::render(gf::RenderRecorder& recorder)
  {
    gf::RenderObject object = {};
    object.priority = priority();
    object.transform = gf::Identity3F;

    object.geometry = m_background;
    recorder.record(object);

    const MaskColor color = m_game->world_state()->current_mask_color();

    if (color != MaskColor::Red) {
      object.geometry = m_red_walls;
      recorder.record(object);
    }

    if (color != MaskColor::Green) {
      object.geometry = m_green_walls;
      recorder.record(object);
    }

    if (color != MaskColor::Blue) {
      object.geometry = m_blue_walls;
      recorder.record(object);
    }
  }

}
