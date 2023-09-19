#pragma once

#include "basic.h"

namespace fgm {

	bool font_exists(asset ind);
	std::string font_get_name(asset ind);
	std::string font_get_fontname(asset ind);
	int font_get_first(asset ind);
	int font_get_last(asset ind);
	bool font_get_italic(asset ind);
	bool font_get_bold(asset ind);
	double font_get_size(asset ind);

	asset font_add(const std::string & name, double size, bool bold, bool italic, int first, int last);
	asset font_add_sprite(asset spr, int first, bool prop, int sep);
	asset font_add_sprite_ext(asset spr, const std::string & string_map, bool prop, int sep);
	void font_replace_sprite(asset ind, asset spr, int first, bool prop, int sep);
	void font_replace_sprite_ext(asset ind, asset spr, const std::string & string_map, bool prop, int sep);
	void font_delete(asset ind);

	int font_texture_page_size_get();
	void font_texture_page_size_set(int size);
	void font_set_cache_size(asset ind, int max);
	void font_add_enable_aa(bool enable);
	bool font_add_get_enable_aa();

	void font_enable_sdf(asset ind, bool enable);
	bool font_get_sdf_enabled(asset ind);
	void font_sdf_spread(asset ind, int spread);
	int font_get_sdf_spread(asset ind);
}
