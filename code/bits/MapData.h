// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_MAP_DATA_H
#define GLT_MAP_DATA_H

#include <cstdint>

#include <optional>

#include <gf2/core/Array2D.h>
#include <gf2/core/TiledMap.h>

#include "MaskColor.h"

namespace glt {

  enum class Cell : uint8_t {
    Empty,
    Occupied,
  };

  struct WallMap {
    gf::Array2D<Cell> cells;
  };

  struct MaskMap {
    MaskColor color = MaskColor::None;
    std::string name;
    std::optional<gf::Vec2I> position;
    gf::Array2D<Cell> cells;
  };

  struct MapData {
    WallMap red_wall_map;
    WallMap green_wall_map;
    WallMap blue_wall_map;
    std::vector<MaskMap> masks;

    gf::Vec2I start;
    gf::Vec2I goal;
  };

  MapData create_map(const gf::TiledMap* tiled);

}

#endif // GLT_MAP_DATA_H
