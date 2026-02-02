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
  constexpr gf::Time MaskChangeFrameTime = gf::milliseconds(20);

  WorldResources::WorldResources()
  {
    using namespace gf::literals;

    hero_animations.textures = {
      // Run animations
      "animations/hero/run-left-right-red.png",     //  0
      "animations/hero/run-left-right-green.png",   //  1
      "animations/hero/run-left-right-blue.png",    //  2
      "animations/hero/run-up.png",                 //  3
      "animations/hero/run-down-red.png",           //  4
      "animations/hero/run-down-green.png",         //  5
      "animations/hero/run-down-blue.png",          //  6

      // Pause animations
      "animations/hero/pause-left-right-red.png",   //  7
      "animations/hero/pause-left-right-green.png", //  8
      "animations/hero/pause-left-right-blue.png",  //  9
      "animations/hero/pause-up.png",               // 10
      "animations/hero/pause-down-red.png",         // 11
      "animations/hero/pause-down-green.png",       // 12
      "animations/hero/pause-down-blue.png",        // 13

      // Remove mask animations
      "animations/hero/remove-mask-red-0.png",      // 14
      "animations/hero/remove-mask-red-1.png",      // 15
      "animations/hero/remove-mask-green-0.png",    // 16
      "animations/hero/remove-mask-green-1.png",    // 17
      "animations/hero/remove-mask-blue-0.png",     // 18
      "animations/hero/remove-mask-blue-1.png",     // 19

      // Wear mask animation
      "animations/hero/wear-mask-red.png",          // 20
      "animations/hero/wear-mask-green.png",        // 21
      "animations/hero/wear-mask-blue.png",         // 22
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
      animation.add_tileset(14, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(15, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(20, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_red_to_red_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(14, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(15, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(21, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_red_to_green_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(14, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(15, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(22, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_red_to_blue_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(16, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(17, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(20, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_green_to_red_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(16, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(17, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(21, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_green_to_green_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(16, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(17, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(22, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_green_to_blue_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(18, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(19, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(20, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_blue_to_red_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(18, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(19, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(21, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_blue_to_green_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(18, {8, 8}, MaskChangeFrameTime, 64);
      animation.add_tileset(19, {8, 8}, MaskChangeFrameTime, 16);
      animation.add_tileset(21, {8, 8}, MaskChangeFrameTime, 41);

      hero_animations.data.animations.emplace("change_mask_blue_to_blue_left"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(14, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(15, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(20, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_red_to_red_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(14, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(15, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(21, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_red_to_green_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(14, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(15, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(22, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_red_to_blue_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(16, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(17, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(20, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_green_to_red_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(16, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(17, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(21, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_green_to_green_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(16, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(17, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(22, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_green_to_blue_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(18, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(19, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(20, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_blue_to_red_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(18, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(19, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(21, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_blue_to_green_right"_id, animation);
    }

    {
      gf::AnimationData animation;
      animation.add_tileset(18, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 64);
      animation.add_tileset(19, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 16);
      animation.add_tileset(21, {8, 8}, MaskChangeFrameTime, gf::AnimationFrameFlip::Horizontally, 41);

      hero_animations.data.animations.emplace("change_mask_blue_to_blue_right"_id, animation);
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
    finish_text.data.content = "Congratulations!\nYou found the star!";
    finish_text.data.color = GelatineYellow;
    finish_text.data.character_size = 128.0f;
    finish_text.data.paragraph_width = 1600.0f;
    finish_text.data.alignment = gf::Alignment::Center;

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
