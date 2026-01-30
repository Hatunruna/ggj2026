// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#include <filesystem>
#include <memory>

#include <gf2/framework/SceneSystem.h>
#include <gf2/graphics/RenderAsync.h>

#include "KickoffAct.h"
#include "KickoffResources.h"
#include "WorldAct.h"
#include "WorldModel.h"
#include "WorldResources.h"

namespace gft {

  class Game : public gf::SceneSystem {
  public:
    Game(const std::filesystem::path& asset_directory);

    KickoffAct* kickoff_act()
    {
      return m_kickoff_act.get();
    }

    WorldModel* world_model()
    {
      return &m_world_model;
    }

    WorldData* world_data()
    {
      return &m_world_model.data;
    }

    WorldState* world_state()
    {
      return &m_world_model.state;
    }

    WorldAct* world_act()
    {
      return m_world_act.get();
    }

    void load_world();
    bool world_loaded();
    void start_world();

  private:
    KickoffResources m_kickoff_resources;
    std::unique_ptr<KickoffAct> m_kickoff_act;

    gf::RenderAsync m_async;
    WorldModel m_world_model;
    WorldResources m_world_resources;
    std::unique_ptr<WorldAct> m_world_act;
  };

}
