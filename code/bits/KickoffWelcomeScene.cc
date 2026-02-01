// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard

#include "KickoffWelcomeScene.h"

#include <gf2/core/SceneTypes.h>

#include "Constants.h"
#include "Game.h"

namespace glt {

  namespace {

    constexpr gf::Vec2F KickoffWelcomeSceneSize = { 1600, 900 };

  }


  KickoffWelcomeScene::KickoffWelcomeScene(Game* game, const KickoffResources& resources)
  : m_game(game)
  , m_action_group(compute_settings())
  , m_atlas({ 1024, 1024 }, game->render_manager())
  , m_main_title_text(&m_atlas, resources.main_title_text, game->render_manager(), game->resource_manager())
  , m_main_subtitle_text(&m_atlas, resources.main_subtitle_text, game->render_manager(), game->resource_manager())
  , m_title_audio(game->resource_manager()->get<gf::Music>(resources.title_audio.filename))
  {
    set_world_size(KickoffWelcomeSceneSize);
    set_world_center(KickoffWelcomeSceneSize / 2.0f);

    m_main_title_text.set_location(KickoffWelcomeSceneSize / 2.0f);
    m_main_title_text.set_origin({ 0.5f, 0.5f });
    add_world_entity(&m_main_title_text);

    m_main_subtitle_text.set_location(KickoffWelcomeSceneSize * gf::vec(0.5f, 0.8f));
    m_main_subtitle_text.set_origin({ 0.5f, 0.5f });
    add_world_entity(&m_main_subtitle_text);

    m_title_audio->set_looping(resources.title_audio.data.loop);
    m_title_audio->set_volume(1.0f);
  }

  gf::ActionGroupSettings KickoffWelcomeScene::compute_settings()
  {
    using namespace gf::literals;
    gf::ActionGroupSettings settings;

    settings.actions.emplace("menu"_id, gf::instantaneous_action().add_scancode_control(gf::Scancode::Space));

    return settings;
  }

  void KickoffWelcomeScene::do_process_event(const gf::Event& event)
  {
    m_action_group.process_event(event);
  }

  void KickoffWelcomeScene::do_handle_actions()
  {
    using namespace gf::literals;

    if (m_action_group.active("menu"_id)) {
       m_game->replace_scene(&m_game->kickoff_act()->menu_scene);
    }

    m_action_group.reset();
  }

  void KickoffWelcomeScene::on_rank_change([[maybe_unused]] gf::SceneRank old_rank, gf::SceneRank new_rank)
  {
    if (new_rank == gf::SceneRank::Top) {
      if (!m_title_audio->playing()) {
        m_title_audio->start();
      }
      m_title_audio->set_fade(0.0f, 1.0f, MaskAudioFade);
    }
  }

}
