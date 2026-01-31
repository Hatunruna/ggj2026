// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_ACT_H
#define GLT_WORLD_ACT_H

#include "CommonBaseScene.h"
#include "WorldBaseScene.h"
#include "WorldResources.h"

namespace glt {
  class Game;

  struct WorldAct {
    WorldAct(Game* game, const WorldResources& resources);

    CommonBaseScene common_scene;
    WorldBaseScene base_scene;

  };

}

#endif // GLT_WORLD_ACT_H
