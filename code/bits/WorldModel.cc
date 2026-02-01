// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldModel.h"

#include <gf2/core/Range.h>

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

      state.hero.running = state.hero.tile_location != state.hero.tile_target;
      return;
    }

    state.hero.running = false;
    state.hero.tile_location = state.hero.tile_target;
    state.hero.world_location = state.hero.tile_location * TileSize;

    if (state.hero.expected_direction != gf::Direction::Center) {
      const gf::Vec2I displacement = gf::displacement(state.hero.expected_direction);
      const gf::Vec2I target = state.hero.tile_location + displacement;

      if (state.reachable(target)) {
        state.hero.direction = state.hero.expected_direction;
        state.hero.tile_target = target;;
        state.hero.move_cooldown = gf::Time();
        state.hero.running = true;
      }
    }

    // check masks

    for (auto [ index, mask_state ] : gf::enumerate(state.map.masks)) {
      if (mask_state == MaskState::Inventory) {
        continue;
      }

      const gf::Vec2I position = state.map.ref->masks[index].position.value();

      if (position == state.hero.tile_location) {
        mask_state = MaskState::Inventory;
      }
    }

    // check end

    if (state.hero.tile_location == state.map.ref->goal) {
      state.hero.status = HeroStatus::End; // TODO: change when finish animation available
    }

  }

}
