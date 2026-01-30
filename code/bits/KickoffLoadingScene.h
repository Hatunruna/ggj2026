// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_KICKOFF_LOADING_SCENE_H
#define GFT_KICKOFF_LOADING_SCENE_H

#include <gf2/graphics/Scene.h>

#include <gf2/graphics/TextEntity.h>
#include <gf2/graphics/FontAtlas.h>

#include "KickoffResources.h"

namespace gft {
  class Game;

  class KickoffLoadingScene : public gf::Scene {
  public:
    KickoffLoadingScene(Game* game, const KickoffResources& resources);

  private:
    void do_update(gf::Time time) override;

    Game* m_game;

    gf::FontAtlas m_atlas;

    gf::TextEntity m_loading_text;
  };

}

#endif // GFT_KICKOFF_LOADING_SCENE_H
