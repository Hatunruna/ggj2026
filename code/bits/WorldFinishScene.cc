#include "WorldFinishScene.h"

#include "Game.h"

namespace glt {

  namespace {

    constexpr gf::Vec2F WorldFinishSceneSize = { 1600, 900 };

  }

  WorldFinishScene::WorldFinishScene(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_atlas({ 1024, 1024 }, game->render_manager())
  , m_finish_text(&m_atlas, resources.finish_text, game->render_manager(), game->resource_manager())
  {
    set_world_size(WorldFinishSceneSize);
    set_world_center(WorldFinishSceneSize / 2.0f);

    m_finish_text.set_location(WorldFinishSceneSize / 2.0f);
    m_finish_text.set_origin({ 0.5f, 0.5f });

    add_world_entity(&m_finish_text);
  }

  gf::ActionGroupSettings WorldFinishScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("finish"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Space));

    return settings;
  }

  void WorldFinishScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void WorldFinishScene::do_handle_actions()
  {
    using namespace gf::literals;

    if (m_action_group.active("finish"_id)) {
      gf::BasicScene* scenes[] = { &m_game->kickoff_act()->common_scene, &m_game->kickoff_act()->welcome_scene };
      m_game->replace_all_scenes(scenes);
    }

    m_action_group.reset();
  }

}
