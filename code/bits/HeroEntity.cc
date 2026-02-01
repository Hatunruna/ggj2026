// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "HeroEntity.h"

#include <fmt/format.h>

#include "Game.h"
#include "HeroState.h"
#include "MaskColor.h"

namespace glt {

  HeroEntity::HeroEntity(Game* game, const WorldResources& resources)
  : gf::AnimationGroupEntity(resources.hero_animations, game->render_manager(), game->resource_manager())
  , m_game(game)
  , m_mask_color(game->world_state()->current_mask_color())
  {
    WorldState* state =game->world_state();
    state->hero.tile_location = state->hero.tile_target =  state->map.ref->start;
  }

  void HeroEntity::update(gf::Time time)
  {
    using namespace gf::literals;

    WorldState* state = m_game->world_state();
    HeroState* hero = &state->hero;

    auto color_to_string = [](MaskColor color) -> std::string {
      std::string string;
      switch (color) {
      case MaskColor::Green:
        string = "green";
        break;

      case MaskColor::Blue:
        string = "blue";
        break;

      case MaskColor::Red:
      default:
        string = "red";
        break;
      }

      return string;
    };

    auto direction_to_string = [](gf::Direction direction) -> std::string {
      std::string string;
      switch (direction) {
      case gf::Direction::Right:
        string = "right";
        break;

      case gf::Direction::Down:
        string = "down";
        break;

      case gf::Direction::Up:
        string = "up";
        break;

      case gf::Direction::Left:
      default:
        string = "left";
        break;
      }

      return string;
    };

    std::string animation_string_id;
    if (hero->status == HeroStatus::ChangeMask) {
      gf::Direction direction_override = (hero->direction == gf::Direction::Up || hero->direction == gf::Direction::Left) ? gf::Direction::Left : gf::Direction::Right;
       animation_string_id =
        fmt::format("change_mask_{}_to_{}_{}",
          color_to_string(m_mask_color),
          color_to_string(state->next_mask_color()),
          direction_to_string(direction_override)
      );

      if (finished()) {
        hero->status = HeroStatus::Move;
        hero->direction = direction_override;
        state->map.current_mask = state->map.next_mask;
        m_mask_color = state->current_mask_color();
      }
    } else {
      animation_string_id =
        fmt::format("{}_{}_{}",
          hero->running ? "run" : "pause",
          direction_to_string(hero->direction),
          color_to_string(m_mask_color)
      );
    }

    select(gf::hash_string(animation_string_id));

    set_location(hero->world_location);

    gf::AnimationGroupEntity::update(time);
  }

}
