#include "audio.h"

namespace fgm {

	bool audio_exists(sndins_id id_or_asset) {
		__basic(__FuncId::audio_exists, id_or_asset);
		return g_funcres.m_real;
	}

	std::string audio_get_name(sndins_id id_or_asset) {
		__basic(__FuncId::audio_get_name, id_or_asset);
		return g_funcres.m_string;
	}
	
	int audio_get_type(sndins_id id_or_asset) {
		__basic(__FuncId::audio_get_type, id_or_asset);
		return g_funcres.m_real;
	}
	
	double audio_sound_length(sndins_id id_or_asset) {
		__basic(__FuncId::audio_sound_length, id_or_asset);
		return g_funcres.m_real;
	}
	
	bool audio_sound_is_playable(sndins_id id_or_asset) {
		__basic(__FuncId::audio_sound_is_playable, id_or_asset);
		return g_funcres.m_real;
	}

	sndins_id audio_play_sound(asset index, int priority, bool loop) {
		__basic(__FuncId::audio_play_sound, index, priority, loop);
		return g_funcres.m_real;
	}
	
	sndins_id audio_play_sound__fullargs(asset index, int priority, bool loop, double gain, double offset, double pitch, int listener_mask) {
		__basic(__FuncId::audio_play_sound__fullargs, index, priority, loop, gain, offset, pitch, listener_mask);
		return g_funcres.m_real;
	}
	
	// audio_play_sound_ext
	
	sndins_id audio_play_sound_at(asset index, double x, double y, double z, double falloff_ref, double falloff_max, double falloff_factor, bool loop, int priority) {
		__basic(__FuncId::audio_play_sound_at, index, x, y, z, falloff_ref, falloff_max, falloff_factor, loop, priority);
		return g_funcres.m_real;
	}
	
	sndins_id audio_play_sound_at__fullargs(asset index, double x, double y, double z, double falloff_ref, double falloff_max, double falloff_factor, bool loop, int priority, double gain, double offset, double pitch, int listener_mask) {
		__basic(__FuncId::audio_play_sound_at__fullargs, index, x, y, z, falloff_ref, falloff_max, falloff_factor, loop, priority, gain, offset, pitch, listener_mask);
		return g_funcres.m_real;
	}
	
	void audio_pause_sound(sndins_id id_or_asset) {
		__basic(__FuncId::audio_pause_sound, id_or_asset);
	}
	
	void audio_pause_all() {
		__basic(__FuncId::audio_pause_all);
	}
	
	void audio_resume_sound(sndins_id id_or_asset) {
		__basic(__FuncId::audio_resume_sound, id_or_asset);
	}
	
	void audio_resume_all() {
		__basic(__FuncId::audio_resume_all);
	}
	
	void audio_stop_sound(sndins_id id_or_asset) {
		__basic(__FuncId::audio_stop_sound, id_or_asset);
	}
	
	void audio_stop_all() {
		__basic(__FuncId::audio_stop_all);
	}
	
	bool audio_is_playing(sndins_id id_or_asset) {
		__basic(__FuncId::audio_is_playing, id_or_asset);
		return g_funcres.m_real;
	}
	
	bool audio_is_paused(sndins_id id_or_asset) {
		__basic(__FuncId::audio_is_paused, id_or_asset);
		return g_funcres.m_real;
	}

	asset audio_create_stream(const std::string & filename) {
		__basic(__FuncId::audio_create_stream, filename);
		return g_funcres.m_real;
	}

	void audio_destroy_stream(asset stream_sound_id) {
		__basic(__FuncId::audio_destroy_stream, stream_sound_id);
	}
	
}
