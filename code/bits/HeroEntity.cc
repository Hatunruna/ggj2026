// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "HeroEntity.h"

#include "Game.h"

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

    switch (hero->direction) {
      case gf::Direction::Left:
        select(hero->running ? "run_left"_id : "pause_left"_id);
        break;
      case gf::Direction::Right:
        select(hero->running ? "run_right"_id : "pause_right"_id);
        break;
      case gf::Direction::Up:
        select(hero->running ? "run_up"_id : "pause_up"_id);
        break;
      case gf::Direction::Down:
        select(hero->running ? "run_down"_id : "pause_down"_id);
        break;
      case gf::Direction::Center:
        select("pause_left"_id);
        break;
    }

    set_location(hero->world_location);

    gf::AnimationGroupEntity::update(time);
  }

}
