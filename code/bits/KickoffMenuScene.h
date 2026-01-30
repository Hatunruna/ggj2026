// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_KICKOFF_MENU_SCENE_H
#define GFT_KICKOFF_MENU_SCENE_H

#include <gf2/graphics/Scene.h>

#include <gf2/core/ActionGroup.h>
#include <gf2/graphics/TextEntity.h>
#include <gf2/graphics/FontAtlas.h>

#include "KickoffResources.h"

namespace gft {
  class Game;

  class KickoffMenuScene : public gf::Scene {
  public:
    KickoffMenuScene(Game* game, const KickoffResources& resources);

  private:
    static gf::ActionGroupSettings compute_settings();

    void do_process_event(const gf::Event& event) override;
    void do_handle_actions() override;

    Game* m_game;

    gf::ActionGroup m_action_group;

    gf::FontAtlas m_atlas;

    gf::TextEntity m_main_title_text;
  };

}

#endif // GFT_KICKOFF_MENU_SCENE_H
