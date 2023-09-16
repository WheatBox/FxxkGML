#include "miscellaneous.h"

namespace fgm {

	int delta_time_get() {
		__basic(__FuncId::delta_time_get);
		return g_funcres.m_real;
	}

	std::string game_save_id_get() {
		__basic(__FuncId::game_save_id_get);
		return g_funcres.m_string;
	}

	std::string game_display_name_get() {
		__basic(__FuncId::game_display_name_get);
		return g_funcres.m_string;
	}

	std::string game_project_name_get() {
		__basic(__FuncId::game_project_name_get);
		return g_funcres.m_string;
	}
	
	void game_end(int return_code) {
		__basic(__FuncId::game_end, return_code);
	}

	void game_restart() {
		__basic(__FuncId::game_restart);
	}

	void game_change(const char * working_directory, const char * launch_parameters) {
		__basic(__FuncId::game_change, working_directory, launch_parameters);
	}

	void game_change(const std::string & working_directory, const std::string & launch_parameters) {
		__basic(__FuncId::game_change, working_directory, launch_parameters);
	}
	
	void game_load_buffer(int buffer_id) {
		__basic(__FuncId::game_load_buffer, buffer_id);
	}
	
	void game_save_buffer(int buffer_id) {
		__basic(__FuncId::game_save_buffer, buffer_id);
	}
	
	void game_set_speed(int speed, int type) {
		__basic(__FuncId::game_set_speed, speed, type);
	}
	
	int game_get_speed(int type) {
		__basic(__FuncId::game_get_speed, type);
		return g_funcres.m_real;
	}

	void highscore_add(const char * str, int numb) {
		__basic(__FuncId::highscore_add, str, numb);
	}

	void highscore_add(const std::string & str, int numb) {
		__basic(__FuncId::highscore_add, str, numb);
	}

	std::string highscore_name(int place) {
		__basic(__FuncId::highscore_name, place);
		return g_funcres.m_string;
	}

	int highscore_value(int place) {
		__basic(__FuncId::highscore_value, place);
		return g_funcres.m_real;
	}

	void highscore_clear() {
		__basic(__FuncId::highscore_clear);
	}

	asset cursor_sprite_get() {
		__basic(__FuncId::cursor_sprite_get);
		return g_funcres.m_real;
	}

	void cursor_sprite_set(asset spr) {
		__basic(__FuncId::cursor_sprite_set, spr);
	}

	asset asset_get_index(const char * name) {
		__basic(__FuncId::asset_get_index, name);
		return g_funcres.m_real;
	}

	asset asset_get_index(const std::string & name) {
		__basic(__FuncId::asset_get_index, name);
		return g_funcres.m_real;
	}

	int asset_get_type(const char * name) {
		__basic(__FuncId::asset_get_type, name);
		return g_funcres.m_real;
	}

	int asset_get_type(const std::string & name) {
		__basic(__FuncId::asset_get_type, name);
		return g_funcres.m_real;
	}

	bool variable_instance_exists(ins_id instance_id, const std::string & name) {
		__basic(__FuncId::variable_instance_exists, instance_id, name);
		return g_funcres.m_real;
	}
	
	double variable_instance_get_real(ins_id instance_id, const std::string & name) {
		__basic(__FuncId::variable_instance_get_real, instance_id, name);
		return g_funcres.m_real;
	}
	
	std::string variable_instance_get_string(ins_id instance_id, const std::string & name) {
		__basic(__FuncId::variable_instance_get_string, instance_id, name);
		return g_funcres.m_string;
	}
	
	void variable_instance_set_real(ins_id instance_id, const std::string & name, double val) {
		__basic(__FuncId::variable_instance_set_real, instance_id, name, val);
	}
	
	void variable_instance_set_string(ins_id instance_id, const std::string & name, const std::string & val) {
		__basic(__FuncId::variable_instance_set_string, instance_id, name, val);
	}
	
	bool variable_global_exists(const std::string & name) {
		__basic(__FuncId::variable_global_exists, name);
		return g_funcres.m_real;
	}
	
	double variable_global_get_real(const std::string & name) {
		__basic(__FuncId::variable_global_get_real, name);
		return g_funcres.m_real;
	}
	
	std::string variable_global_get_string(const std::string & name) {
		__basic(__FuncId::variable_global_get_string, name);
		return g_funcres.m_string;
	}
	
	void variable_global_set_real(const std::string & name, double val) {
		__basic(__FuncId::variable_global_set_real, name, val);
	}
	
	void variable_global_set_string(const std::string & name, const std::string & val) {
		__basic(__FuncId::variable_global_set_string, name, val);
	}

}