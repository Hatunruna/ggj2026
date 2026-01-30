// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "WorldResources.h"

#include <gf2/core/Color.h>
#include <gf2/framework/BundleBuilder.h>

#include "Game.h"

namespace gft {

  WorldResources::WorldResources()
  {

  }

  gf::ResourceBundle WorldResources::bundle(Game* game) const
  {
    gf::BundleBuilder builder(game);

    return builder.make_bundle();
  }


}
