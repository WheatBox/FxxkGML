#pragma once

#include "basic.h"

namespace fgm {

	bool sprite_exists(asset index);
	std::string sprite_get_name(asset index);
	int sprite_get_number(asset index);
	int sprite_get_speed(asset index);
	int sprite_get_speed_type(asset index);
	double sprite_get_width(asset index);
	double sprite_get_height(asset index);
	vec2 sprite_get_size(asset index);
	double sprite_get_xoffset(asset index);
	double sprite_get_yoffset(asset index);
	vec2 sprite_get_offset(asset index);
	double sprite_get_bbox_bottom(asset index);
	double sprite_get_bbox_left(asset index);
	double sprite_get_bbox_right(asset index);
	double sprite_get_bbox_top(asset index);
	rect sprite_get_bbox(asset index);
	int sprite_get_bbox_mode(asset index);
	
	void sprite_collision_mask(asset ind, bool sepmasks, int bboxmode, const rect & bboxrect, int kind, int tolerance);
	void sprite_collision_mask(asset ind, bool sepmasks, int bboxmode, double bbleft, double bbtop, double bbright, double bbbottom, int kind, int tolerance);
	void sprite_set_offset(asset ind, const vec2 & off);
	void sprite_set_offset(asset ind, double xoff, double yoff);
	void sprite_set_bbox_mode(asset ind, int mode);
	void sprite_set_bbox(asset ind, const rect & bboxrect);
	void sprite_set_bbox(asset ind, double left, double top, double right, double bottom);
	int sprite_set_speed(asset index, int speed, int type);
	
	asset sprite_add(const std::string & fname, int imgnumb, bool removeback, bool smooth, const vec2 & orig);
	asset sprite_add(const std::string & fname, int imgnumb, bool removeback, bool smooth, double xorig, double yorig);
	void sprite_delete(asset index);
	void sprite_replace(asset ind, const std::string & fname, int imgnumb, bool removeback, bool smooth, const vec2 & orig);
	void sprite_replace(asset ind, const std::string & fname, int imgnumb, bool removeback, bool smooth, double xorig, double yorig);
	asset sprite_duplicate(asset index);
	void sprite_assign(asset index, asset sprite);
	void sprite_merge(asset ind1, asset ind2);
	void sprite_set_alpha_from_sprite(asset ind, asset spr);
	asset sprite_create_from_surface(asset surfindex, const vec2 & xy, const vec2 & wh, bool removeback, bool smooth, const vec2 & orig);
	asset sprite_create_from_surface(asset surfindex, double x, double y, double w, double h, bool removeback, bool smooth, double xorig, double yorig);
	void sprite_add_from_surface(asset sprindex, asset surfindex, const vec2 & xy, const vec2 & wh, bool removeback, bool smooth);
	void sprite_add_from_surface(asset sprindex, asset surfindex, double x, double y, double w, double h, bool removeback, bool smooth);
	
	void sprite_save(asset ind, int subimg, const std::string & fname);
	void sprite_save_strip(asset ind, const std::string & filename);
	
	int sprite_prefetch(asset ind);
	int sprite_flush(asset ind);
	
}
