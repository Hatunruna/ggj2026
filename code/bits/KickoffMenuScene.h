// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_KICKOFF_MENU_SCENE_H
#define GLT_KICKOFF_MENU_SCENE_H

#include <gf2/graphics/Scene.h>

#include <gf2/core/ActionGroup.h>
#include <gf2/graphics/TextEntity.h>
#include <gf2/graphics/FontAtlas.h>

#include "KickoffResources.h"

namespace glt {
  class Game;

  class KickoffMenuScene : public gf::Scene {
  public:
    KickoffMenuScene(Game* game, const KickoffResources& resources);

  private:
    static gf::ActionGroupSettings compute_settings();

    void do_process_event(const gf::Event& event) override;
    void do_handle_actions() override;
    void compute_arrow_position();

    Game* m_game;

    gf::ActionGroup m_action_group;

    gf::FontAtlas m_atlas;

    std::size_t m_current_map = 0;

    gf::TextEntity m_arrow_text;
    gf::TextEntity m_tutorial_text;
    gf::TextEntity m_level01_text;
    gf::TextEntity m_level02_text;
    gf::TextEntity m_level03_text;
  };

}

#endif // GLT_KICKOFF_MENU_SCENE_H
