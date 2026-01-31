// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_MAP_STATE_H
#define GLT_MAP_STATE_H

#include <cstdint>

#include <gf2/core/Array2D.h>

namespace glt {
  struct MapData;

  enum class MaskState : uint8_t {
    Map,
    Inventory,
  };

  struct MapState {
    const MapData* ref = nullptr;
    std::vector<MaskState> masks;
    std::size_t current_mask = 0;

    void initialize_with(const MapData& data);
  };

}

#endif // GLT_MAP_STATE_H
