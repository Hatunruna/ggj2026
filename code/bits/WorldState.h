// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_STATE_H
#define GLT_WORLD_STATE_H

#include "HeroState.h"
#include "MapState.h"
#include "MaskColor.h"

namespace glt {
  struct WorldData;

  struct WorldState {
    void bind(const WorldData& data);

    MaskColor current_mask_color() const;

    bool reachable(gf::Vec2I position) const;

    std::size_t mask_count() const;
    bool is_mask_collected(std::size_t index) const;
    bool is_mask_available(std::size_t index) const;
    bool is_mask_current(std::size_t index) const;

    MapState map;
    HeroState hero;
  };

}

#endif // GLT_WORLD_STATE_H
