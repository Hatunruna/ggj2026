// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_STATE_H
#define GLT_WORLD_STATE_H

#include <gf2/core/Direction.h>
#include <gf2/core/Time.h>
#include <gf2/core/Vec2.h>

namespace glt {
  struct WorldData;

  struct HeroState {
    gf::Vec2I location = { 0, 0 };
    gf::Vec2I target = { 0, 0 };
    gf::Vec2F middle = {0.0f, 0.0f};
    gf::Direction direction = gf::Direction::Center;
    gf::Time move_cooldown;
  };

  struct WorldState {

    void bind(const WorldData& data);

    void process_hero_move(gf::Direction direction);

    HeroState hero;
  };

}

#endif // GLT_WORLD_STATE_H
