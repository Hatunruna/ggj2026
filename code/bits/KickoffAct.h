// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_KICKOFF_ACT_H
#define GLT_KICKOFF_ACT_H

#include "CommonBaseScene.h"
#include "KickoffLoadingScene.h"
#include "KickoffMenuScene.h"
#include "KickoffResources.h"

namespace glt {
  class Game;

  struct KickoffAct {
    KickoffAct(Game* game, const KickoffResources& resources);

    CommonBaseScene common_scene;
    KickoffMenuScene menu_scene;
    KickoffLoadingScene loading_scene;

  };

}

#endif // GLT_KICKOFF_ACT_H
