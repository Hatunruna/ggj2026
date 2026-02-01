// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (c) 2025 Julien Bernard
#include "SoundEntity.h"

#include "Constants.h"
#include "Game.h"
#include "MaskColor.h"

namespace glt {

  SoundEntity::SoundEntity(Game* game, const WorldResources& resources)
  : m_game(game)
  , m_red_mask_sound(game->resource_manager()->get<gf::Sound>(resources.red_mask_audio.filename))
  , m_green_mask_sound(game->resource_manager()->get<gf::Sound>(resources.green_mask_audio.filename))
  , m_blue_mask_sound(game->resource_manager()->get<gf::Sound>(resources.blue_mask_audio.filename))
  {
    const gf::Time audio_time = game->audio_manager()->time();
    m_red_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));
    m_green_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));
    m_blue_mask_sound->set_start_time(audio_time + gf::seconds(0.10f));

    m_red_mask_sound->set_looping(resources.red_mask_audio.data.loop);
    m_green_mask_sound->set_looping(resources.green_mask_audio.data.loop);
    m_blue_mask_sound->set_looping(resources.blue_mask_audio.data.loop);

    m_red_mask_sound->set_volume(0.0f);
    m_green_mask_sound->set_volume(0.0f);
    m_blue_mask_sound->set_volume(0.0f);

    m_red_mask_sound->start();
    m_green_mask_sound->start();
    m_blue_mask_sound->start();
  }

  void SoundEntity::update([[maybe_unused]] gf::Time time)
  {
    const WorldState* state = m_game->world_state();

    if (state->hero.status == HeroStatus::End) {
      switch (m_mask_color) {
      case MaskColor::Red:
        m_red_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
      break;
      case MaskColor::Blue:
        m_blue_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
        break;
      case MaskColor::Green:
        m_green_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
        break;

      default:
        // nothing to do
        break;
      }

      return;
    }

    const MaskColor new_mask_color = state->current_mask_color();

    if (new_mask_color == m_mask_color) {
      return;
    }

    switch (m_mask_color) {
    case MaskColor::Red:
      m_red_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
     break;
    case MaskColor::Blue:
      m_blue_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
      break;
    case MaskColor::Green:
      m_green_mask_sound->set_fade(1.0f, 0.0f, MaskAudioFade);
      break;

    default:
      // nothing to do
      break;
    }

    switch (new_mask_color) {
    case MaskColor::Red:
      m_red_mask_sound->set_volume(1.0f);
      m_red_mask_sound->set_fade(0.0f, 1.0f, MaskAudioFade);
      break;
    case MaskColor::Blue:
      m_blue_mask_sound->set_volume(1.0f);
      m_blue_mask_sound->set_fade(0.0f, 1.0f, MaskAudioFade);
      break;
    case MaskColor::Green:
      m_green_mask_sound->set_volume(1.0f);
      m_green_mask_sound->set_fade(0.0f, 1.0f, MaskAudioFade);
      break;

    default:
      // nothing to do
      break;
    }

    m_mask_color = new_mask_color;
  }

}
