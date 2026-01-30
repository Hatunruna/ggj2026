// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_WORLD_BASE_SCENE_H
#define GFT_WORLD_BASE_SCENE_H

#include <gf2/core/ActionGroup.h>

#include <gf2/graphics/Scene.h>
#include <gf2/graphics/ShapeEntity.h>

#include "WorldResources.h"

namespace gft {
  class Game;

  class WorldBaseScene : public gf::Scene {
  public:
    WorldBaseScene(Game* game, const WorldResources& resources);

    void do_process_event(const gf::Event& event) override;
    void do_handle_actions() override;

  private:
    static gf::ActionGroupSettings compute_settings();

    Game* m_game = nullptr;
    gf::ActionGroup m_action_group;

    gf::ShapeEntity m_hero;
  };

}

#endif // GFT_WORLD_BASE_SCENE_H
