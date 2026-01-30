// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_WORLD_BASE_SCENE_H
#define GFT_WORLD_BASE_SCENE_H

#include <gf2/graphics/Scene.h>

#include "WorldResources.h"

namespace gft {
  class Game;

  class WorldBaseScene : public gf::Scene {
  public:
    WorldBaseScene(Game* game, const WorldResources& resources);


  private:

  };

}

#endif // GFT_WORLD_BASE_SCENE_H
