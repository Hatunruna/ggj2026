// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldModel.h"

#include "Constants.h"

namespace glt {

  void WorldModel::update(gf::Time time)
  {
    hero_move(time);
  }

  void WorldModel::hero_move(gf::Time time)
  {
    state.hero.move_cooldown += time;

    if (state.hero.location == state.hero.target) {
      state.hero.middle = state.hero.location * TileSize;
      return;
    }

    if (state.hero.move_cooldown > HeroMoveCooldown) {
      state.hero.location = state.hero.target;
      state.hero.middle = state.hero.location * TileSize;
    } else {
      state.hero.middle = gf::lerp(
        state.hero.location * TileSize,
        state.hero.target * TileSize,
        state.hero.move_cooldown.as_seconds() / HeroMoveCooldown.as_seconds()
      );
    }
  }

}
