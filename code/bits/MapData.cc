// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "MapData.h"

#include <cassert>

#include <algorithm>

namespace glt {

  namespace {

    WallMap create_wall_map(const gf::MapTileLayer& layer, gf::Vec2I size)
    {
      assert(layer.tiles.size() == size);
      WallMap map;

      map.cells = gf::Array2D<Cell>(size);

      for (const gf::Vec2I position : layer.tiles.position_range()) {
        map.cells(position) = layer.tiles(position).gid == 0 ? Cell::Empty : Cell::Occupied;
      }

      return map;
    }

    MaskMap create_mask_map(const gf::MapTileLayer& layer, gf::Vec2I size, MaskColor color)
    {
      assert(layer.tiles.size() == size);
      MaskMap map;

      map.color = color;
      map.name = layer.layer.name;
      map.cells = gf::Array2D<Cell>(size);

      for (const gf::Vec2I position : layer.tiles.position_range()) {
        map.cells(position) = layer.tiles(position).gid == 0 ? Cell::Empty : Cell::Occupied;
      }

      return map;
    }

  }

  MapData create_map(const gf::TiledMap* tiled)
  {
    const gf::Vec2I size = tiled->map_size;
    const gf::Vec2I tile_size = tiled->tile_size;

    MapData data = {};

    for (const gf::MapTileLayer& layer : tiled->tile_layers) {
      if (layer.layer.type == "red_walls") {
        data.red_wall_map = create_wall_map(layer, size);
      } else if (layer.layer.type == "green_walls") {
        data.green_wall_map = create_wall_map(layer, size);
      } else if (layer.layer.type == "blue_walls") {
        data.blue_wall_map = create_wall_map(layer, size);
      } else if (layer.layer.type == "red_mask") {
        data.masks.push_back(create_mask_map(layer, size, MaskColor::Red));
      } else if (layer.layer.type == "green_mask") {
        data.masks.push_back(create_mask_map(layer, size, MaskColor::Green));
      } else if (layer.layer.type == "blue_mask") {
        data.masks.push_back(create_mask_map(layer, size, MaskColor::Blue));
      }
    }

    assert(tiled->object_layers.size() == 1);

    auto to_position = [tile_size](gf::Vec2F location) {
      const gf::Vec2I position = location / tile_size;
      return position;
    };

    for (const gf::MapObject& object : tiled->object_layers.front().objects) {
      assert(object.object_type == gf::MapObjectType::Point);

      if (object.type == "start") {
        data.start = to_position(object.location);
      } else if (object.type == "goal") {
        data.goal = to_position(object.location);
      } else if (object.type == "mask") {
        auto iterator = std::ranges::find(data.masks, object.name, &MaskMap::name);
        assert(iterator != data.masks.end());
        iterator->position = to_position(object.location);
      }
    }

    return data;
  }

}
