// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_STATE_H
#define GLT_WORLD_STATE_H

#include <gf2/core/Vec2.h>

namespace glt {
  struct WorldData;

  struct WorldState {

    void bind(const WorldData& data);

    gf::Vec2F hero_location = {0.0f, 0.0f};
  };

}

#endif // GLT_WORLD_STATE_H
