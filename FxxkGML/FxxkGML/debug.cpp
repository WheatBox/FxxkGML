#include "debug.h"

namespace fgm {
	
	void show_error(const char * str, bool abort) {
		__basic(__FuncId::show_error, str, abort);
	}
	
	void show_error(const std::string & str, bool abort) {
		__basic(__FuncId::show_error, str, abort);
	}

	void show_message(const char * str) {
		__basic(__FuncId::show_message, str);
	}
	
	void show_message(const std::string & str) {
		__basic(__FuncId::show_message, str);
	}
	
	bool show_question(const char * str) {
		__basic(__FuncId::show_question, str);
		return g_funcres.m_real;
	}
	
	bool show_question(const std::string & str) {
		__basic(__FuncId::show_question, str);
		return g_funcres.m_real;
	}
	
	void show_debug_message(const char * str) {
		__basic(__FuncId::show_debug_message, str);
	}
	
	void show_debug_message(const std::string & str) {
		__basic(__FuncId::show_debug_message, str);
	}
	
	bool code_is_compiled() {
		__basic(__FuncId::code_is_compiled);
		return g_funcres.m_real;
	}
	
	int fps_get() {
		__basic(__FuncId::fps_get);
		return g_funcres.m_real;
	}
	
	int fps_real_get() {
		__basic(__FuncId::fps_real_get);
		return g_funcres.m_real;
	}
	
	void show_debug_overlay(bool enable, bool minimised, double scale, double alpha) {
		__basic(__FuncId::show_debug_overlay, enable, minimised, scale, alpha);
	}
	
	void show_debug_log(bool enable) {
		__basic(__FuncId::show_debug_log, enable);
	}
	
	bool is_debug_overlay_open() {
		__basic(__FuncId::is_debug_overlay_open);
		return g_funcres.m_real;
	}

}