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
      "animations/hero/run-up.png",
      "animations/hero/run-down.png",
      "animations/hero/pause-left-right.png",
      "animations/hero/pause-up.png",
      "animations/hero/pause-down.png",
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
      animation.add_tileset(0, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 19);

      hero_animations.data.animations.emplace("run_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(1, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_up"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(2, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_down"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(3, {8, 8}, gf::seconds(1.0f / 25.0f), 28);

      hero_animations.data.animations.emplace("pause_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(3, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 28);

      hero_animations.data.animations.emplace("pause_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(4, {8, 8}, gf::seconds(1.0f / 25.0f), 29);

      hero_animations.data.animations.emplace("pause_up"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(5, {8, 8}, gf::seconds(1.0f / 25.0f), 29);

      hero_animations.data.animations.emplace("pause_down"_id, animation);
    }

    red_mask_audio.filename = "audio/red-mask.ogg";
    red_mask_audio.data.loop = true;

    green_mask_audio.filename = "audio/green-mask.ogg";
    green_mask_audio.data.loop = true;

    blue_mask_audio.filename = "audio/blue-mask.ogg";
    blue_mask_audio.data.loop = true;
  }

  gf::ResourceBundle WorldResources::bundle(Game* game) const
  {
    gf::BundleBuilder builder(game);

    builder.add_in_bundle(tutorial_map);

    builder.add_in_bundle(hero_animations);

    builder.add_in_bundle(red_mask_audio);
    builder.add_in_bundle(green_mask_audio);
    builder.add_in_bundle(blue_mask_audio);

    return builder.make_bundle();
  }


}
