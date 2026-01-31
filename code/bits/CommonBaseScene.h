// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_COMMON_BASE_SCENE_H
#define GLT_COMMON_BASE_SCENE_H

#include <gf2/graphics/Scene.h>

#include <gf2/core/ActionGroup.h>

#include "KickoffResources.h"

namespace glt {
  class Game;

  class CommonBaseScene : public gf::Scene {
  public:
    CommonBaseScene(Game* game);

  private:
    static gf::ActionGroupSettings compute_settings();

    void do_process_event(const gf::Event& event) override;
    void do_handle_actions() override;

    Game* m_game;
    gf::ActionGroup m_action_group;
  };

}




#endif // GLT_KICKOFF_BASE_SCENE_H
