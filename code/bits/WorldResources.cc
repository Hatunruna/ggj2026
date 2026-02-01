// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldResources.h"

#include <gf2/core/AnimationData.h>
#include <gf2/core/Color.h>
#include <gf2/core/ShapeBuffer.h>
#include <gf2/framework/BundleBuilder.h>

#include "Constants.h"
#include "Game.h"

namespace glt {

  constexpr gf::Color ShadeColor = gf::gray(0.5f) * gf::opaque(0.5f);

  WorldResources::WorldResources()
  {
    using namespace gf::literals;

    hero_animations.textures = {
      // Run animations
      "animations/hero/run-left-right-red.png",
      "animations/hero/run-left-right-green.png",
      "animations/hero/run-left-right-blue.png",
      "animations/hero/run-up.png",
      "animations/hero/run-down-red.png",
      "animations/hero/run-down-green.png",
      "animations/hero/run-down-blue.png",

      // Pause animations
      "animations/hero/pause-left-right-red.png",
      "animations/hero/pause-left-right-green.png",
      "animations/hero/pause-left-right-blue.png",
      "animations/hero/pause-up.png",
      "animations/hero/pause-down-red.png",
      "animations/hero/pause-down-green.png",
      "animations/hero/pause-down-blue.png",

      // Remove mask animations
      "animations/hero/remove-mask-red-0.png",
      "animations/hero/remove-mask-red-1.png",
      // TODO: add other color

      // Wear mask animation
      "animations/hero/wear-mask-red.png",
      // TODO: add other color
    };

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(0, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_left_red"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(1, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_left_green"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(2, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_left_blue"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(0, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 19);

      hero_animations.data.animations.emplace("run_right_red"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(1, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 19);

      hero_animations.data.animations.emplace("run_right_green"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(2, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 19);

      hero_animations.data.animations.emplace("run_right_blue"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(3, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_up_red"_id, animation);
      hero_animations.data.animations.emplace("run_up_green"_id, animation);
      hero_animations.data.animations.emplace("run_up_blue"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(4, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_down_red"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(5, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_down_green"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(6, {8, 8}, gf::seconds(1.0f / 25.0f), 19);

      hero_animations.data.animations.emplace("run_down_blue"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(7, {8, 8}, gf::seconds(1.0f / 25.0f), 28);

      hero_animations.data.animations.emplace("pause_left_red"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(8, {8, 8}, gf::seconds(1.0f / 25.0f), 28);

      hero_animations.data.animations.emplace("pause_left_green"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(9, {8, 8}, gf::seconds(1.0f / 25.0f), 28);

      hero_animations.data.animations.emplace("pause_left_blue"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(7, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 28);

      hero_animations.data.animations.emplace("pause_right_red"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(8, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 28);

      hero_animations.data.animations.emplace("pause_right_green"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(9, {8, 8}, gf::seconds(1.0f / 25.0f), gf::AnimationFrameFlip::Horizontally, 28);

      hero_animations.data.animations.emplace("pause_right_blue"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(10, {8, 8}, gf::seconds(1.0f / 25.0f), 28);

      hero_animations.data.animations.emplace("pause_up_red"_id, animation);
      hero_animations.data.animations.emplace("pause_up_green"_id, animation);
      hero_animations.data.animations.emplace("pause_up_blue"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(11, {8, 8}, gf::seconds(1.0f / 25.0f), 28);

      hero_animations.data.animations.emplace("pause_down_red"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(12, {8, 8}, gf::seconds(1.0f / 25.0f), 28);

      hero_animations.data.animations.emplace("pause_down_green"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.properties.set(gf::AnimationProperties::Loop);
      animation.add_tileset(13, {8, 8}, gf::seconds(1.0f / 25.0f), 28);

      hero_animations.data.animations.emplace("pause_down_blue"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(14, {8, 8}, gf::seconds(1.0f / 25.0f), 64);
      animation.add_tileset(15, {8, 8}, gf::seconds(1.0f / 25.0f), 12);
      animation.add_tileset(16, {8, 8}, gf::seconds(1.0f / 25.0f), 45);

      hero_animations.data.animations.emplace("change_mask_red_to_red"_id, animation);
      // FIXME: Generate the right animations when the texture will be available
      hero_animations.data.animations.emplace("change_mask_red_to_green"_id, animation);
      hero_animations.data.animations.emplace("change_mask_red_to_blue"_id, animation);
      hero_animations.data.animations.emplace("change_mask_green_to_red"_id, animation);
      hero_animations.data.animations.emplace("change_mask_green_to_green"_id, animation);
      hero_animations.data.animations.emplace("change_mask_green_to_blue"_id, animation);
      hero_animations.data.animations.emplace("change_mask_blue_to_red"_id, animation);
      hero_animations.data.animations.emplace("change_mask_blue_to_green"_id, animation);
      hero_animations.data.animations.emplace("change_mask_blue_to_blue"_id, animation);
    }

    red_mask_sprite.texture = "sprites/red_mask.png";

    red_mask_sprite_shaded.texture = "sprites/red_mask.png";
    red_mask_sprite_shaded.data.color = ShadeColor;

    green_mask_sprite.texture = "sprites/green_mask.png";

    green_mask_sprite_shaded.texture = "sprites/green_mask.png";
    green_mask_sprite_shaded.data.color = ShadeColor;

    blue_mask_sprite.texture = "sprites/blue_mask.png";

    blue_mask_sprite_shaded.texture = "sprites/blue_mask.png";
    blue_mask_sprite_shaded.data.color = ShadeColor;

    placeholder_mask.texture = "sprites/unknown_mask.png";

    star_sprite.texture = "sprites/star.png";
    star_sprite.data.color = GelatineYellow;

    red_mask_audio.filename = "audio/red-mask.ogg";
    red_mask_audio.data.loop = true;

    green_mask_audio.filename = "audio/green-mask.ogg";
    green_mask_audio.data.loop = true;

    blue_mask_audio.filename = "audio/blue-mask.ogg";
    blue_mask_audio.data.loop = true;

    finish_text.font = "thickhea.ttf";
    finish_text.data.content = "Congratulations! You found the star!";
    finish_text.data.color = GelatineYellow;
    finish_text.data.character_size = 128.0f;
  }

  gf::ResourceBundle WorldResources::bundle(Game* game) const
  {
    gf::BundleBuilder builder(game);

    builder.add_in_bundle(map);

    builder.add_in_bundle(hero_animations);

    builder.add_in_bundle(red_mask_sprite);
    builder.add_in_bundle(red_mask_sprite_shaded);
    builder.add_in_bundle(green_mask_sprite);
    builder.add_in_bundle(green_mask_sprite_shaded);
    builder.add_in_bundle(blue_mask_sprite);
    builder.add_in_bundle(blue_mask_sprite_shaded);

    builder.add_in_bundle(red_mask_audio);
    builder.add_in_bundle(green_mask_audio);
    builder.add_in_bundle(blue_mask_audio);

    builder.add_in_bundle(red_mask_sprite);
    builder.add_in_bundle(red_mask_sprite_shaded);
    builder.add_in_bundle(green_mask_sprite);
    builder.add_in_bundle(green_mask_sprite_shaded);
    builder.add_in_bundle(blue_mask_sprite);
    builder.add_in_bundle(blue_mask_sprite_shaded);
    builder.add_in_bundle(placeholder_mask);

    builder.add_in_bundle(star_sprite);

    return builder.make_bundle();
  }


}
