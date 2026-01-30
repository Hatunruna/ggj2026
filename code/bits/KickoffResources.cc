// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffResources.h"

#include <gf2/core/Color.h>
#include <gf2/framework/BundleBuilder.h>

#include "Game.h"

namespace glt {

  KickoffResources::KickoffResources()
  {
    main_title_text.font = "thickhea.ttf";
    main_title_text.data.content = "Gelatine";
    main_title_text.data.color = gf::Yellow;
    main_title_text.data.character_size = 128.0f;

    loading_text.font = "Oxanium-Regular.ttf";
    loading_text.data.content = "Loading...";
    loading_text.data.color = gf::Yellow;
    loading_text.data.character_size = 64.0f;
  }

  gf::ResourceBundle KickoffResources::bundle(Game* game) const
  {
    gf::BundleBuilder builder(game);

    builder.add_in_bundle(main_title_text);
    builder.add_in_bundle(loading_text);

    return builder.make_bundle();
  }


}
