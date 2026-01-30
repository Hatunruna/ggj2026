// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_WORLD_STATE_H
#define GFT_WORLD_STATE_H

namespace gft {
  struct WorldData;

  struct WorldState {

    void bind(const WorldData& data);
  };

}

#endif // GFT_WORLD_STATE_H
