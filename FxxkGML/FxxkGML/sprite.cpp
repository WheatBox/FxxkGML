#include "sprite.h"

namespace fgm {

	bool sprite_exists(asset index) {
		__basic(__FuncId::sprite_exists, index);
		return g_funcres.m_real;
	}

	std::string sprite_get_name(asset index) {
		__basic(__FuncId::sprite_get_name, index);
		return g_funcres.m_string;
	}
	
	int sprite_get_number(asset index) {
		__basic(__FuncId::sprite_get_number, index);
		return g_funcres.m_real;
	}
	
	int sprite_get_speed(asset index) {
		__basic(__FuncId::sprite_get_speed, index);
		return g_funcres.m_real;
	}

	int sprite_get_speed_type(asset index) {
		__basic(__FuncId::sprite_get_speed_type, index);
		return g_funcres.m_real;
	}
	
	double sprite_get_width(asset index) {
		__basic(__FuncId::sprite_get_width, index);
		return g_funcres.m_real;
	}
	
	double sprite_get_height(asset index) {
		__basic(__FuncId::sprite_get_height, index);
		return g_funcres.m_real;
	}
	
	vec2 sprite_get_size(asset index) {
		__basic(__FuncId::sprite_get_size, index);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}
	
	double sprite_get_xoffset(asset index) {
		__basic(__FuncId::sprite_get_xoffset, index);
		return g_funcres.m_real;
	}
	
	double sprite_get_yoffset(asset index) {
		__basic(__FuncId::sprite_get_yoffset, index);
		return g_funcres.m_real;
	}
	
	vec2 sprite_get_offset(asset index) {
		__basic(__FuncId::sprite_get_offset, index);
		return { g_otherress[0].m_real, g_otherress[1].m_real };
	}
	
	double sprite_get_bbox_bottom(asset index) {
		__basic(__FuncId::sprite_get_bbox_bottom, index);
		return g_funcres.m_real;
	}
	
	double sprite_get_bbox_left(asset index) {
		__basic(__FuncId::sprite_get_bbox_left, index);
		return g_funcres.m_real;
	}
	
	double sprite_get_bbox_right(asset index) {
		__basic(__FuncId::sprite_get_bbox_right, index);
		return g_funcres.m_real;
	}
	
	double sprite_get_bbox_top(asset index) {
		__basic(__FuncId::sprite_get_bbox_top, index);
		return g_funcres.m_real;
	}
	
	rect sprite_get_bbox(asset index) {
		__basic(__FuncId::sprite_get_bbox, index);
		return { g_otherress[0].m_real, g_otherress[1].m_real, g_otherress[2].m_real, g_otherress[3].m_real };
	}
	
	int sprite_get_bbox_mode(asset index) {
		__basic(__FuncId::sprite_get_bbox_mode, index);
		return g_funcres.m_real;
	}
	
	void sprite_collision_mask(asset ind, bool sepmasks, int bboxmode, const rect & bboxrect, int kind, int tolerance) {
		__basic(__FuncId::sprite_collision_mask, ind, sepmasks, bboxmode, bboxrect.m_left, bboxrect.m_top, bboxrect.m_right, bboxrect.m_bottom, kind, tolerance);
	}
	
	void sprite_collision_mask(asset ind, bool sepmasks, int bboxmode, double bbleft, double bbtop, double bbright, double bbbottom, int kind, int tolerance) {
		__basic(__FuncId::sprite_collision_mask, ind, sepmasks, bboxmode, bbleft, bbtop, bbright, bbbottom, kind, tolerance);
	}
	
	void sprite_set_offset(asset ind, const vec2 & off) {
		__basic(__FuncId::sprite_set_offset, ind, off.m_x, off.m_y);
	}
	
	void sprite_set_offset(asset ind, double xoff, double yoff) {
		__basic(__FuncId::sprite_set_offset, ind, xoff, yoff);
	}
	
	void sprite_set_bbox_mode(asset ind, int mode) {
		__basic(__FuncId::sprite_set_bbox_mode, ind, mode);
	}
	
	void sprite_set_bbox(asset ind, const rect & bboxrect) {
		__basic(__FuncId::sprite_set_bbox, ind, bboxrect.m_left, bboxrect.m_top, bboxrect.m_right, bboxrect.m_bottom);
	}
	
	void sprite_set_bbox(asset ind, double left, double top, double right, double bottom) {
		__basic(__FuncId::sprite_set_bbox, ind, left, top, right, bottom);
	}
	
	int sprite_set_speed(asset index, int speed, int type) {
		__basic(__FuncId::sprite_set_speed, index, speed, type);
		return g_funcres.m_real;
	}
	
	asset sprite_add(const std::string & fname, int imgnumb, bool removeback, bool smooth, const vec2 & orig) {
		__basic(__FuncId::sprite_add, fname, imgnumb, removeback, smooth, orig.m_x, orig.m_y);
		return g_funcres.m_real;
	}
	
	asset sprite_add(const std::string & fname, int imgnumb, bool removeback, bool smooth, double xorig, double yorig) {
		__basic(__FuncId::sprite_add, fname, imgnumb, removeback, smooth, xorig, yorig);
		return g_funcres.m_real;
	}
	
	void sprite_delete(asset index) {
		__basic(__FuncId::sprite_delete, index);
	}
	
	void sprite_replace(asset ind, const std::string & fname, int imgnumb, bool removeback, bool smooth, const vec2 & orig) {
		__basic(__FuncId::sprite_replace, ind, imgnumb, removeback, smooth, orig.m_x, orig.m_y);
	}
	
	void sprite_replace(asset ind, const std::string & fname, int imgnumb, bool removeback, bool smooth, double xorig, double yorig) {
		__basic(__FuncId::sprite_replace, ind, imgnumb, removeback, smooth, xorig, yorig);
	}

	asset sprite_duplicate(asset index) {
		__basic(__FuncId::sprite_duplicate, index);
		return g_funcres.m_real;
	}

	void sprite_assign(asset index, asset sprite) {
		__basic(__FuncId::sprite_assign, index, sprite);
	}
	
	void sprite_merge(asset ind1, asset ind2) {
		__basic(__FuncId::sprite_merge, ind1, ind2);
	}
	
	void sprite_set_alpha_from_sprite(asset ind, asset spr) {
		__basic(__FuncId::sprite_set_alpha_from_sprite, ind, spr);
	}
	
	asset sprite_create_from_surface(asset surfindex, const vec2 & xy, const vec2 & wh, bool removeback, bool smooth, const vec2 & orig) {
		__basic(__FuncId::sprite_create_from_surface, surfindex, xy.m_x, xy.m_y, wh.m_x, wh.m_y, removeback, smooth, orig.m_x, orig.m_y);
		return g_funcres.m_real;
	}
	
	asset sprite_create_from_surface(asset surfindex, double x, double y, double w, double h, bool removeback, bool smooth, double xorig, double yorig) {
		__basic(__FuncId::sprite_create_from_surface, surfindex, x, y, w, h, removeback, smooth, xorig, yorig);
		return g_funcres.m_real;
	}
	
	void sprite_add_from_surface(asset sprindex, asset surfindex, const vec2 & xy, const vec2 & wh, bool removeback, bool smooth) {
		__basic(__FuncId::sprite_add_from_surface, sprindex, surfindex, xy.m_x, xy.m_y, wh.m_x, wh.m_y, removeback, smooth);
	}
	
	void sprite_add_from_surface(asset sprindex, asset surfindex, double x, double y, double w, double h, bool removeback, bool smooth) {
		__basic(__FuncId::sprite_add_from_surface, sprindex, surfindex, x, y, w, h, removeback, smooth);
	}
	
	void sprite_save(asset ind, int subimg, const std::string & fname) {
		__basic(__FuncId::sprite_save, subimg, fname);
	}

	void sprite_save_strip(asset ind, const std::string & filename) {
		__basic(__FuncId::sprite_save_strip, ind, filename);
	}
	
	int sprite_prefetch(asset ind) {
		__basic(__FuncId::sprite_prefetch, ind);
		return g_funcres.m_real;
	}

	int sprite_flush(asset ind) {
		__basic(__FuncId::sprite_flush, ind);
		return g_funcres.m_real;
	}
	
}
