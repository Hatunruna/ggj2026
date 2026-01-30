// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_RESOURCES_H
#define GLT_WORLD_RESOURCES_H

#include <gf2/core/ResourceBundle.h>

#include <gf2/graphics/Shape.h>
#include <gf2/graphics/Text.h>

namespace glt {
  class Game;

  struct WorldResources {
    WorldResources();

    gf::ResourceBundle bundle(Game* game) const;

    // resources
    gf::ShapeResource hero_shape;
  };

}

#endif // GLT_WORLD_RESOURCES_H
