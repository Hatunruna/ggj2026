// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_MASK_ENTITY_H
#define GLT_MASK_ENTITY_H

#include <gf2/graphics/Entity.h>
#include <gf2/graphics/Sprite.h>
#include "HeroEntity.h"
#include "WorldResources.h"

namespace glt {

  class MaskEntity : public gf::Entity {
  public:
    MaskEntity(Game* game, const WorldResources& resources);

    void render(gf::RenderRecorder& recorder) override;

  private:
    Game* m_game = nullptr;
    gf::Sprite m_red_mask;
    gf::Sprite m_green_mask;
    gf::Sprite m_blue_mask;
  };

}

#endif // GLT_MASK_ENTITY_H
