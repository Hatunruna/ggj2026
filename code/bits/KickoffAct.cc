// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffAct.h"

namespace glt {

  KickoffAct::KickoffAct(Game* game, const KickoffResources& resources)
  : common_scene(game)
  , menu_scene(game, resources)
  , loading_scene(game, resources)
  {
  }

}
