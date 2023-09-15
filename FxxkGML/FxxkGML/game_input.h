#pragma once

#include "basic.h"

namespace fgm {

	void io_clear();
	bool keyboard_check(vkey_t key);
	bool keyboard_check_pressed(vkey_t key);
	bool keyboard_check_released(vkey_t key);
	bool keyboard_check_direct(vkey_t key);
	void keyboard_clear(vkey_t key);
	void keyboard_set_map(vkey_t key1, vkey_t key2);
	vkey_t keyboard_get_map();
	void keyboard_unset_map();
	void keyboard_set_numlock(bool on);
	bool keyboard_get_numlock();
	void keyboard_key_press(vkey_t key);
	void keyboard_key_release(vkey_t key);
	vkey_t keyboard_key_get();
	vkey_t keyboard_lastkey_get();
	std::string keyboard_lastchar_get();
	std::string keyboard_string_get();
	void keyboard_key_set(vkey_t key);
	void keyboard_lastkey_set(vkey_t key);
	void keyboard_lastchar_set(const char * str);
	void keyboard_string_set(const char * str);
	void keyboard_lastchar_set(const std::string & str);
	void keyboard_string_set(const std::string & str);

	int mouse_button_get();
	void mouse_button_set(int _mb_xxx);
	bool mouse_check_button(int _mb_xxx);
	bool mouse_check_button_pressed(int _mb_xxx);
	bool mouse_check_button_released(int _mb_xxx);
	bool mouse_clear(int _mb_xxx);
	int mouse_lastbutton_get();
	void mouse_lastbutton_set(int _mb_xxx);
	bool mouse_wheel_up();
	bool mouse_wheel_down();
	double mouse_x_get();
	double mouse_y_get();
	vec2 mouse_pos_get();

	double window_mouse_get_x();
	double window_mouse_get_y();
	vec2 window_mouse_get_pos();
	void window_mouse_set(double x, double y);
	void window_mouse_set(const vec2 & xy);
	double window_view_mouse_get_x(int view_id);
	double window_view_mouse_get_y(int view_id);
	vec2 window_view_mouse_get_pos(int view_id);
	double window_views_mouse_get_x();
	double window_views_mouse_get_y();
	vec2 window_views_mouse_get_pos();

	bool device_mouse_check_button(int device, int _mb_xxx);
	bool device_mouse_check_button_pressed(int device, int _mb_xxx);
	bool device_mouse_check_button_released(int device, int _mb_xxx);
	bool device_mouse_dbclick_enable(bool enable);
	double device_mouse_x(int device);
	double device_mouse_y(int device);
	vec2 device_mouse_pos(int device);
	double device_mouse_raw_x(int device);
	double device_mouse_raw_y(int device);
	vec2 device_mouse_raw_pos(int device);
	double device_mouse_x_to_gui(int device);
	double device_mouse_y_to_gui(int device);
	vec2 device_mouse_pos_to_gui(int device);
	bool device_is_keypad_open();
	double device_get_tilt_x();
	double device_get_tilt_y();
	double device_get_tilt_z();

}
