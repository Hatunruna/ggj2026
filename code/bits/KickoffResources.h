// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GFT_KICKOFF_RESOURCES_H
#define GFT_KICKOFF_RESOURCES_H

#include <gf2/core/ResourceBundle.h>

#include <gf2/graphics/Text.h>

namespace gft {
  class Game;

  struct KickoffResources {
    KickoffResources();

    gf::ResourceBundle bundle(Game* game) const;

    // resources

    gf::TextResource main_title_text;
    gf::TextResource loading_text;
  };

}

#endif // GFT_KICKOFF_RESOURCES_H
