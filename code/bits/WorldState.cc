// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldState.h"

#include <gf2/core/Log.h>

#include "Constants.h"
#include "WorldData.h"

namespace glt {

  void WorldState::bind(const WorldData& data)
  {
    map.initialize_with(data.maps.front());
  }

  void WorldState::process_hero_move(gf::Direction direction)
  {
    if (direction == gf::Direction::Center) {
      hero.running = hero.move_cooldown < HeroMoveCooldown;
      return;
    }
    hero.running = true;

    if (hero.move_cooldown < HeroMoveCooldown) {
      return;
    }

    hero.direction = direction;

    gf::Vec2I next_location = hero.tile_location + gf::displacement(direction);

    if (hero.tile_location == next_location) {
      return;
    }

    hero.tile_target = next_location;
    hero.move_cooldown = gf::seconds(0);
  }

  MaskColor WorldState::current_mask_color() const
  {
    return map.ref->masks[map.current_mask].color;
  }

}
