#pragma once

#include "basic.h"

namespace fgm {

	void draw_enable_drawevent(bool enable);
	void draw_flush();

	color_bgr draw_getpixel();
	color_bgr draw_get_colour();
	double draw_get_alpha();
	void draw_clear(const color_bgr & col);
	void draw_clear_alpha(const color_bgr & col, double alpha);
	void draw_set_alpha(double alpha);
	void draw_set_colour(const color_bgr & col);

	void draw_arrow(const vec2 & xy1, const vec2 & xy2, double size);
	void draw_arrow(double x1, double y1, double x2, double y2, double size);
	void draw_circle(const vec2 & xy, double r, bool outline);
	void draw_circle(double x, double y, double r, bool outline);
	void draw_circle_colour(const vec2 & xy, double r, const color_bgr & col1, const color_bgr & col2, bool outline);
	void draw_circle_colour(double x, double y, double r, const color_bgr & col1, const color_bgr & col2, bool outline);
	void draw_ellipse(const vec2 & xy1, const vec2 & xy2, bool outline);
	void draw_ellipse(double x1, double y1, double x2, double y2, bool outline);
	void draw_ellipse_colour(const vec2 & xy1, const vec2 & xy2, const color_bgr & col1, const color_bgr & col2, bool outline);
	void draw_ellipse_colour(double x1, double y1, double x2, double y2, const color_bgr & col1, const color_bgr & col2, bool outline);
	void draw_line(const vec2 & xy1, const vec2 & xy2);
	void draw_line(double x1, double y1, double x2, double y2);
	void draw_line_colour(const vec2 & xy1, const vec2 & xy2, const color_bgr & col1, const color_bgr & col2);
	void draw_line_colour(double x1, double y1, double x2, double y2, const color_bgr & col1, const color_bgr & col2);
	void draw_line_width(const vec2 & xy1, const vec2 & xy2, double w);
	void draw_line_width(double x1, double y1, double x2, double y2, double w);
	void draw_line_width_colour(const vec2 & xy1, const vec2 & xy2, double w, const color_bgr & col1, const color_bgr & col2);
	void draw_line_width_colour(double x1, double y1, double x2, double y2, double w, const color_bgr & col1, const color_bgr & col2);
	void draw_point(const vec2 & xy);
	void draw_point(double x, double y);
	void draw_point_colour(const vec2 & xy, const color_bgr & col);
	void draw_point_colour(double x, double y, const color_bgr & col);
	void draw_rectangle(const rect & rect_, bool outline);
	void draw_rectangle(double x1, double y1, double x2, double y2, bool outline);
	void draw_rectangle_colour(const rect & rect_, const rect_t<color_bgr> & rect_col, bool outline);
	void draw_rectangle_colour(const rect & rect_, const color_bgr & col1, const color_bgr & col2, const color_bgr & col3, const color_bgr & col4, bool outline);
	void draw_rectangle_colour(double x1, double y1, double x2, double y2, const rect_t<color_bgr> & rect_col, bool outline);
	void draw_rectangle_colour(double x1, double y1, double x2, double y2, const color_bgr & col1, const color_bgr & col2, const color_bgr & col3, const color_bgr & col4, bool outline);
	void draw_roundrect(const rect & rect_, bool outline);
	void draw_roundrect(double x1, double y1, double x2, double y2, bool outline);
	void draw_roundrect_colour(const rect & rect_, const color_bgr & col1, const color_bgr & col2, bool outline);
	void draw_roundrect_colour(double x1, double y1, double x2, double y2, const color_bgr & col1, const color_bgr & col2, bool outline);
	void draw_roundrect_ext(const rect & rect_, double xrad, double yrad, bool outline);
	void draw_roundrect_ext(double x1, double y1, double x2, double y2, double xrad, double yrad, bool outline);
	void draw_roundrect_colour_ext(const rect & rect_, double xrad, double yrad, const color_bgr & col1, const color_bgr & col2, bool outline);
	void draw_roundrect_colour_ext(double x1, double y1, double x2, double y2, double xrad, double yrad, const color_bgr & col1, const color_bgr & col2, bool outline);
	void draw_triangle(const vec2 & xy1, const vec2 & xy2, const vec2 & xy3, bool outline);
	void draw_triangle(double x1, double y1, double x2, double y2, double x3, double y3, bool outline);
	void draw_triangle_colour(const vec2 & xy1, const vec2 & xy2, const vec2 & xy3, const color_bgr & col1, const color_bgr & col2, const color_bgr & col3, bool outline);
	void draw_triangle_colour(double x1, double y1, double x2, double y2, double x3, double y3, const color_bgr & col1, const color_bgr & col2, const color_bgr & col3, bool outline);
	
	// The precision value that you can input into this function is the number of sides the circle polygon has, and this number can be anything between 4 and 64, but must be a number divisible by 4, with a default value of 24.
	void draw_set_circle_precision(int precision);
	
	void draw_path(asset path, const vec2 & xy, bool absolute);
	void draw_path(asset path, double x, double y, bool absolute);

	void draw_self();
	void draw_sprite(asset sprite, unsigned int subimg, const vec2 & xy);
	void draw_sprite(asset sprite, unsigned int subimg, double x, double y);
	void draw_sprite_ext(asset sprite, unsigned int subimg, const vec2 & xy, const vec2 & scale, double rot, const color_bgr & colour, double alpha);
	void draw_sprite_ext(asset sprite, unsigned int subimg, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour, double alpha);
	void draw_sprite_general(asset sprite, unsigned int subimg, double left, double top, double width, double height, double x, double y, double xscale, double yscale, double rot, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_sprite_part(asset sprite, unsigned int subimg, double left, double top, double width, double height, const vec2 & xy);
	void draw_sprite_part(asset sprite, unsigned int subimg, double left, double top, double width, double height, double x, double y);
	void draw_sprite_part_ext(asset sprite, unsigned int subimg, double left, double top, double width, double height, const vec2 & xy, const vec2 & scale, const color_bgr & colour, double alpha);
	void draw_sprite_part_ext(asset sprite, unsigned int subimg, double left, double top, double width, double height, double x, double y, const vec2 & scale, const color_bgr & colour, double alpha);
	void draw_sprite_part_ext(asset sprite, unsigned int subimg, double left, double top, double width, double height, const vec2 & xy, double xscale, double yscale, const color_bgr & colour, double alpha);
	void draw_sprite_part_ext(asset sprite, unsigned int subimg, double left, double top, double width, double height, double x, double y, double xscale, double yscale, const color_bgr & colour, double alpha);
	void draw_sprite_stretched(asset sprite, unsigned int subimg, const vec2 & xy, const vec2 & wh);
	void draw_sprite_stretched(asset sprite, unsigned int subimg, const vec2 & xy, double w, double h);
	void draw_sprite_stretched(asset sprite, unsigned int subimg, double x, double y, const vec2 & wh);
	void draw_sprite_stretched(asset sprite, unsigned int subimg, double x, double y, double w, double h);
	void draw_sprite_stretched_ext(asset sprite, unsigned int subimg, const vec2 & xy, const vec2 & wh, const color_bgr & colour, double alpha);
	void draw_sprite_stretched_ext(asset sprite, unsigned int subimg, const vec2 & xy, double w, double h, const color_bgr & colour, double alpha);
	void draw_sprite_stretched_ext(asset sprite, unsigned int subimg, double x, double y, const vec2 & wh, const color_bgr & colour, double alpha);
	void draw_sprite_stretched_ext(asset sprite, unsigned int subimg, double x, double y, double w, double h, const color_bgr & colour, double alpha);
	void draw_sprite_pos(asset sprite, unsigned int subimg, const vec2 & xy1, const vec2 & xy2, const vec2 & xy3, const vec2 & xy4, double alpha);
	void draw_sprite_pos(asset sprite, unsigned int subimg, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double alpha);
	void draw_sprite_tiled(asset sprite, unsigned int subimg, const vec2 & xy);
	void draw_sprite_tiled(asset sprite, unsigned int subimg, double x, double y);
	void draw_sprite_tiled_ext(asset sprite, unsigned int subimg, const vec2 & xy, const vec2 & scale, const color_bgr & colour, double alpha);
	void draw_sprite_tiled_ext(asset sprite, unsigned int subimg, double x, double y, double xscale, double yscale, const color_bgr & colour, double alpha);
	void draw_enable_swf_aa(bool enable);
	void draw_set_swf_aa_level(double AA);
	double draw_get_swf_aa_level();
	void draw_skeleton(asset sprite, const std::string & animname, const std::string & skinname, unsigned int frame, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour, double alpha);
	void draw_skeleton_instance(ins_id ins_id_, const std::string & animname, const std::string & skinname, unsigned int frame, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour, double alpha);
	void draw_skeleton_collision(asset sprite, const std::string & animname, unsigned int frame, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour);
	void draw_skeleton_time(asset sprite, const std::string & animname, const std::string & skinname, double time, double x, double y, double xscale, double yscale, double rot, const color_bgr & colour, double alpha);
	void draw_tile(asset tileset, int tiledata, unsigned int frame, const vec2 & xy);
	void draw_tile(asset tileset, int tiledata, unsigned int frame, double x, double y);
	void draw_tilemap(asset tilemap_element_id, const vec2 & xy);
	void draw_tilemap(asset tilemap_element_id, double x, double y);

	void draw_set_font(asset font);
	void draw_set_halign(int halign__fa_xxx);
	void draw_set_valign(int valign__fa_xxx);
	asset draw_get_font();
	int draw_get_halign();
	int draw_get_valign();
	void draw_text(const vec2 & xy, const std::string & string);
	void draw_text(double x, double y, const std::string & string);
	void draw_text_ext(const vec2 & xy, const std::string & string, double sep, double w);
	void draw_text_ext(double x, double y, const std::string & string, double sep, double w);
	void draw_text_colour(const vec2 & xy, const std::string & string, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_colour(double x, double y, const std::string & string, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_transformed(const vec2 & xy, const std::string & string, const vec2 & scale, double angle);
	void draw_text_transformed(const vec2 & xy, const std::string & string, double xscale, double yscale, double angle);
	void draw_text_transformed(double x, double y, const std::string & string, const vec2 & scale, double angle);
	void draw_text_transformed(double x, double y, const std::string & string, double xscale, double yscale, double angle);
	void draw_text_ext_colour(const vec2 & xy, const std::string & string, double sep, double w, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_ext_colour(double x, double y, const std::string & string, double sep, double w, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_ext_transformed(const vec2 & xy, const std::string & string, double sep, double w, const vec2 & scale, double angle);
	void draw_text_ext_transformed(const vec2 & xy, const std::string & string, double sep, double w, double xscale, double yscale, double angle);
	void draw_text_ext_transformed(double x, double y, const std::string & string, double sep, double w, const vec2 & scale, double angle);
	void draw_text_ext_transformed(double x, double y, const std::string & string, double sep, double w, double xscale, double yscale, double angle);
	void draw_text_transformed_colour(const vec2 & xy, const std::string & string, const vec2 & scale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_transformed_colour(const vec2 & xy, const std::string & string, double xscale, double yscale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_transformed_colour(double x, double y, const std::string & string, const vec2 & scale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_transformed_colour(double x, double y, const std::string & string, double xscale, double yscale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_ext_transformed_colour(const vec2 & xy, const std::string & string, double sep, double w, const vec2 & scale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_ext_transformed_colour(const vec2 & xy, const std::string & string, double sep, double w, double xscale, double yscale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_ext_transformed_colour(double x, double y, const std::string & string, double sep, double w, const vec2 & scale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_text_ext_transformed_colour(double x, double y, const std::string & string, double sep, double w, double xscale, double yscale, double angle, const color_bgr & c1, const color_bgr & c2, const color_bgr & c3, const color_bgr & c4, double alpha);
	void draw_highscore(const rect & rect_);
	void draw_highscore(const vec2 & xy1, const vec2 & xy2);
	void draw_highscore(double x1, double y1, double x2, double y2);

}
