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

}
