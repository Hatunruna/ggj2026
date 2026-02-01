// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffResources.h"

#include <gf2/core/Color.h>
#include <gf2/framework/BundleBuilder.h>

#include "Constants.h"
#include "Game.h"

namespace glt {

  KickoffResources::KickoffResources()
  {
    main_title_text.font = "thickhea.ttf";
    main_title_text.data.content = "Gelatine";
    main_title_text.data.color = GelatineYellow;
    main_title_text.data.character_size = 256.0f;

    main_subtitle_text.font = "thickhea.ttf";
    main_subtitle_text.data.content = "Press space to continue";
    main_subtitle_text.data.color = GelatineYellow;
    main_subtitle_text.data.character_size = 48.0f;

    loading_text.font = "thickhea.ttf";
    loading_text.data.content = "Loading...";
    loading_text.data.color = GelatineYellow;
    loading_text.data.character_size = 96.0f;

    arrow_text.font = "thickhea.ttf";
    arrow_text.data.content = ">";
    arrow_text.data.color = GelatineYellow;
    arrow_text.data.character_size = 48.0f;

    tutorial_text.font = "thickhea.ttf";
    tutorial_text.data.content = "Tutorial";
    tutorial_text.data.color = GelatineYellow;
    tutorial_text.data.character_size = 48.0f;

    level01_text.font = "thickhea.ttf";
    level01_text.data.content = "Level #01";
    level01_text.data.color = GelatineYellow;
    level01_text.data.character_size = 48.0f;

    level02_text.font = "thickhea.ttf";
    level02_text.data.content = "Level #02";
    level02_text.data.color = GelatineYellow;
    level02_text.data.character_size = 48.0f;

    level03_text.font = "thickhea.ttf";
    level03_text.data.content = "Level #03";
    level03_text.data.color = GelatineYellow;
    level03_text.data.character_size = 48.0f;
  }

  gf::ResourceBundle KickoffResources::bundle(Game* game) const
  {
    gf::BundleBuilder builder(game);

    builder.add_in_bundle(main_title_text);
    builder.add_in_bundle(loading_text);

    return builder.make_bundle();
  }


}
