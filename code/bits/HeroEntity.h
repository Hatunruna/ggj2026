// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_HERO_ENTITY_H
#define GLT_HERO_ENTITY_H

#include <gf2/graphics/AnimationGroupEntity.h>

#include "MaskColor.h"
#include "WorldResources.h"

namespace glt {
  class Game;

  class HeroEntity : public gf::AnimationGroupEntity {
  public:
    HeroEntity(Game* game, const WorldResources& resources);

    void update(gf::Time time) override;

  private:
    Game* m_game = nullptr;

    MaskColor m_mask_color;
  };

}

#endif // GLT_HERO_ENTITY_H
