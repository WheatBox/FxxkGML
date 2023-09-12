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

	/* TODO */
	asset instance_get_object(ins_id id);
	int instance_get_depth(ins_id id);
	// ...

}
