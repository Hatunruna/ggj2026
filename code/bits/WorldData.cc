// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldData.h"

#include <cassert>
#include "MapData.h"

namespace glt {

  void WorldData::load_map(const gf::TiledMapResource& resource, gf::ResourceManager* resource_manager)
  {
    const gf::TiledMap* tiled = resource_manager->get<gf::TiledMap>(resource.filename);
    assert(tiled != nullptr);

    maps.push_back(create_map(tiled));
  }

}
