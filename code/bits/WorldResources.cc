// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldResources.h"

#include <gf2/core/AnimationData.h>
#include <gf2/core/Color.h>
#include <gf2/core/ShapeBuffer.h>
#include <gf2/framework/BundleBuilder.h>

#include "Game.h"

namespace glt {

  WorldResources::WorldResources()
  {
    using namespace gf::literals;

    tutorial_map.filename = "map/tutorial.tmx";

    hero_animations.textures = {
      "animations/hero/run-left-right.png",
      "animations/hero/run-left-right.png",
      "animations/hero/pause-left-right.png",
      "animations/hero/pause-left-right.png",
    };

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(0, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(1, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 19);

      hero_animations.data.animations.emplace("run_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(2, {1, 1}, gf::seconds(1.0f / 25.0f), 1);

      hero_animations.data.animations.emplace("pause_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(3, {1, 1}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 1);

      hero_animations.data.animations.emplace("pause_right"_id, animation);
    }
  }

  gf::ResourceBundle WorldResources::bundle(Game* game) const
  {
    gf::BundleBuilder builder(game);

    builder.add_in_bundle(tutorial_map);

    builder.add_in_bundle(hero_animations);

    return builder.make_bundle();
  }


}
