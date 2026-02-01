// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_FINISH_SCENE_H
#define GLT_WORLD_FINISH_SCENE_H

#include <gf2/graphics/Scene.h>
#include <gf2/graphics/TextEntity.h>

#include "WorldResources.h"

namespace glt {
  class Game;

  class WorldFinishScene : public gf::Scene {
  public:
    WorldFinishScene(Game* game, const WorldResources& resources);

  private:
    gf::FontAtlas m_atlas;
    gf::TextEntity m_finish_text;
  };

}


#endif // GLT_WORLD_FINISH_SCENE_H
