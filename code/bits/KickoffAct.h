// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_KICKOFF_ACT_H
#define GFT_KICKOFF_ACT_H

#include "KickoffLoadingScene.h"
#include "KickoffMenuScene.h"
#include "KickoffResources.h"

namespace gft {
  class Game;

  struct KickoffAct {
    KickoffAct(Game* game, const KickoffResources& resources);

    KickoffMenuScene menu_scene;
    KickoffLoadingScene loading_scene;

  };

}

#endif // GFT_KICKOFF_ACT_H
