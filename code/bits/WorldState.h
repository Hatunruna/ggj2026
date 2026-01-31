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

    void process_hero_move(gf::Direction direction);
    MaskColor current_mask_color() const;

    MapState map;
    HeroState hero;
  };

}

#endif // GLT_WORLD_STATE_H
