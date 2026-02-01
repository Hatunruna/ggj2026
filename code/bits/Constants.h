#ifndef GLT_CONSTANTS_ACT_H
#define GLT_CONSTANTS_ACT_H

#include <gf2/core/Color.h>
#include <gf2/core/Time.h>
#include <gf2/core/Vec2.h>

namespace glt {

  constexpr gf::Vec2F TileSize = {128.0f, 128.0f};
  constexpr gf::Time HeroMoveCooldown = gf::seconds(0.40f);
  constexpr gf::Time MaskAudioFade = gf::seconds(2.0f);

  constexpr gf::Color GelatineYellow = 0xF5E74E;

}

#endif // GLT_CONSTANTS_ACT_H
