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

    if (state.hero.tile_location == state.hero.tile_target) {
      state.hero.world_location = state.hero.tile_location * TileSize;
      return;
    }

    if (state.hero.move_cooldown > HeroMoveCooldown) {
      state.hero.tile_location = state.hero.tile_target;
      state.hero.world_location = state.hero.tile_location * TileSize;
    } else {
      state.hero.world_location = gf::lerp(
        state.hero.tile_location * TileSize,
        state.hero.tile_target * TileSize,
        state.hero.move_cooldown.as_seconds() / HeroMoveCooldown.as_seconds()
      );
    }
  }

}
