// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#ifndef GLT_MASK_COLOR_H
#define GLT_MASK_COLOR_H

#include <cstdint>

namespace glt {

  enum class MaskColor : uint8_t {
    None,
    Red,
    Green,
    Blue,
  };

}

#endif // GLT_MASK_COLOR_H
