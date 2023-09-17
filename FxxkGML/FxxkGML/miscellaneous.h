#pragma once

#include "basic.h"

namespace fgm {

	void FxxkGML_Init(ins_id instance_id, const char * _dll_filename);
	void FxxkGML_Init(ins_id instance_id, const std::string & _dll_filename);
	void FxxkGML_Main(ins_id instance_id);
	void FxxkGML_Assistant(ins_id instance_id, int assistantIndex);
	void FxxkGML_GetVersion(ins_id instance_id, int * p_dest_left, int * p_dest_mid, int * p_dest_right);

	void FxxkGML_Init(const instance & ins, const char * _dll_filename);
	void FxxkGML_Init(const instance & ins, const std::string & _dll_filename);
	void FxxkGML_Main(const instance & ins);
	void FxxkGML_Assistant(const instance & ins, int assistantIndex);
	void FxxkGML_GetVersion(const instance & ins, int * p_dest_left, int * p_dest_mid, int * p_dest_right);

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

	bool variable_instance_exists(ins_id instance_id, const std::string & name);
	double variable_instance_get_real(ins_id instance_id, const std::string & name);
	std::string variable_instance_get_string(ins_id instance_id, const std::string & name);
	void variable_instance_set_real(ins_id instance_id, const std::string & name, double val);
	void variable_instance_set_string(ins_id instance_id, const std::string & name, const std::string & val);
	bool variable_global_exists(const std::string & name);
	double variable_global_get_real(const std::string & name);
	std::string variable_global_get_string(const std::string & name);
	void variable_global_set_real(const std::string & name, double val);
	void variable_global_set_string(const std::string & name, const std::string & val);

}