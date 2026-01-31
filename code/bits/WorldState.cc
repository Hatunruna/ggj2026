// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldState.h"

#include <gf2/core/Log.h>

#include "Constants.h"

namespace glt {

  void WorldState::bind(const WorldData& data)
  {

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

    gf::Vec2I next_location = hero.location + gf::displacement(direction);

    if (hero.location == next_location) {
      return;
    }

    hero.target = next_location;
    hero.move_cooldown = gf::seconds(0);
  }

}
