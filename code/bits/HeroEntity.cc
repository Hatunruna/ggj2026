// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "HeroEntity.h"

#include <fmt/format.h>

#include "Game.h"
#include "gf2/core/Direction.h"
#include "gf2/core/Id.h"

namespace glt {

  HeroEntity::HeroEntity(Game* game, const WorldResources& resources)
  : gf::AnimationGroupEntity(resources.hero_animations, game->render_manager(), game->resource_manager())
  , m_game(game)
  {
    WorldState* state =game->world_state();
    state->hero.tile_location = state->hero.tile_target =  state->map.ref->start;
  }

  void HeroEntity::update(gf::Time time)
  {
    using namespace gf::literals;

    const WorldState* state = m_game->world_state();
    const HeroState* hero = &state->hero;

    std::string direction_string;
    switch (hero->direction) {
    case gf::Direction::Right:
      direction_string = "right";
      break;

    case gf::Direction::Down:
      direction_string = "down";
      break;

    case gf::Direction::Up:
      direction_string = "up";
      break;

    case gf::Direction::Left:
    default:
      direction_string = "left";
      break;
    }

    std::string color_string;
    switch (state->current_mask_color()) {
    case MaskColor::Green:
      color_string = "green";
      break;

    case MaskColor::Blue:
      color_string = "blue";
      break;

    case MaskColor::Red:
    default:
      color_string = "red";
      break;
    }

    const std::string animation_string_id =
      fmt::format("{}_{}_{}",
        hero->running ? "run" : "pause",
        direction_string,
        color_string
    );

    select(gf::hash_string(animation_string_id));

    set_location(hero->world_location);

    gf::AnimationGroupEntity::update(time);
  }

}
