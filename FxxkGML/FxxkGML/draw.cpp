#include "draw.h"

#define FUNC_COLOR_COLOUR(func, after) \
	func##colour after \
	func##color after
#define FUNC_COLOR_COLOUR_EXT(func, ext, after) \
	func##colour##ext after \
	func##color##ext after

namespace fgm {
	
	void draw_enable_drawevent(bool enable) {
		__basic(__FuncId::draw_enable_drawevent, enable);
	}

	void draw_flush() {
		__basic(__FuncId::draw_flush);
	}

	color_bgr draw_getpixel() {
		__basic(__FuncId::draw_getpixel);
		return { static_cast<color_t>(g_funcres.m_real) };
	}

	FUNC_COLOR_COLOUR(color_bgr draw_get_, () {
		__basic(__FuncId::draw_get_colour);
		return { static_cast<color_t>(g_funcres.m_real) };
	});

	double draw_get_alpha() {
		__basic(__FuncId::draw_get_alpha);
		return g_funcres.m_real;
	}

	void draw_clear(const color_bgr & col) {
		__basic(__FuncId::draw_clear, col.get());
	}

	void draw_clear_alpha(const color_bgr & col, double alpha) {
		__basic(__FuncId::draw_clear_alpha, col.get(), alpha);
	}

	void draw_set_alpha(double alpha) {
		__basic(__FuncId::draw_set_alpha, alpha);
	}

	FUNC_COLOR_COLOUR(void draw_set_, (const color_bgr & col) {
		__basic(__FuncId::draw_set_colour, col.get());
	});

	void draw_arrow(const vec2 & xy1, const vec2 & xy2, double size) {
		draw_arrow(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, size);
	}

	void draw_arrow(double x1, double y1, double x2, double y2, double size) {
		__basic(__FuncId::draw_arrow, x1, y1, x2, y2, size);
	}

	void draw_circle(const vec2 & xy, double r, bool outline) {
		draw_circle(xy.m_x, xy.m_y, r, outline);
	}

	void draw_circle(double x, double y, double r, bool outline) {
		__basic(__FuncId::draw_circle, x, y, r, outline);
	}

	FUNC_COLOR_COLOUR(void draw_circle_, (const vec2 & xy, double r, const color_bgr & col1, const color_bgr & col2, bool outline) {
		draw_circle_colour(xy.m_x, xy.m_y, r, col1, col2, outline);
	});

	FUNC_COLOR_COLOUR(void draw_circle_, (double x, double y, double r, const color_bgr & col1, const color_bgr & col2, bool outline) {
		__basic(__FuncId::draw_circle_colour, x, y, r, col1.get(), col2.get(), outline);
	});

	void draw_ellipse(const vec2 & xy1, const vec2 & xy2, bool outline) {
		draw_ellipse(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, outline);
	}

	void draw_ellipse(double x1, double y1, double x2, double y2, bool outline) {
		__basic(__FuncId::draw_ellipse, x1, y1, x2, y2, outline);
	}

	FUNC_COLOR_COLOUR(void draw_ellipse_, (const vec2 & xy1, const vec2 & xy2, const color_bgr & col1, const color_bgr & col2, bool outline) {
		draw_ellipse_colour(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, col1, col2, outline);
	});

	FUNC_COLOR_COLOUR(void draw_ellipse_, (double x1, double y1, double x2, double y2, const color_bgr & col1, const color_bgr & col2, bool outline) {
		__basic(__FuncId::draw_ellipse_colour, x1, y1, x2, y2, col1.get(), col2.get(), outline);
	});
	
	void draw_line(const vec2 & xy1, const vec2 & xy2) {
		draw_line(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y);
	}

	void draw_line(double x1, double y1, double x2, double y2) {
		__basic(__FuncId::draw_line, x1, y1, x2, y2);
	}
	
	FUNC_COLOR_COLOUR(void draw_line_, (const vec2 & xy1, const vec2 & xy2, const color_bgr & col1, const color_bgr & col2) {
		draw_line_colour(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, col1, col2);
	});

	FUNC_COLOR_COLOUR(void draw_line_, (double x1, double y1, double x2, double y2, const color_bgr & col1, const color_bgr & col2) {
		__basic(__FuncId::draw_line_colour, x1, y1, x2, y2, col1.get(), col2.get());
	});

	void draw_line_width(const vec2 & xy1, const vec2 & xy2, double w) {
		draw_line_width(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, w);
	}
	
	void draw_line_width(double x1, double y1, double x2, double y2, double w) {
		__basic(__FuncId::draw_line_width, x1, y1, x2, y2, w);
	}
	
	FUNC_COLOR_COLOUR(void draw_line_width_, (const vec2 & xy1, const vec2 & xy2, double w, const color_bgr & col1, const color_bgr & col2) {
		draw_line_width_colour(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, w, col1, col2);
	});
	
	FUNC_COLOR_COLOUR(void draw_line_width_, (double x1, double y1, double x2, double y2, double w, const color_bgr & col1, const color_bgr & col2) {
		__basic(__FuncId::draw_line_width_colour, x1, y1, x2, y2, w, col1.get(), col2.get());
	});
	
	void draw_point(const vec2 & xy) {
		draw_point(xy.m_x, xy.m_y);
	}

	void draw_point(double x, double y) {
		__basic(__FuncId::draw_point, x, y);
	}

	FUNC_COLOR_COLOUR(void draw_point_, (const vec2 & xy, const color_bgr & col) {
		draw_point_colour(xy.m_x, xy.m_y, col);
	});

	FUNC_COLOR_COLOUR(void draw_point_, (double x, double y, const color_bgr & col) {
		__basic(__FuncId::draw_point_colour, x, y, col.get());
	});
	
	void draw_rectangle(const rect & rect_, bool outline) {
		draw_rectangle(rect_.m_left, rect_.m_top, rect_.m_right, rect_.m_bottom, outline);
	}

	void draw_rectangle(double x1, double y1, double x2, double y2, bool outline) {
		__basic(__FuncId::draw_rectangle, x1, y1, x2, y2, outline);
	}
	
	FUNC_COLOR_COLOUR(void draw_rectangle_, (const rect & rect_, const rect_t<color_bgr> & rect_col, bool outline) {
		draw_rectangle_colour(rect_.m_left, rect_.m_top, rect_.m_right, rect_.m_bottom, rect_col.m_left, rect_col.m_top, rect_col.m_right, rect_col.m_bottom, outline);
	});

	FUNC_COLOR_COLOUR(void draw_rectangle_, (const rect & rect_, const color_bgr & col1, const color_bgr & col2, const color_bgr & col3, const color_bgr & col4, bool outline) {
		draw_rectangle_colour(rect_.m_left, rect_.m_top, rect_.m_right, rect_.m_bottom, col1.get(), col2.get(), col3.get(), col4.get(), outline);
	});
	
	FUNC_COLOR_COLOUR(void draw_rectangle_, (double x1, double y1, double x2, double y2, const rect_t<color_bgr> & rect_col, bool outline) {
		draw_rectangle_colour(x1, y1, x2, y2, rect_col.m_left, rect_col.m_top, rect_col.m_right, rect_col.m_bottom, outline);
	});

	FUNC_COLOR_COLOUR(void draw_rectangle_, (double x1, double y1, double x2, double y2, const color_bgr & col1, const color_bgr & col2, const color_bgr & col3, const color_bgr & col4, bool outline) {
		__basic(__FuncId::draw_rectangle_colour, x1, y1, x2, y2, col1.get(), col2.get(), col3.get(), col4.get(), outline);
	});
	
	void draw_roundrect(const rect & rect_, bool outline) {
		draw_roundrect(rect_.m_left, rect_.m_top, rect_.m_right, rect_.m_bottom, outline);
	}

	void draw_roundrect(double x1, double y1, double x2, double y2, bool outline) {
		__basic(__FuncId::draw_roundrect, x1, y1, x2, y2, outline);
	}

	FUNC_COLOR_COLOUR(void draw_roundrect_, (const rect & rect_, const color_bgr & col1, const color_bgr & col2, bool outline) {
		draw_roundrect_colour(rect_.m_left, rect_.m_top, rect_.m_right, rect_.m_bottom, col1, col2, outline);
	});
	
	FUNC_COLOR_COLOUR(void draw_roundrect_, (double x1, double y1, double x2, double y2, const color_bgr & col1, const color_bgr & col2, bool outline) {
		__basic(__FuncId::draw_roundrect_colour, x1, y1, x2, y2, col1.get(), col2.get(), outline);
	});
	
	void draw_roundrect_ext(const rect & rect_, double xrad, double yrad, bool outline) {
		draw_roundrect_ext(rect_.m_left, rect_.m_top, rect_.m_right, rect_.m_bottom, xrad, yrad, outline);
	}

	void draw_roundrect_ext(double x1, double y1, double x2, double y2, double xrad, double yrad, bool outline) {
		__basic(__FuncId::draw_roundrect_ext, x1, y1, x2, y2, xrad, yrad, outline);
	}
	
	FUNC_COLOR_COLOUR_EXT(void draw_roundrect_, _ext, (const rect & rect_, double xrad, double yrad, const color_bgr & col1, const color_bgr & col2, bool outline) {
		draw_roundrect_colour_ext(rect_.m_left, rect_.m_top, rect_.m_right, rect_.m_bottom, xrad, yrad, col1, col2, outline);
	});
	
	FUNC_COLOR_COLOUR_EXT(void draw_roundrect_, _ext, (double x1, double y1, double x2, double y2, double xrad, double yrad, const color_bgr & col1, const color_bgr & col2, bool outline) {
		__basic(__FuncId::draw_roundrect_colour_ext, x1, y1, x2, y2, xrad, yrad, col1.get(), col2.get(), outline);
	});
	
	void draw_triangle(const vec2 & xy1, const vec2 & xy2, const vec2 & xy3, bool outline) {
		draw_triangle(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, xy3.m_x, xy3.m_y, outline);
	}

	void draw_triangle(double x1, double y1, double x2, double y2, double x3, double y3, bool outline) {
		__basic(__FuncId::draw_triangle, x1, y1, x2, y2, x3, y3, outline);
	}
	
	FUNC_COLOR_COLOUR(void draw_triangle_, (const vec2 & xy1, const vec2 & xy2, const vec2 & xy3, const color_bgr & col1, const color_bgr & col2, const color_bgr & col3, bool outline) {
		draw_triangle_colour(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, xy3.m_x, xy3.m_y, col1, col2, col3, outline);
	});
	
	FUNC_COLOR_COLOUR(void draw_triangle_, (double x1, double y1, double x2, double y2, double x3, double y3, const color_bgr & col1, const color_bgr & col2, const color_bgr & col3, bool outline) {
		__basic(__FuncId::draw_triangle_colour, x1, y1, x2, y2, x3, y3, col1.get(), col2.get(), col3.get(), outline);
	});
	
	void draw_set_circle_precision(int precision) {
		__basic(__FuncId::draw_set_circle_precision, precision);
	}
	
	void draw_path(asset path, const vec2 & xy, bool absolute) {
		draw_path(path, xy.m_x, xy.m_y, absolute);
	}

	void draw_path(asset path, double x, double y, bool absolute) {
		__basic(__FuncId::draw_path, path, x, y, absolute);
	}

	void draw_self() {
		__basic(__FuncId::draw_self);
	}

	void draw_sprite(asset sprite, unsigned int subimg, const vec2 & xy) {
		draw_sprite(sprite, subimg, xy.m_x, xy.m_y);
	}

	void draw_sprite(asset sprite, unsigned int subimg, double x, double y) {
		__basic(__FuncId::draw_sprite, sprite, subimg, x, y);
	}

	void draw_sprite_ext(asset sprite, unsigned int subimg, const vec2 & xy, const vec2 & scale, double rot, const color_bgr & colour, double alpha) {
		draw_sprite_ext(sprite, subimg, xy.m_x, xy.m_y, scale.m_x, scale.m_y, rot, colour, alpha);
	}
	
	void draw_sprite_ext(asset sprite, unsigned int subimg, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour, double alpha) {
		__basic(__FuncId::draw_sprite_ext, sprite, subimg, x, y, xscale, yscale, rot, colour.get(), alpha);
	}
	
	void draw_sprite_general(asset sprite, unsigned int subimg, double left, double top, double width, double height, double x, double y, double xscale, double yscale, double rot, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		__basic(__FuncId::draw_sprite_general, sprite, subimg, left, top, width, height, x, y, xscale, yscale, rot, c1.get(), c2.get(), c3.get(), c4.get(), alpha);
	}
	
	void draw_sprite_part(asset sprite, unsigned int subimg, double left, double top, double width, double height, const vec2 & xy) {
		draw_sprite_part(sprite, subimg, left, top, width, height, xy.m_x, xy.m_y);
	}
	
	void draw_sprite_part(asset sprite, unsigned int subimg, double left, double top, double width, double height, double x, double y) {
		__basic(__FuncId::draw_sprite_part, sprite, subimg, left, top, width, height, x, y);
	}
	
	void draw_sprite_part_ext(asset sprite, unsigned int subimg, double left, double top, double width, double height, const vec2 & xy, const vec2 & scale, const color_bgr & colour, double alpha) {
		draw_sprite_part_ext(sprite, subimg, left, top, width, height, xy.m_x, xy.m_y, scale.m_x, scale.m_y, colour, alpha);
	}
	
	void draw_sprite_part_ext(asset sprite, unsigned int subimg, double left, double top, double width, double height, double x, double y, const vec2 & scale, const color_bgr & colour, double alpha) {
		draw_sprite_part_ext(sprite, subimg, left, top, width, height, x, y, scale.m_x, scale.m_y, colour, alpha);
	}

	void draw_sprite_part_ext(asset sprite, unsigned int subimg, double left, double top, double width, double height, const vec2 & xy, double xscale, double yscale, const color_bgr & colour, double alpha) {
		draw_sprite_part_ext(sprite, subimg, left, top, width, height, xy.m_x, xy.m_y, xscale, yscale, colour, alpha);
	}
	
	void draw_sprite_part_ext(asset sprite, unsigned int subimg, double left, double top, double width, double height, double x, double y, double xscale, double yscale, const color_bgr & colour, double alpha) {
		__basic(__FuncId::draw_sprite_part_ext, sprite, subimg, left, top, width, height, x, y, xscale, yscale, colour.get(), alpha);
	}
	
	void draw_sprite_stretched(asset sprite, unsigned int subimg, const vec2 & xy, const vec2 & wh) {
		draw_sprite_stretched(sprite, subimg, xy.m_x, xy.m_y, wh.m_x, wh.m_y);
	}
	
	void draw_sprite_stretched(asset sprite, unsigned int subimg, const vec2 & xy, double w, double h) {
		draw_sprite_stretched(sprite, subimg, xy.m_x, xy.m_y, w, h);
	}

	void draw_sprite_stretched(asset sprite, unsigned int subimg, double x, double y, const vec2 & wh) {
		draw_sprite_stretched(sprite, subimg, x, y, wh.m_x, wh.m_y);
	}
	
	void draw_sprite_stretched(asset sprite, unsigned int subimg, double x, double y, double w, double h) {
		__basic(__FuncId::draw_sprite_stretched, sprite, subimg, x, y, w, h);
	}
	
	void draw_sprite_stretched_ext(asset sprite, unsigned int subimg, const vec2 & xy, const vec2 & wh, const color_bgr & colour, double alpha) {
		draw_sprite_stretched_ext(sprite, subimg, xy.m_x, xy.m_y, wh.m_x, wh.m_y, colour, alpha);
	}
	
	void draw_sprite_stretched_ext(asset sprite, unsigned int subimg, const vec2 & xy, double w, double h, const color_bgr & colour, double alpha) {
		draw_sprite_stretched_ext(sprite, subimg, xy.m_x, xy.m_y, w, h, colour, alpha);
	}
	
	void draw_sprite_stretched_ext(asset sprite, unsigned int subimg, double x, double y, const vec2 & wh, const color_bgr & colour, double alpha) {
		draw_sprite_stretched_ext(sprite, subimg, x, y, wh.m_x, wh.m_y, colour, alpha);
	}

	void draw_sprite_stretched_ext(asset sprite, unsigned int subimg, double x, double y, double w, double h, const color_bgr & colour, double alpha) {
		__basic(__FuncId::draw_sprite_stretched_ext, sprite, subimg, x, y, w, h, colour.get(), alpha);
	}
	
	void draw_sprite_pos(asset sprite, unsigned int subimg, const vec2 & xy1, const vec2 & xy2, const vec2 & xy3, const vec2 & xy4, double alpha) {
		draw_sprite_pos(sprite, subimg, xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y, xy3.m_x, xy3.m_y, xy4.m_x, xy4.m_y, alpha);
	}
	
	void draw_sprite_pos(asset sprite, unsigned int subimg, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double alpha) {
		__basic(__FuncId::draw_sprite_pos, sprite, subimg, x1, y1, x2, y2, x3, y3, x4, y4, alpha);
	}
	
	void draw_sprite_tiled(asset sprite, unsigned int subimg, const vec2 & xy) {
		draw_sprite_tiled(sprite, subimg, xy.m_x, xy.m_y);
	}
	
	void draw_sprite_tiled(asset sprite, unsigned int subimg, double x, double y) {
		__basic(__FuncId::draw_sprite_tiled, sprite, subimg, x, y);
	}
	
	void draw_sprite_tiled_ext(asset sprite, unsigned int subimg, const vec2 & xy, const vec2 & scale, const color_bgr & colour, double alpha) {
		draw_sprite_tiled_ext(sprite, subimg, xy.m_x, xy.m_y, scale.m_x, scale.m_y, colour, alpha);
	}
	
	void draw_sprite_tiled_ext(asset sprite, unsigned int subimg, double x, double y, double xscale, double yscale, const color_bgr & colour, double alpha) {
		__basic(__FuncId::draw_sprite_tiled_ext, sprite, subimg, x, y, xscale, yscale, colour.get(), alpha);
	}
	
	void draw_enable_swf_aa(bool enable) {
		__basic(__FuncId::draw_enable_swf_aa, enable);
	}
	
	void draw_set_swf_aa_level(double AA) {
		__basic(__FuncId::draw_set_swf_aa_level, AA);
	}
	
	double draw_get_swf_aa_level() {
		__basic(__FuncId::draw_get_swf_aa_level);
		return g_funcres.m_real;
	}
	
	void draw_skeleton(asset sprite, const std::string & animname, const std::string & skinname, unsigned int frame, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour, double alpha) {
		__basic(__FuncId::draw_skeleton, sprite, animname, skinname, frame, x, y, xscale, yscale, rot, colour.get(), alpha);
	}
	
	void draw_skeleton_instance(ins_id ins_id_, const std::string & animname, const std::string & skinname, unsigned int frame, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour, double alpha) {
		__basic(__FuncId::draw_skeleton_instance, ins_id_, animname, skinname, frame, x, y, xscale, yscale, rot, colour.get(), alpha);
	}
	
	void draw_skeleton_collision(asset sprite, const std::string & animname, unsigned int frame, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour) {
		__basic(__FuncId::draw_skeleton_collision, sprite, animname, frame, x, y, xscale, yscale, rot, colour.get());
	}
	
	void draw_skeleton_time(asset sprite, const std::string & animname, const std::string & skinname, double time, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour, double alpha) {
		__basic(__FuncId::draw_skeleton_time, sprite, animname, skinname, time, x, y, xscale, yscale, rot, colour.get(), alpha);
	}
	
	void draw_tile(asset tileset, int tiledata, unsigned int frame, const vec2 & xy) {
		draw_tile(tileset, tiledata, frame, xy.m_x, xy.m_y);
	}
	
	void draw_tile(asset tileset, int tiledata, unsigned int frame, double x, double y) {
		__basic(__FuncId::draw_tile, tileset, tiledata, frame, x, y);
	}
	
	void draw_tilemap(asset tilemap_element_id, const vec2 & xy) {
		draw_tilemap(tilemap_element_id, xy.m_x, xy.m_y);
	}
	
	void draw_tilemap(asset tilemap_element_id, double x, double y) {
		__basic(__FuncId::draw_tilemap, tilemap_element_id, x, y);
	}

	void draw_set_font(asset font) {
		__basic(__FuncId::draw_set_font, font);
	}

	void draw_set_halign(int halign__fa_xxx) {
		__basic(__FuncId::draw_set_halign, halign__fa_xxx);
	}

	void draw_set_valign(int valign__fa_xxx) {
		__basic(__FuncId::draw_set_valign, valign__fa_xxx);
	}

	asset draw_get_font() {
		__basic(__FuncId::draw_get_font);
		return g_funcres.m_real;
	}

	int draw_get_halign() {
		__basic(__FuncId::draw_get_halign);
		return g_funcres.m_real;
	}
	
	int draw_get_valign() {
		__basic(__FuncId::draw_get_valign);
		return g_funcres.m_real;
	}
	
	void draw_text(const vec2 & xy, const std::string & string) {
		draw_text(xy.m_x, xy.m_y, string);
	}

	void draw_text(double x, double y, const std::string & string) {
		__basic(__FuncId::draw_text, x, y, string);
	}

	void draw_text_ext(const vec2 & xy, const std::string & string, double sep, double w) {
		draw_text_ext(xy.m_x, xy.m_y, string, sep, w);
	}

	void draw_text_ext(double x, double y, const std::string & string, double sep, double w) {
		__basic(__FuncId::draw_text_ext, x, y, string, sep, w);
	}
	
	FUNC_COLOR_COLOUR(void draw_text_, (const vec2 & xy, const std::string & string, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		draw_text_colour(xy.m_x, xy.m_y, string, c1, c2, c3, c4, alpha);
	});

	FUNC_COLOR_COLOUR(void draw_text_, (double x, double y, const std::string & string, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		__basic(__FuncId::draw_text_colour, x, y, string, c1.get(), c2.get(), c3.get(), c4.get(), alpha);
	});
	
	void draw_text_transformed(const vec2 & xy, const std::string & string, const vec2 & scale, double angle) {
		draw_text_transformed(xy.m_x, xy.m_y, string, scale.m_x, scale.m_y, angle);
	}
	
	void draw_text_transformed(const vec2 & xy, const std::string & string, double xscale, double yscale, double angle) {
		draw_text_transformed(xy.m_x, xy.m_y, string, xscale, yscale, angle);
	}
	
	void draw_text_transformed(double x, double y, const std::string & string, const vec2 & scale, double angle) {
		draw_text_transformed(x, y, string, scale.m_x, scale.m_y, angle);
	}
	
	void draw_text_transformed(double x, double y, const std::string & string, double xscale, double yscale, double angle) {
		__basic(__FuncId::draw_text_transformed, x, y, string, xscale, yscale, angle);
	}
	
	FUNC_COLOR_COLOUR(void draw_text_ext_, (const vec2 & xy, const std::string & string, double sep, double w, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		draw_text_ext_colour(xy.m_x, xy.m_y, string, sep, w, c1, c2, c3, c4, alpha);
	});

	FUNC_COLOR_COLOUR(void draw_text_ext_, (double x, double y, const std::string & string, double sep, double w, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		__basic(__FuncId::draw_text_ext_colour, x, y, string, sep, w, c1.get(), c2.get(), c3.get(), c4.get(), alpha);
	});

	void draw_text_ext_transformed(const vec2 & xy, const std::string & string, double sep, double w, const vec2 & scale, double angle) {
		draw_text_ext_transformed(xy.m_x, xy.m_y, string, sep, w, scale.m_x, scale.m_y, angle);
	}
	
	void draw_text_ext_transformed(const vec2 & xy, const std::string & string, double sep, double w, double xscale, double yscale, double angle) {
		draw_text_ext_transformed(xy.m_x, xy.m_y, string, sep, w, xscale, yscale, angle);
	}
	
	void draw_text_ext_transformed(double x, double y, const std::string & string, double sep, double w, const vec2 & scale, double angle) {
		draw_text_ext_transformed(x, y, string, sep, w, scale.m_x, scale.m_y, angle);
	}
	
	void draw_text_ext_transformed(double x, double y, const std::string & string, double sep, double w, double xscale, double yscale, double angle) {
		__basic(__FuncId::draw_text_ext_transformed, x, y, string, sep, w, xscale, yscale, angle);
	}
	
	FUNC_COLOR_COLOUR(void draw_text_transformed_, (const vec2 & xy, const std::string & string, const vec2 & scale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		draw_text_transformed_colour(xy.m_x, xy.m_y, string, scale.m_x, scale.m_y, angle, c1, c2, c3, c4, alpha);
	});
	
	FUNC_COLOR_COLOUR(void draw_text_transformed_, (const vec2 & xy, const std::string & string, double xscale, double yscale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		draw_text_transformed_colour(xy.m_x, xy.m_y, string, xscale, yscale, angle, c1, c2, c3, c4, alpha);
	});
	
	FUNC_COLOR_COLOUR(void draw_text_transformed_, (double x, double y, const std::string & string, const vec2 & scale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		draw_text_transformed_colour(x, y, string, scale.m_x, scale.m_y, angle, c1, c2, c3, c4, alpha);
	});
	
	FUNC_COLOR_COLOUR(void draw_text_transformed_, (double x, double y, const std::string & string, double xscale, double yscale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		__basic(__FuncId::draw_text_transformed_colour, x, y, string, xscale, yscale, angle, c1.get(), c2.get(), c3.get(), c4.get(), alpha);
	});
	
	FUNC_COLOR_COLOUR(void draw_text_ext_transformed_, (const vec2 & xy, const std::string & string, double sep, double w, const vec2 & scale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		draw_text_ext_transformed_colour(xy.m_x, xy.m_y, string, sep, w, scale.m_x, scale.m_y, angle, c1, c2, c3, c4, alpha);
	});
	
	FUNC_COLOR_COLOUR(void draw_text_ext_transformed_, (const vec2 & xy, const std::string & string, double sep, double w, double xscale, double yscale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		draw_text_ext_transformed_colour(xy.m_x, xy.m_y, string, sep, w, xscale, yscale, angle, c1, c2, c3, c4, alpha);
	});
	
	FUNC_COLOR_COLOUR(void draw_text_ext_transformed_, (double x, double y, const std::string & string, double sep, double w, const vec2 & scale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		draw_text_ext_transformed_colour(x, y, string, sep, w, scale.m_x, scale.m_y, angle, c1, c2, c3, c4, alpha);
	});
	
	FUNC_COLOR_COLOUR(void draw_text_ext_transformed_, (double x, double y, const std::string & string, double sep, double w, double xscale, double yscale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha) {
		__basic(__FuncId::draw_text_ext_transformed_colour, x, y, string, sep, w, xscale, yscale, angle, c1.get(), c2.get(), c3.get(), c4.get(), alpha);
	});
	
	void draw_highscore(const rect & rect_) {
		draw_highscore(rect_.m_left, rect_.m_top, rect_.m_right, rect_.m_bottom);
	}
	
	void draw_highscore(const vec2 & xy1, const vec2 & xy2) {
		draw_highscore(xy1.m_x, xy1.m_y, xy2.m_x, xy2.m_y);
	}
	
	void draw_highscore(double x1, double y1, double x2, double y2) {
		__basic(__FuncId::draw_highscore, x1, y1, x2, y2);
	}

}
