#pragma once

#include "basic.h"

namespace fgm {

	bool audio_exists(sndins_id id_or_asset);
	std::string audio_get_name(sndins_id id_or_asset);
	int audio_get_type(sndins_id id_or_asset);
	double audio_sound_length(sndins_id id_or_asset);
	bool audio_sound_is_playable(sndins_id id_or_asset);

	sndins_id audio_play_sound(asset index, int priority, bool loop);
	sndins_id audio_play_sound__fullargs(asset index, int priority, bool loop, double gain, double offset = 0.0, double pitch = 1.0, int listener_mask = 0);
	// audio_play_sound_ext
	sndins_id audio_play_sound_at(asset index, double x, double y, double z, double falloff_ref, double falloff_max, double falloff_factor, bool loop, int priority);
	sndins_id audio_play_sound_at__fullargs(asset index, double x, double y, double z, double falloff_ref, double falloff_max, double falloff_factor, bool loop, int priority, double gain, double offset = 0.0, double pitch = 1.0, int listener_mask = 0);
	void audio_pause_sound(sndins_id id_or_asset);
	void audio_pause_all();
	void audio_resume_sound(sndins_id id_or_asset);
	void audio_resume_all();
	void audio_stop_sound(sndins_id id_or_asset);
	void audio_stop_all();
	bool audio_is_playing(sndins_id id_or_asset);
	bool audio_is_paused(sndins_id id_or_asset);

	asset audio_create_stream(const std::string & filename);
	void audio_destroy_stream(asset stream_sound_id);

}
