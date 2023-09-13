#pragma once

#include "basic.h"

namespace fgm {

	instance instance_create_layer(double x, double y, const char * layername, asset obj);
	instance instance_create_layer(double x, double y, const std::string & layername, asset obj);
	instance instance_create_layer(double x, double y, const layer & _layer, asset obj);
	instance instance_create_depth(double x, double y, int depth, asset obj);
	void instance_destroy(int id, bool execute_event_flag = true);
	void instance_destroy(instance & ins, bool execute_event_flag = true);
	void instance_destroy(const instance && ins, bool execute_event_flag = true);
	bool instance_exists(int id_or_obj);
	ins_id instance_find(asset obj, int n);
	ins_id instance_furthest(double x, double y, asset obj);
	ins_id instance_nearest(double x, double y, asset obj);
	int instance_number(asset obj);
	ins_id instance_place(double x, double y, asset obj);
	ins_id instance_place_list(double x, double y, asset obj, std::vector<ins_id> * p_vlist, bool ordered);
	ins_id instance_position(double x, double y, asset obj);
	ins_id instance_position_list(double x, double y, asset obj, std::vector<ins_id> * p_vlist, bool ordered);
	ins_id instance_id_get(int index);
	int instance_count_get();
	void instance_activate_all();
	void instance_activate_object(int id_or_obj);
	void instance_activate_region(double x_left, double y_top, double width, double height, bool inside);
	void instance_activate_region(rect rect_left_top_right_bottom, bool inside);
	void instance_activate_layer(int layer_id);
	void instance_activate_layer(const layer & _layer);
	void instance_activate_layer(const char * layername);
	void instance_activate_layer(const std::string & layername);
	void instance_deactivate_all(bool not_me);
	void instance_deactivate_object(int id_or_obj);
	void instance_deactivate_region(double x_left, double y_top, double width, double height, bool inside, bool not_me);
	void instance_deactivate_region(rect rect_left_top_right_bottom, bool inside, bool not_me);
	void instance_deactivate_layer(int layer_id);
	void instance_deactivate_layer(const layer & _layer);
	void instance_deactivate_layer(const char * layername);
	void instance_deactivate_layer(const std::string & layername);
	instance instance_get(int id);
	instance instance_get_self();

	/* instance variables */
	
	asset instance_get_object(ins_id id);
	int instance_get_depth(ins_id id);
	void instance_set_depth(ins_id id, int depth);
	layer instance_get_layer(ins_id id);
	void instance_set_layer(ins_id id, const layer & _layer);
	double instance_get_x(ins_id id);
	double instance_get_y(ins_id id);
	vec2 instance_get_pos(ins_id id);
	void instance_get_pos(ins_id id, double * xdest, double * ydest);
	void instance_set_x(ins_id id, double x);
	void instance_set_y(ins_id id, double y);
	void instance_set_pos(ins_id id, const vec2 & _vec2);
	void instance_set_pos(ins_id id, double x, double y);

	bool instance_get_visible(ins_id id);
	void instance_set_visible(ins_id id, bool visible);
	bool instance_get_solid(ins_id id);
	void instance_set_solid(ins_id id, bool solid);
	bool instance_get_persistent(ins_id id);
	void instance_set_persistent(ins_id id, bool persistent);

	asset instance_get_sprite(ins_id id);
	void instance_set_sprite(ins_id id, asset sprindex);
	asset instance_get_mask(ins_id id);
	void instance_set_mask(ins_id id, asset sprindex);
	double instance_get_spr_width(ins_id id);
	double instance_get_spr_height(ins_id id);
	vec2 instance_get_spr_size(ins_id id);
	double instance_get_spr_xoff(ins_id id);
	double instance_get_spr_yoff(ins_id id);
	vec2 instance_get_spr_offset(ins_id id);

	double instance_get_image_alpha(ins_id id);
	void instance_set_image_alpha(ins_id id, double alpha);
	double instance_get_image_angle(ins_id id);
	void instance_set_image_angle(ins_id id, double angle);
	color_t instance_get_image_blend(ins_id id);
	void instance_set_image_blend(ins_id id, color_t col);
	double instance_get_image_xscale(ins_id id);
	void instance_set_image_xscale(ins_id id, double xscale);
	double instance_get_image_yscale(ins_id id);
	void instance_set_image_yscale(ins_id id, double yscale);
	vec2 instance_get_image_scale(ins_id id);
	void instance_set_image_scale(ins_id id, vec2 scale);
	void instance_set_image_scale(ins_id id, double xscale, double yscale);

	unsigned int instance_get_image_index(ins_id id);
	void instance_set_image_index(ins_id id, unsigned int imgindex);
	unsigned int instance_get_image_number(ins_id id);
	double instance_get_image_speed(ins_id id);
	void instance_set_image_speed(ins_id id, double imgspeed);
	
	rect instance_get_bbox_local(ins_id id);
	rect instance_get_bbox(ins_id id);

}
