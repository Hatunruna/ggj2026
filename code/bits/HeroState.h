// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_HERO_STATE_H
#define GLT_HERO_STATE_H

#include <gf2/core/Direction.h>
#include <gf2/core/Time.h>
#include <gf2/core/Vec2.h>

#include "MaskColor.h"

namespace glt {

  struct HeroState {
    gf::Vec2I tile_location = { 0, 0 };
    gf::Vec2I tile_target = { 0, 0 };
    gf::Vec2F world_location = {0.0f, 0.0f};
    bool running = false;
    gf::Direction direction = gf::Direction::Center;
    gf::Direction expected_direction = gf::Direction::Center;
    gf::Time move_cooldown;

    MaskColor mask_color = MaskColor::None;
  };

};

#endif // GLT_HERO_STATE_H
