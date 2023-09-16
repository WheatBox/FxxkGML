#pragma once

#include "basic.h"

namespace fgm {

	int delta_time_get();

	std::string game_save_id_get();
	std::string game_display_name_get();
	std::string game_project_name_get();
	void game_end(int return_code = 0);
	void game_restart();
	void game_change(const char * working_directory, const char * launch_parameters);
	void game_change(const std::string & working_directory, const std::string & launch_parameters);
	void game_load_buffer(int buffer_id);
	void game_save_buffer(int buffer_id);
	void game_set_speed(int speed, int type);
	int game_get_speed(int type);

	void highscore_add(const char * str, int numb);
	void highscore_add(const std::string & str, int numb);
	std::string highscore_name(int place);
	int highscore_value(int place);
	void highscore_clear();

	asset cursor_sprite_get();
	void cursor_sprite_set(asset spr);

	asset asset_get_index(const char * name);
	asset asset_get_index(const std::string & name);
	int asset_get_type(const char * name);
	int asset_get_type(const std::string & name);

}