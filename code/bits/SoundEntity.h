// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_SOUND_ENTITY_RESOURCES_H
#define GLT_SOUND_ENTITY_RESOURCES_H

#include <gf2/audio/Sound.h>

#include <gf2/graphics/Entity.h>

#include "MaskColor.h"
#include "WorldResources.h"

namespace glt {

  class Game;

  class SoundEntity : public gf::Entity {
  public:
    SoundEntity(Game* game, const WorldResources& resources);

    void update(gf::Time time) override;

  private:
    Game* m_game = nullptr;

    MaskColor m_mask_color = MaskColor::None;

    gf::Sound* m_red_mask_sound = nullptr;
    gf::Sound* m_green_mask_sound = nullptr;
    gf::Sound* m_blue_mask_sound = nullptr;
  };

}

#endif // GLT_SOUND_ENTITY_RESOURCES_H
