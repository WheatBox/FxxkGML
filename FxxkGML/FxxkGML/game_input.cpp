#include "game_input.h"

namespace fgm {

	void io_clear() {
		__basic(__FuncId::io_clear);
	}

	bool keyboard_check(vkey_t key) {
		__basic(__FuncId::keyboard_check, key);
		
		return g_funcres.m_real;
	}

	bool keyboard_check_pressed(vkey_t key) {
		__basic(__FuncId::keyboard_check_pressed, key);
		return g_funcres.m_real;
	}

	bool keyboard_check_released(vkey_t key) {
		__basic(__FuncId::keyboard_check_released, key);
		return g_funcres.m_real;
	}

	bool keyboard_check_direct(vkey_t key) {
		__basic(__FuncId::keyboard_check_direct, key);
		return g_funcres.m_real;
	}

	void keyboard_clear(vkey_t key) {
		__basic(__FuncId::keyboard_clear, key);
	}

	void keyboard_set_map(vkey_t key1, vkey_t key2) {
		__basic(__FuncId::keyboard_set_map, key1, key2);
	}

	vkey_t keyboard_get_map() {
		__basic(__FuncId::keyboard_get_map);
		return g_funcres.m_real;
	}

	void keyboard_unset_map() {
		__basic(__FuncId::keyboard_unset_map);
	}

	void keyboard_set_numlock(bool on) {
		__basic(__FuncId::keyboard_set_numlock, on);
	}

	bool keyboard_get_numlock() {
		__basic(__FuncId::keyboard_get_numlock);
		return g_funcres.m_real;
	}

	void keyboard_key_press(vkey_t key) {
		__basic(__FuncId::keyboard_key_press, key);
	}

	void keyboard_key_release(vkey_t key) {
		__basic(__FuncId::keyboard_key_release, key);
	}

	vkey_t keyboard_key_get() {
		__basic(__FuncId::keyboard_key_get);
		return g_funcres.m_real;
	}

	vkey_t keyboard_lastkey_get() {
		__basic(__FuncId::keyboard_lastkey_get);
		return g_funcres.m_real;
	}

	std::string keyboard_lastchar_get() {
		__basic(__FuncId::keyboard_lastchar_get);
		return g_funcres.m_string;
	}

	std::string keyboard_string_get() {
		__basic(__FuncId::keyboard_string_get);
		return g_funcres.m_string;
	}

	void keyboard_key_set(vkey_t key) {
		__basic(__FuncId::keyboard_key_set, key);
	}

	void keyboard_lastkey_set(vkey_t key) {
		__basic(__FuncId::keyboard_lastkey_set, key);
	}

	void keyboard_lastchar_set(const char * str) {
		__basic(__FuncId::keyboard_lastchar_set, str);
	}
	
	void keyboard_string_set(const char * str) {
		__basic(__FuncId::keyboard_string_set, str);
	}

	void keyboard_lastchar_set(const std::string & str) {
		__basic(__FuncId::keyboard_lastchar_set, str);
	}

	void keyboard_string_set(const std::string & str) {
		__basic(__FuncId::keyboard_string_set, str);
	}

	int mouse_button_get() {
		__basic(__FuncId::mouse_button_get);
		return g_funcres.m_real;
	}
	
	void mouse_button_set(int _mb_xxx) {
		__basic(__FuncId::mouse_button_set, _mb_xxx);
	}
	
	bool mouse_check_button(int _mb_xxx) {
		__basic(__FuncId::mouse_check_button, _mb_xxx);
		return g_funcres.m_real;
	}
	
	bool mouse_check_button_pressed(int _mb_xxx) {
		__basic(__FuncId::mouse_check_button_pressed, _mb_xxx);
		return g_funcres.m_real;
	}
	
	bool mouse_check_button_released(int _mb_xxx) {
		__basic(__FuncId::mouse_check_button_released, _mb_xxx);
		return g_funcres.m_real;
	}
	
	bool mouse_clear(int _mb_xxx) {
		__basic(__FuncId::mouse_clear, _mb_xxx);
		return g_funcres.m_real;
	}
	
	int mouse_lastbutton_get() {
		__basic(__FuncId::mouse_lastbutton_get);
		return g_funcres.m_real;
	}
	
	void mouse_lastbutton_set(int _mb_xxx) {
		__basic(__FuncId::mouse_lastbutton_set, _mb_xxx);
	}
	
	bool mouse_wheel_up() {
		__basic(__FuncId::mouse_wheel_up);
		return g_funcres.m_real;
	}
	
	bool mouse_wheel_down() {
		__basic(__FuncId::mouse_wheel_down);
		return g_funcres.m_real;
	}
	
	double mouse_x_get() {
		__basic(__FuncId::mouse_x_get);
		return g_funcres.m_real;
	}
	
	double mouse_y_get() {
		__basic(__FuncId::mouse_y_get);
		return g_funcres.m_real;
	}
	
	vec2 mouse_pos_get() {
		__basic(__FuncId::mouse_pos_get);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}

	double window_mouse_get_x() {
		__basic(__FuncId::window_mouse_get_x);
		return g_funcres.m_real;
	}
	
	double window_mouse_get_y() {
		__basic(__FuncId::window_mouse_get_y);
		return g_funcres.m_real;
	}
	
	vec2 window_mouse_get_pos() {
		__basic(__FuncId::window_mouse_get_pos);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}
	
	void window_mouse_set(double x, double y) {
		__basic(__FuncId::window_mouse_set, x, y);
	}
	
	void window_mouse_set(const vec2 & xy) {
		__basic(__FuncId::window_mouse_set, xy.m_x, xy.m_y);
	}
	
	double window_view_mouse_get_x(int view_id) {
		__basic(__FuncId::window_view_mouse_get_x, view_id);
		return g_funcres.m_real;
	}
	
	double window_view_mouse_get_y(int view_id) {
		__basic(__FuncId::window_view_mouse_get_y, view_id);
		return g_funcres.m_real;
	}
	
	vec2 window_view_mouse_get_pos(int view_id) {
		__basic(__FuncId::window_view_mouse_get_pos, view_id);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}
	
	double window_views_mouse_get_x() {
		__basic(__FuncId::window_views_mouse_get_x);
		return g_funcres.m_real;
	}
	
	double window_views_mouse_get_y() {
		__basic(__FuncId::window_views_mouse_get_y);
		return g_funcres.m_real;
	}
	
	vec2 window_views_mouse_get_pos() {
		__basic(__FuncId::window_views_mouse_get_pos);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}

	bool device_mouse_check_button(int device, int _mb_xxx) {
		__basic(__FuncId::device_mouse_check_button, device, _mb_xxx);
		return g_funcres.m_real;
	}

	bool device_mouse_check_button_pressed(int device, int _mb_xxx) {
		__basic(__FuncId::device_mouse_check_button_pressed, device, _mb_xxx);
		return g_funcres.m_real;
	}
	
	bool device_mouse_check_button_released(int device, int _mb_xxx) {
		__basic(__FuncId::device_mouse_check_button_released, device, _mb_xxx);
		return g_funcres.m_real;
	}
	
	bool device_mouse_dbclick_enable(bool enable) {
		__basic(__FuncId::device_mouse_dbclick_enable, enable);
		return g_funcres.m_real;
	}

	double device_mouse_x(int device) {
		__basic(__FuncId::device_mouse_x, device);
		return g_funcres.m_real;
	}
	
	double device_mouse_y(int device) {
		__basic(__FuncId::device_mouse_y, device);
		return g_funcres.m_real;
	}
	
	vec2 device_mouse_pos(int device) {
		__basic(__FuncId::device_mouse_pos, device);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}
	
	double device_mouse_raw_x(int device) {
		__basic(__FuncId::device_mouse_raw_x, device);
		return g_funcres.m_real;
	}

	double device_mouse_raw_y(int device) {
		__basic(__FuncId::device_mouse_raw_y, device);
		return g_funcres.m_real;
	}
	
	vec2 device_mouse_raw_pos(int device) {
		__basic(__FuncId::device_mouse_raw_pos, device);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}
	
	double device_mouse_x_to_gui(int device) {
		__basic(__FuncId::device_mouse_x_to_gui, device);
		return g_funcres.m_real;
	}
	
	double device_mouse_y_to_gui(int device) {
		__basic(__FuncId::device_mouse_y_to_gui, device);
		return g_funcres.m_real;
	}
	
	vec2 device_mouse_pos_to_gui(int device) {
		__basic(__FuncId::device_mouse_pos_to_gui, device);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}
	
	bool device_is_keypad_open() {
		__basic(__FuncId::device_is_keypad_open);
		return g_funcres.m_real;
	}
	
	double device_get_tilt_x() {
		__basic(__FuncId::device_get_tilt_x);
		return g_funcres.m_real;
	}
	
	double device_get_tilt_y() {
		__basic(__FuncId::device_get_tilt_y);
		return g_funcres.m_real;
	}
	
	double device_get_tilt_z() {
		__basic(__FuncId::device_get_tilt_z);
		return g_funcres.m_real;
	}

}
