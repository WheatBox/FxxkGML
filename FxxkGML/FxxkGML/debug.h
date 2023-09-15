#pragma once

#include "basic.h"

namespace fgm {

	void show_error(const char * str, bool abort);
	void show_error(const std::string & str, bool abort);
	void show_message(const char * str);
	void show_message(const std::string & str);
	bool show_question(const char * str);
	bool show_question(const std::string & str);
	void show_debug_message(const char * str);
	void show_debug_message(const std::string & str);
	bool code_is_compiled();
	int fps_get();
	int fps_real_get();
	void show_debug_overlay(bool enable, bool minimised = true, double scale = 1, double alpha = 0.8);
	void show_debug_log(bool enable);
	bool is_debug_overlay_open();

}
