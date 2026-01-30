// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#include "bits/Game.h"

#if defined(_WIN32) && defined(NDEBUG)
#include <windows.h>
#endif

#if defined(_WIN32) && defined(NDEBUG)
int WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
#else
int main()
#endif
{
  gft::Game game(std::filesystem::current_path() / "data");
  return game.run();
}
