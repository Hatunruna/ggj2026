// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldBaseScene.h"

#include <gf2/core/Color.h>

#include "Game.h"

namespace gft {

  WorldBaseScene::WorldBaseScene(Game* game, const WorldResources& resources)
  {
    set_clear_color(gf::White);
  }

}
