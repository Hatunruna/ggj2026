// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_WORLD_MODEL_H
#define GFT_WORLD_MODEL_H

#include <gf2/core/Model.h>
#include "WorldData.h"
#include "WorldState.h"

namespace gft {

  struct WorldModel : public gf::Model {
    WorldData data;
    WorldState state;

    void update(gf::Time time) override;
  };

}

#endif // GFT_WORLD_MODEL_H
