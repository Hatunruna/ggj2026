// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldAct.h"

namespace glt {

  WorldAct::WorldAct(Game* game, const WorldResources& resources)
  : common_scene(game)
  , base_scene(game, resources)
  , finish_scene(game, resources)
  {
  }

}
