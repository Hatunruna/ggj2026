// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldState.h"

#include <gf2/core/Log.h>

#include "WorldData.h"

namespace glt {

  void WorldState::bind(const WorldData& data)
  {
    map.initialize_with(data.maps.front());
  }

  MaskColor WorldState::current_mask_color() const
  {
    return map.ref->masks[map.current_mask].color;
  }

}
