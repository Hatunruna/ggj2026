// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldModel.h"

#include "Constants.h"

namespace glt {

  void WorldModel::update(gf::Time time)
  {
    update_hero(time);
  }

  void WorldModel::update_hero(gf::Time time)
  {
    state.hero.move_cooldown += time;

    if (state.hero.move_cooldown < HeroMoveCooldown) {
      state.hero.world_location = gf::lerp(
        state.hero.tile_location * TileSize,
        state.hero.tile_target * TileSize,
        state.hero.move_cooldown.as_seconds() / HeroMoveCooldown.as_seconds()
      );

      state.hero.running = true;
      return;
    }

    state.hero.running = false;
    state.hero.tile_location = state.hero.tile_target;
    state.hero.world_location = state.hero.tile_location * TileSize;

    if (state.hero.expected_direction != gf::Direction::Center) {
      state.hero.direction = state.hero.expected_direction;
      state.hero.tile_target = state.hero.tile_location + gf::displacement(state.hero.direction);;
      state.hero.move_cooldown = gf::Time();
      state.hero.running = true;
    }
  }

}
