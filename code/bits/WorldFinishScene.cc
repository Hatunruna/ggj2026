#include "WorldFinishScene.h"

#include "Game.h"

namespace glt {

  namespace {

    constexpr gf::Vec2F WorldFinishSceneSize = { 1600, 900 };

  }

  WorldFinishScene::WorldFinishScene(Game* game, const WorldResources& resources)
  : m_atlas({ 1024, 1024 }, game->render_manager())
  , m_finish_text(&m_atlas, resources.finish_text, game->render_manager(), game->resource_manager())
  {
    set_world_size(WorldFinishSceneSize);
    set_world_center(WorldFinishSceneSize / 2.0f);

    m_finish_text.set_location(WorldFinishSceneSize / 2.0f);
    m_finish_text.set_origin({ 0.5f, 0.5f });

    add_world_entity(&m_finish_text);
  }

}
