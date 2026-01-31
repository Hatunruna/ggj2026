// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_BASE_SCENE_H
#define GLT_WORLD_BASE_SCENE_H

#include <gf2/core/ActionGroup.h>

#include <gf2/audio/Sound.h>

#include <gf2/graphics/AnimationGroupEntity.h>
#include <gf2/graphics/Scene.h>

#include "WorldResources.h"

namespace glt {
  class Game;

  class WorldBaseScene : public gf::Scene {
  public:
    WorldBaseScene(Game* game, const WorldResources& resources);

    void do_process_event(const gf::Event& event) override;
    void do_handle_actions() override;
    void do_update(gf::Time time) override;

  private:
    static gf::ActionGroupSettings compute_settings();

    Game* m_game = nullptr;
    gf::ActionGroup m_action_group;

    gf::AnimationGroupEntity m_hero;

    gf::Sound* m_red_mask_sound = nullptr;
    gf::Sound* m_green_mask_sound = nullptr;
    gf::Sound* m_blue_mask_sound = nullptr;
  };

}

#endif // GLT_WORLD_BASE_SCENE_H
