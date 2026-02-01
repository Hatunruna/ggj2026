// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldState.h"

#include <cassert>

#include <gf2/core/Log.h>

#include "WorldData.h"

namespace glt {

  namespace {

    bool is_mask_compatible_with_position(const MapData* data, const MaskMap& mask, gf::Vec2I position)
    {
      if (!mask.cells.valid(position)) {
        return false;
      };

      const MaskColor color = mask.color;

      switch (color) {
        case MaskColor::None:
          return false;
        case MaskColor::Red:
          return mask.cells(position) == Cell::Empty && data->green_wall_map.cells(position) == Cell::Empty && data->blue_wall_map.cells(position) == Cell::Empty;
        case MaskColor::Green:
          return mask.cells(position) == Cell::Empty && data->red_wall_map.cells(position) == Cell::Empty && data->blue_wall_map.cells(position) == Cell::Empty;
        case MaskColor::Blue:
          return mask.cells(position) == Cell::Empty && data->red_wall_map.cells(position) == Cell::Empty && data->green_wall_map.cells(position) == Cell::Empty;
      }

      return false;
    }

  }

  void WorldState::bind(const WorldData& data)
  {
    map.initialize_with(data.map);
  }

  MaskColor WorldState::current_mask_color() const
  {
    return map.ref->masks[map.current_mask].color;
  }

  bool WorldState::reachable(gf::Vec2I position) const
  {
    const MaskMap& mask = map.ref->masks[map.current_mask];
    return is_mask_compatible_with_position(map.ref, mask, position);
  }

  std::size_t WorldState::mask_count() const
  {
    return map.ref->masks.size();
  }

  bool WorldState::is_mask_collected(std::size_t index) const
  {
    assert(index < map.masks.size());
    return map.masks[index] == MaskState::Inventory;
  }

  bool WorldState::is_mask_available(std::size_t index) const
  {
    assert(index < map.masks.size());
    const MaskMap& mask = map.ref->masks[index];
    const gf::Vec2I position = hero.tile_location;
    return is_mask_collected(index) && is_mask_compatible_with_position(map.ref, mask, position);
  }

  bool WorldState::is_mask_current(std::size_t index) const
  {
    return index == map.current_mask;
  }

  MaskColor WorldState::mask_color(std::size_t index) const
  {
    assert(map.ref != nullptr);
    assert(index < map.ref->masks.size());
    return map.ref->masks[index].color;
  }

}
