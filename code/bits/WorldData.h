// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_WORLD_DATA_H
#define GLT_WORLD_DATA_H

#include <gf2/core/TiledMapResource.h>
#include <gf2/core/ResourceManager.h>

#include "MapData.h"

namespace glt {

  struct WorldData {

    std::vector<MapData> maps;

    void load_map(const gf::TiledMapResource& resource, gf::ResourceManager* resource_manager);
  };

}

#endif // GLT_WORLD_DATA_H
