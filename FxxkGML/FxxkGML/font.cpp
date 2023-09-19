#include "font.h"

namespace fgm {

	bool font_exists(asset ind) {
		__basic(__FuncId::font_exists, ind);
		return g_funcres.m_real;
	}
	
	std::string font_get_name(asset ind) {
		__basic(__FuncId::font_get_name, ind);
		return g_funcres.m_string;
	}
	
	std::string font_get_fontname(asset ind) {
		__basic(__FuncId::font_get_fontname, ind);
		return g_funcres.m_string;
	}
	
	int font_get_first(asset ind) {
		__basic(__FuncId::font_get_first, ind);
		return g_funcres.m_real;
	}
	
	int font_get_last(asset ind) {
		__basic(__FuncId::font_get_last, ind);
		return g_funcres.m_real;
	}
	
	bool font_get_italic(asset ind) {
		__basic(__FuncId::font_get_italic, ind);
		return g_funcres.m_real;
	}
	
	bool font_get_bold(asset ind) {
		__basic(__FuncId::font_get_bold, ind);
		return g_funcres.m_real;
	}
	
	double font_get_size(asset ind) {
		__basic(__FuncId::font_get_size, ind);
		return g_funcres.m_real;
	}

	asset font_add(const std::string & name, double size, bool bold, bool italic, int first, int last) {
		__basic(__FuncId::font_add, name, size, bold, italic, first, last);
		return g_funcres.m_real;
	}
	
	asset font_add_sprite(asset spr, int first, bool prop, int sep) {
		__basic(__FuncId::font_add_sprite, spr, first, prop, sep);
		return g_funcres.m_real;
	}
	
	asset font_add_sprite_ext(asset spr, const std::string & string_map, bool prop, int sep) {
		__basic(__FuncId::font_add_sprite_ext, spr, string_map, prop, sep);
		return g_funcres.m_real;
	}
	
	void font_replace_sprite(asset ind, asset spr, int first, bool prop, int sep) {
		__basic(__FuncId::font_replace_sprite, ind, spr, first, prop, sep);
	}
	
	void font_replace_sprite_ext(asset ind, asset spr, const std::string & string_map, bool prop, int sep) {
		__basic(__FuncId::font_replace_sprite_ext, ind, spr, string_map, prop, sep);
	}
	
	void font_delete(asset ind) {
		__basic(__FuncId::font_delete, ind);
	}

	int font_texture_page_size_get() {
		__basic(__FuncId::font_texture_page_size_get);
		return g_funcres.m_real;
	}
	
	void font_texture_page_size_set(int size) {
		__basic(__FuncId::font_texture_page_size_set, size);
	}
	
	void font_set_cache_size(asset ind, int max) {
		__basic(__FuncId::font_set_cache_size, ind, max);
	}
	
	void font_add_enable_aa(bool enable) {
		__basic(__FuncId::font_add_enable_aa, enable);
	}
	
	bool font_add_get_enable_aa() {
		__basic(__FuncId::font_add_get_enable_aa);
		return g_funcres.m_real;
	}

	void font_enable_sdf(asset ind, bool enable) {
		__basic(__FuncId::font_enable_sdf, ind, enable);
	}
	
	bool font_get_sdf_enabled(asset ind) {
		__basic(__FuncId::font_get_sdf_enabled, ind);
		return g_funcres.m_real;
	}
	
	void font_sdf_spread(asset ind, int spread) {
		__basic(__FuncId::font_sdf_spread, ind, spread);
	}
	
	int font_get_sdf_spread(asset ind) {
		__basic(__FuncId::font_get_sdf_spread, ind);
		return g_funcres.m_real;
	}

}
