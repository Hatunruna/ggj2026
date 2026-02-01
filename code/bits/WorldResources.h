// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_RESOURCES_H
#define GLT_WORLD_RESOURCES_H

#include <gf2/core/AudioSourceData.h>
#include <gf2/core/ResourceBundle.h>
#include <gf2/core/SpriteData.h>
#include <gf2/core/TiledMapResource.h>

#include <gf2/graphics/AnimationGroup.h>
#include <gf2/graphics/Shape.h>
#include <gf2/graphics/Text.h>

namespace glt {
  class Game;

  struct WorldResources {
    WorldResources();

    gf::ResourceBundle bundle(Game* game) const;

    // resources
    gf::TiledMapResource map;

    gf::AnimationGroupResource hero_animations;

    gf::SpriteResource red_mask_sprite;
    gf::SpriteResource red_mask_sprite_shaded;
    gf::SpriteResource green_mask_sprite;
    gf::SpriteResource green_mask_sprite_shaded;
    gf::SpriteResource blue_mask_sprite;
    gf::SpriteResource blue_mask_sprite_shaded;
    gf::SpriteResource placeholder_mask;

    gf::AudioSourceResource red_mask_audio;
    gf::AudioSourceResource green_mask_audio;
    gf::AudioSourceResource blue_mask_audio;

  };

}

#endif // GLT_WORLD_RESOURCES_H
