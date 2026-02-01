// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#include "InventoryHudEntity.h"

#include <cassert>
#include <cstddef>

#include <gf2/core/Color.h>
#include <gf2/core/Positioning.h>
#include <gf2/core/Rect.h>
#include <gf2/core/ShapeBuffer.h>
#include <gf2/core/Vec2.h>

#include "Game.h"
#include "WorldResources.h"
#include "WorldState.h"

namespace glt {

  namespace {
    constexpr gf::Vec2F RelativeInventoryCenter = gf::Vec2F(0.0f, -0.40f); // The origin is in middle of the screen
    constexpr float RelativeMaskBoxWidth = 0.05f;
    constexpr float RelativeMaskBoxPaddingWidth = 0.01f;
    constexpr float BoxRadius = 16.0f;
    constexpr float RelativeBoxOutlineThickness = 0.002f;
    constexpr gf::Color BackgroundColor = gf::Color(0x0F0F0F, 175);
    constexpr gf::Color ActiveBackgroundColor = gf::Color(0x0F0F0F, 100);
    constexpr gf::Color ActiveOutlineColor = gf::Color(0xEFEFEF);
    constexpr float SpriteFactor = 3.0f / 128.0f;
  }

  InventoryHudEntity::InventoryHudEntity(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_shapes(compute_boxes(game, game->window()->surface_size()), game->render_manager())
  , m_red_mask(resources.red_mask_sprite, game->render_manager(), game->resource_manager())
  , m_red_mask_shaded(resources.red_mask_sprite_shaded, game->render_manager(), game->resource_manager())
  , m_green_mask(resources.green_mask_sprite, game->render_manager(), game->resource_manager())
  , m_green_mask_shaded(resources.green_mask_sprite_shaded, game->render_manager(), game->resource_manager())
  , m_blue_mask(resources.blue_mask_sprite, game->render_manager(), game->resource_manager())
  , m_blue_mask_shaded(resources.blue_mask_sprite_shaded, game->render_manager(), game->resource_manager())
  , m_placeholder_mask(resources.placeholder_mask, game->render_manager(), game->resource_manager())
  {
    gf::Positioning positioning(m_game->window()->surface_size());
    const float sprite_scale = positioning.relative_size({ 1.0f, RelativeMaskBoxWidth }).y * SpriteFactor;

    m_red_mask.set_origin(gf::Vec2F(0.5f, 0.5f));
    m_red_mask.set_scale(sprite_scale);

    m_red_mask_shaded.set_origin(gf::Vec2F(0.5f, 0.5f));
    m_red_mask_shaded.set_scale(sprite_scale);

    m_green_mask.set_origin(gf::Vec2F(0.5f, 0.5f));
    m_green_mask.set_scale(sprite_scale);

    m_green_mask_shaded.set_origin(gf::Vec2F(0.5f, 0.5f));
    m_green_mask_shaded.set_scale(sprite_scale);

    m_blue_mask.set_origin(gf::Vec2F(0.5f, 0.5f));
    m_blue_mask.set_scale(sprite_scale);

    m_blue_mask_shaded.set_origin(gf::Vec2F(0.5f, 0.5f));
    m_blue_mask_shaded.set_scale(sprite_scale);

    m_placeholder_mask.set_origin(gf::Vec2F(0.5f, 0.5f));
    m_placeholder_mask.set_scale(sprite_scale * 0.9f);
  }

  void InventoryHudEntity::update(gf::Time time)
  {
    std::size_t current_mask = m_game->world_state()->map.current_mask;

    if (m_last_mask != current_mask) {
      resize(m_game->window()->surface_size());
      m_last_mask = current_mask;
    }
  }

  void InventoryHudEntity::render(gf::RenderRecorder& recorder)
  {
    m_shapes.render(recorder);

    gf::Positioning positioning(m_game->window()->surface_size());
    const float sprite_scale = positioning.relative_size({ 1.0f, RelativeMaskBoxWidth }).y * SpriteFactor;

    const WorldState* world_state = m_game->world_state();
    const std::size_t mask_count = world_state->mask_count();

    for (std::size_t i = 0; i < mask_count; ++i) {
      if (world_state->is_mask_collected(i)) {
        // Plain mask
        if ((world_state->is_mask_current(i) || world_state->is_mask_available(i))) {
          switch (world_state->mask_color(i)) {
          case MaskColor::Red:
            m_red_mask.set_location(positioning.relative_point(compute_relative_mask_center(i, mask_count) + 0.5f));
            m_red_mask.set_scale(sprite_scale);
            m_red_mask.render(recorder);
            break;

          case MaskColor::Green:
            m_green_mask.set_location(positioning.relative_point(compute_relative_mask_center(i, mask_count) + 0.5f));
            m_green_mask.set_scale(sprite_scale);
            m_green_mask.render(recorder);
            break;

          case MaskColor::Blue:
            m_blue_mask.set_location(positioning.relative_point(compute_relative_mask_center(i, mask_count) + 0.5f));
            m_blue_mask.set_scale(sprite_scale);
            m_blue_mask.render(recorder);
            break;

          default:
            assert(false);
          }
        }
        // Shaded mask
        else {
          switch (world_state->mask_color(i)) {
          case MaskColor::Red:
            m_red_mask_shaded.set_location(positioning.relative_point(compute_relative_mask_center(i, mask_count) + 0.5f));
            m_red_mask_shaded.set_scale(sprite_scale);
            m_red_mask_shaded.render(recorder);
            break;

          case MaskColor::Green:
            m_green_mask_shaded.set_location(positioning.relative_point(compute_relative_mask_center(i, mask_count) + 0.5f));
            m_green_mask_shaded.set_scale(sprite_scale);
            m_green_mask_shaded.render(recorder);
            break;

          case MaskColor::Blue:
            m_blue_mask_shaded.set_location(positioning.relative_point(compute_relative_mask_center(i, mask_count) + 0.5f));
            m_blue_mask_shaded.set_scale(sprite_scale);
            m_blue_mask_shaded.render(recorder);
            break;

          default:
            assert(false);
          }
        }
      } else {
        m_placeholder_mask.set_location(positioning.relative_point(compute_relative_mask_center(i, mask_count) + 0.5f));
        m_placeholder_mask.set_scale(sprite_scale * 0.9f);
        m_placeholder_mask.render(recorder);
      }
    }
  }

  void InventoryHudEntity::resize(gf::Vec2I surface_size)
  {
    m_shapes.shape_group().update(compute_boxes(m_game, surface_size), m_game->render_manager());
  }

  gf::ShapeGroupBuffer InventoryHudEntity::compute_boxes(Game* game, const gf::Vec2F& screen_size)
  {
    gf::ShapeGroupBuffer buffer;

    gf::Positioning positioning(screen_size);

    const float screen_ratio = screen_size.w / screen_size.h;
    const std::size_t mask_count = game->world_state()->mask_count();
    const float relative_mask_box_height = RelativeMaskBoxWidth * screen_ratio;
    const float relative_mask_box_padding_height = RelativeMaskBoxPaddingWidth * screen_ratio;
    const float relative_inventory_background_width = (RelativeMaskBoxWidth + RelativeMaskBoxPaddingWidth) * static_cast<float>(mask_count);
    const gf::Vec2F inventory_background_size = positioning.relative_size(gf::Vec2F(
      relative_inventory_background_width,
      (relative_mask_box_height + relative_mask_box_padding_height)
    ));
    const float outline_thickness = positioning.relative_thickness(RelativeBoxOutlineThickness);

    {
      gf::ShapeBuffer canvas = gf::ShapeBuffer::make_rectangle(
        screen_size
      );
      canvas.color = gf::Color(0x000000, 0);

      buffer.shapes.emplace_back(canvas);
    }

    {
      gf::ShapeBuffer background = gf::ShapeBuffer::make_rounded_rectangle(
        gf::RectF::from_center_size(positioning.relative_point(RelativeInventoryCenter), inventory_background_size),
        BoxRadius
      );
      background.color = BackgroundColor;
      background.outline_color = gf::Black;
      background.outline_thickness = outline_thickness;

      buffer.shapes.emplace_back(background);
    }

    {
      const gf::Vec2F mask_center_location = positioning.relative_point(compute_relative_mask_center(game->world_state()->map.current_mask, mask_count));
      const gf::Vec2F mask_size = positioning.relative_size(gf::Vec2F(
        RelativeMaskBoxWidth,
        relative_mask_box_height
      ));

      gf::ShapeBuffer selection = gf::ShapeBuffer::make_rounded_rectangle(gf::RectF::from_center_size(mask_center_location, mask_size), BoxRadius);
      selection.color = ActiveBackgroundColor;
      selection.outline_color = ActiveOutlineColor;
      selection.outline_thickness = outline_thickness;

      buffer.shapes.emplace_back(selection);
    }

    return buffer;
  }

  gf::Vec2F InventoryHudEntity::compute_relative_mask_center(std::size_t index, std::size_t mask_count)
  {
    const float relative_inventory_background_width = (RelativeMaskBoxWidth + RelativeMaskBoxPaddingWidth) * static_cast<float>(mask_count);
    const float left_offset = ((1.0f - relative_inventory_background_width) * 0.5f) + ((RelativeMaskBoxWidth + RelativeMaskBoxPaddingWidth) * 0.5f);

    return {
      (left_offset + (static_cast<float>(index) * (relative_inventory_background_width / static_cast<float>(mask_count)))) - 0.5f,
      RelativeInventoryCenter.h
    };
  }

}
