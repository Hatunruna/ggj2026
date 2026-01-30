// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_WORLD_ACT_H
#define GFT_WORLD_ACT_H

#include "WorldBaseScene.h"
#include "WorldResources.h"

namespace gft {
  class Game;

  struct WorldAct {
    WorldAct(Game* game, const WorldResources& resources);

    WorldBaseScene base_scene;

  };

}

#endif // GFT_WORLD_ACT_H
