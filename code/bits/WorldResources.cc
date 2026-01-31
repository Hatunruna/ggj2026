// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldResources.h"

#include <gf2/core/Color.h>
#include <gf2/core/ShapeBuffer.h>
#include <gf2/framework/BundleBuilder.h>

#include "Game.h"
#include "Constants.h"

namespace glt {

  WorldResources::WorldResources()
  {
    hero_shape.buffer = gf::ShapeBuffer::make_circle(gf::CircF::from_radius(TileSize.w));
    hero_shape.buffer.color = gf::Green;

    tutorial_map.filename = "map/tutorial.tmx";
  }

  gf::ResourceBundle WorldResources::bundle(Game* game) const
  {
    gf::BundleBuilder builder(game);

    builder.add_in_bundle(hero_shape);
    builder.add_in_bundle(tutorial_map);

    return builder.make_bundle();
  }


}
