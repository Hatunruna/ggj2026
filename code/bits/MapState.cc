// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "MapState.h"


#include "MapData.h"

namespace glt {

  void MapState::initialize_with(const MapData& data)
  {
    ref = &data;
    masks.clear();
    masks.resize(data.masks.size());
    current_mask = data.masks.size();

    for (auto [ index, mask ] : gf::enumerate(data.masks)) {
      if (mask.position) {
        masks[index] = MaskState::Map;
      } else {
        masks[index] = MaskState::Inventory;

        if (current_mask == data.masks.size()) {
          current_mask = index;
        }
      }
    }

    assert(current_mask != data.masks.size());
  }

  bool MapState::reachable(gf::Vec2I position) const
  {
    const MaskMap& mask = ref->masks[current_mask];

    if (!mask.cells.valid(position)) {
      return false;
    };

    const MaskColor color = mask.color;

    switch (color) {
      case MaskColor::None:
        return false;
      case MaskColor::Red:
        return mask.cells(position) == Cell::Empty && ref->green_wall_map.cells(position) == Cell::Empty && ref->blue_wall_map.cells(position) == Cell::Empty;
      case MaskColor::Green:
        return mask.cells(position) == Cell::Empty && ref->red_wall_map.cells(position) == Cell::Empty && ref->blue_wall_map.cells(position) == Cell::Empty;
      case MaskColor::Blue:
        return mask.cells(position) == Cell::Empty && ref->red_wall_map.cells(position) == Cell::Empty && ref->green_wall_map.cells(position) == Cell::Empty;
    }

    return false;
  }

}
