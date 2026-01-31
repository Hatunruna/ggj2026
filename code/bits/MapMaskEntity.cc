// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "MapMaskEntity.h"

#include <gf2/graphics/RenderRecorder.h>

#include "Game.h"

namespace glt {

  MapMaskEntity::MapMaskEntity(Game* game, const gf::TiledMapResource& resource)
  : m_game(game)
  , m_graphics(resource, game->render_manager(), game->resource_manager())
  {
    const gf::TiledMap* tiled = game->resource_manager()->get<gf::TiledMap>(resource.filename);

    auto compute_geometry = [&](const gf::MapLayerStructure layer_structure) {
      std::vector<gf::RenderGeometry> geometries = m_graphics.select_geometry({ &layer_structure, 1 });
      assert(geometries.size() == 1);
      return geometries.front();
    };

    for (const gf::MapLayerStructure layer_structure : tiled->layers) {
      if (layer_structure.type != gf::MapLayerType::Tile) {
        continue;
      }

      const gf::MapTileLayer& layer = tiled->tile_layers[layer_structure.layer_index];

      if (layer.layer.type == "red_mask" || layer.layer.type == "green_mask" || layer.layer.type == "blue_mask") {
        m_masks.push_back(compute_geometry(layer_structure));
      }
    }
  }

  void MapMaskEntity::render(gf::RenderRecorder& recorder)
  {
    gf::RenderObject object = {};
    object.priority = priority();
    object.transform = gf::Identity3F;

    const std::size_t index = m_game->world_state()->map.current_mask;
    assert(index < m_masks.size());
    object.geometry = m_masks[index];

    recorder.record(object);
  }

}
