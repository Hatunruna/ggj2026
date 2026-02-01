// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_KICKOFF_BACKGROUND_SCENE_H
#define GLT_KICKOFF_BACKGROUND_SCENE_H

#include <gf2/graphics/Scene.h>
#include <gf2/graphics/SpriteEntity.h>

namespace glt {

  struct KickoffResources;
  struct Game;

  class KickoffBackgroundScene : public gf::Scene {
  public:
    KickoffBackgroundScene(Game* game, const KickoffResources& resources);

  private:
    gf::SpriteEntity m_background;
  };

}

#endif // GLT_KICKOFF_BACKGROUND_SCENE_H
