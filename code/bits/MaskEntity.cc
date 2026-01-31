// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "MaskEntity.h"

#include <gf2/core/Range.h>
#include <gf2/core/Transform.h>
#include <gf2/graphics/RenderRecorder.h>
#include <gf2/graphics/RenderObject.h>

#include "Constants.h"
#include "Game.h"

namespace glt {

  MaskEntity::MaskEntity(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_red_mask(resources.red_mask_sprite, game->render_manager(), game->resource_manager())
  , m_green_mask(resources.green_mask_sprite, game->render_manager(), game->resource_manager())
  , m_blue_mask(resources.blue_mask_sprite, game->render_manager(), game->resource_manager())
  {
  }

  void MaskEntity::render(gf::RenderRecorder& recorder)
  {
    const WorldState* state = m_game->world_state();

    for (auto [ index, mask_state ] : gf::enumerate(state->map.masks)) {
      if (mask_state == MaskState::Inventory) {
        continue;
      }

      const MaskMap& mask = state->map.ref->masks[index];
      assert(mask.position);

      gf::Transform transform = {};
      transform.location = mask.position.value() * TileSize;

      gf::RenderObject object = {};

      switch (mask.color) {
        case MaskColor::Red:
          object.geometry = m_red_mask.geometry();
          object.transform = transform.compute_matrix(m_red_mask.bounds());
          break;
        case MaskColor::Green:
          object.geometry = m_green_mask.geometry();
          object.transform = transform.compute_matrix(m_green_mask.bounds());
          break;
        case MaskColor::Blue:
          object.geometry = m_blue_mask.geometry();
          object.transform = transform.compute_matrix(m_blue_mask.bounds());
          break;
        case MaskColor::None:
          break;
      }

      recorder.record(object);
    }
  }

}
