#include "CommonBaseScene.h"

#include "Game.h"

namespace glt {

  CommonBaseScene::CommonBaseScene(Game* game)
  : m_game(game)
  , m_action_group(compute_settings())
  {
    game->window()->toggle_fullscreen();
  }

  gf::ActionGroupSettings CommonBaseScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("fullscreen"_id, gf::instantaneous_action().add_keycode_control(gf::Keycode::F));
    settings.actions.emplace("exit"_id, gf::instantaneous_action().add_keycode_control(gf::Keycode::Escape));

    return settings;
  }

  void CommonBaseScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void CommonBaseScene::do_handle_actions()
  {
    using namespace gf::literals;

    if (m_action_group.active("fullscreen"_id)) {
      m_game->window()->toggle_fullscreen();
    }

    if (m_action_group.active("exit"_id)) {
      m_game->pop_all_scenes();
    }

    m_action_group.reset();
  }

}
