// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffAct.h"

namespace gft {

  KickoffAct::KickoffAct(Game* game, const KickoffResources& resources)
  : menu_scene(game, resources)
  , loading_scene(game, resources)
  {
  }

}
