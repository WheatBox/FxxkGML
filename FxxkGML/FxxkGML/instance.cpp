#include "instance.h"

namespace fgm {

	instance instance_create_layer(double x, double y, const char * layername, asset obj) {
		return { x, y, layername, obj };
	}
	
	instance instance_create_layer(double x, double y, const std::string & layername, asset obj) {
		return { x, y, layername, obj };
	}

	instance instance_create_layer(double x, double y, const layer & _layer, asset obj) {
		return { x, y, _layer, obj };
	}

	instance instance_create_depth(double x, double y, int depth, asset obj) {
		return { x, y, depth, obj };
	}

	void instance_destroy(int id, bool execute_event_flag) {
		__basic(__FuncId::instance_destroy, id, execute_event_flag);
	}

	void instance_destroy(instance & ins, bool execute_event_flag) {
		ins.destroy(execute_event_flag);
	}

	void instance_destroy(const instance && ins, bool execute_event_flag) {
		__basic(__FuncId::instance_destroy, ins.get_id(), execute_event_flag);
	}

	bool instance_exists(int id_or_obj) {
		__basic(__FuncId::instance_exists, id_or_obj);
		return g_funcres.m_real;
	}

	ins_id instance_find(asset obj, int n) {
		__basic(__FuncId::instance_find, obj, n);
		return g_funcres.m_real;
	}

	ins_id instance_furthest(double x, double y, asset obj) {
		__basic(__FuncId::instance_furthest, x, y, obj);
		return g_funcres.m_real;
	}

	ins_id instance_nearest(double x, double y, asset obj) {
		__basic(__FuncId::instance_nearest, x, y, obj);
		return g_funcres.m_real;
	}

	int instance_number(asset obj) {
		__basic(__FuncId::instance_number, obj);
		return g_funcres.m_real;
	}

	ins_id instance_place(double x, double y, asset obj) {
		__basic(__FuncId::instance_place, x, y, obj);
		return g_funcres.m_real;
	}

	ins_id instance_place_list(double x, double y, asset obj, std::vector<ins_id> * p_vlist, bool ordered) {
		__basic(__FuncId::instance_place_list, x, y, obj, 0, ordered);
		for(auto & it : g_funcres_dvec) {
			p_vlist->push_back(static_cast<int>(it));
		}
		return g_funcres.m_real;
	}

	ins_id instance_position(double x, double y, asset obj) {
		__basic(__FuncId::instance_position, x, y, obj);
		return g_funcres.m_real;
	}

	ins_id instance_position_list(double x, double y, asset obj, std::vector<ins_id> * p_vlist, bool ordered) {
		__basic(__FuncId::instance_position_list, x, y, obj, 0, ordered);
		for(auto & it : g_funcres_dvec) {
			p_vlist->push_back(static_cast<int>(it));
		}
		return g_funcres.m_real;
	}

	ins_id instance_id_get(int index) {
		__basic(__FuncId::instance_id_get, index);
		return g_funcres.m_real;
	}

	int instance_count_get() {
		__basic(__FuncId::instance_count_get);
		return g_funcres.m_real;
	}

	void instance_activate_all() {
		__basic(__FuncId::instance_activate_all);
	}

	void instance_activate_object(int id_or_obj) {
		__basic(__FuncId::instance_activate_object, id_or_obj);
	}

	void instance_activate_region(double x_left, double y_top, double width, double height, bool inside) {
		__basic(__FuncId::instance_activate_region, x_left, y_top, width, height, inside);
	}

	void instance_activate_region(rect rect_left_top_right_bottom, bool inside) {
		__basic(__FuncId::instance_activate_region,
			rect_left_top_right_bottom.m_left,
			rect_left_top_right_bottom.m_top,
			rect_left_top_right_bottom.m_right - rect_left_top_right_bottom.m_left,
			rect_left_top_right_bottom.m_bottom - rect_left_top_right_bottom.m_top,
			inside);
	}

	void instance_activate_layer(int layer_id) {
		__basic(__FuncId::instance_activate_layer, layer_id);
	}
	
	void instance_activate_layer(const layer & _layer) {
		__basic(__FuncId::instance_activate_layer, _layer.get_id());
	}
	
	void instance_activate_layer(const char * layername) {
		__basic(__FuncId::instance_activate_layer__str, layername);
	}

	void instance_activate_layer(const std::string & layername) {
		__basic(__FuncId::instance_activate_layer__str, layername);
	}

	void instance_deactivate_all(bool not_me) {
		__basic(__FuncId::instance_deactivate_all, not_me);
	}

	void instance_deactivate_object(int id_or_obj) {
		__basic(__FuncId::instance_deactivate_object, id_or_obj);
	}

	void instance_deactivate_region(double x_left, double y_top, double width, double height, bool inside, bool not_me) {
		__basic(__FuncId::instance_deactivate_region, x_left, y_top, width, height, inside, not_me);
	}

	void instance_deactivate_region(rect rect_left_top_right_bottom, bool inside, bool not_me) {
		__basic(__FuncId::instance_deactivate_region,
			rect_left_top_right_bottom.m_left,
			rect_left_top_right_bottom.m_top,
			rect_left_top_right_bottom.m_right - rect_left_top_right_bottom.m_left,
			rect_left_top_right_bottom.m_bottom - rect_left_top_right_bottom.m_top,
			inside, not_me);
	}

	void instance_deactivate_layer(int layer_id) {
		__basic(__FuncId::instance_deactivate_layer, layer_id);
	}
	
	void instance_deactivate_layer(const layer & _layer) {
		__basic(__FuncId::instance_deactivate_layer, _layer.get_id());
	}
	
	void instance_deactivate_layer(const char * layername) {
		__basic(__FuncId::instance_deactivate_layer__str, layername);
	}

	void instance_deactivate_layer(const std::string & layername) {
		__basic(__FuncId::instance_deactivate_layer__str, layername);
	}
	
	instance instance_get(int id) {
		return { id };
	}

	instance instance_get_self() {
		return { self };
	}

	/* instance variables */

#define ____IVV_GET(func) __instance_var_view.__setid(id); return __instance_var_view.func(true);
#define ____IVV_SET(func, val) __instance_var_view.__setid(id); __instance_var_view.func(val, true);
#define ____IVV_SET2(func, val1, val2) __instance_var_view.__setid(id); __instance_var_view.func(val1, val2, true);

	class __instance_var_view_t : public instance {
	public:
		__instance_var_view_t() = default;

		void __setid(ins_id id) {
			m_id = id;
		}
	} __instance_var_view;

	asset instance_get_object(ins_id id) {
		____IVV_GET(get_object);
	}

	int instance_get_depth(ins_id id) {
		____IVV_GET(get_depth);
	}

	void instance_set_depth(ins_id id, int depth) {
		____IVV_SET(set_depth, depth);
	}

	layer instance_get_layer(ins_id id) {
		____IVV_GET(get_layer);
	}

	void instance_set_layer(ins_id id, const layer & _layer) {
		____IVV_SET(set_layer, _layer);
	}

	double instance_get_x(ins_id id) {
		____IVV_GET(get_x);
	}

	double instance_get_y(ins_id id) {
		____IVV_GET(get_y);
	}

	vec2 instance_get_pos(ins_id id) {
		____IVV_GET(get_pos);
	}

	void instance_get_pos(ins_id id, double * xdest, double * ydest) {
		__instance_var_view.__setid(id);
		__instance_var_view.get_pos(xdest, ydest, true);
	}

	void instance_set_x(ins_id id, double x) {
		____IVV_SET(set_x, x);
	}

	void instance_set_y(ins_id id, double y) {
		____IVV_SET(set_y, y);
	}

	void instance_set_pos(ins_id id, const vec2 & _vec2) {
		____IVV_SET(set_pos, _vec2);
	}

	void instance_set_pos(ins_id id, double x, double y) {
		____IVV_SET2(set_pos, x, y);
	}

	bool instance_get_visible(ins_id id) {
		____IVV_GET(get_visible);
	}

	void instance_set_visible(ins_id id, bool visible) {
		____IVV_SET(set_visible, visible);
	}
	
	bool instance_get_solid(ins_id id) {
		____IVV_GET(get_solid);
	}
	
	void instance_set_solid(ins_id id, bool solid) {
		____IVV_SET(set_solid, solid);
	}
	
	bool instance_get_persistent(ins_id id) {
		____IVV_GET(get_persistent);
	}
	
	void instance_set_persistent(ins_id id, bool persistent) {
		____IVV_SET(set_persistent, persistent);
	}

	asset instance_get_sprite(ins_id id) {
		____IVV_GET(get_sprite);
	}

	void instance_set_sprite(ins_id id, asset sprindex) {
		____IVV_SET(set_sprite, sprindex);
	}

	asset instance_get_mask(ins_id id) {
		____IVV_GET(get_mask);
	}

	void instance_set_mask(ins_id id, asset sprindex) {
		____IVV_SET(set_mask, sprindex);
	}
	
	double instance_get_spr_width(ins_id id) {
		____IVV_GET(get_spr_width);
	}

	double instance_get_spr_height(ins_id id) {
		____IVV_GET(get_spr_height);
	}

	vec2 instance_get_spr_size(ins_id id) {
		____IVV_GET(get_spr_size);
	}

	double instance_get_spr_xoff(ins_id id) {
		____IVV_GET(get_spr_xoff);
	}

	double instance_get_spr_yoff(ins_id id) {
		____IVV_GET(get_spr_yoff);
	}

	vec2 instance_get_spr_offset(ins_id id) {
		____IVV_GET(get_spr_offset);
	}

	double instance_get_image_alpha(ins_id id) {
		____IVV_GET(get_image_alpha);
	}

	void instance_set_image_alpha(ins_id id, double alpha) {
		____IVV_SET(set_image_alpha, alpha);
	}

	double instance_get_image_angle(ins_id id) {
		____IVV_GET(get_image_angle);
	}

	void instance_set_image_angle(ins_id id, double angle) {
		____IVV_SET(set_image_angle, angle);
	}

	color_t instance_get_image_blend(ins_id id) {
		____IVV_GET(get_image_blend);
	}

	void instance_set_image_blend(ins_id id, color_t col) {
		____IVV_SET(set_image_blend, col);
	}

	double instance_get_image_xscale(ins_id id) {
		____IVV_GET(get_image_xscale);
	}

	void instance_set_image_xscale(ins_id id, double xscale) {
		____IVV_SET(set_image_xscale, xscale);
	}

	double instance_get_image_yscale(ins_id id) {
		____IVV_GET(get_image_yscale);
	}

	void instance_set_image_yscale(ins_id id, double yscale) {
		____IVV_SET(set_image_yscale, yscale);
	}

	vec2 instance_get_image_scale(ins_id id) {
		____IVV_GET(get_image_scale);
	}

	void instance_set_image_scale(ins_id id, vec2 scale) {
		____IVV_SET(set_image_scale, scale);
	}

	void instance_set_image_scale(ins_id id, double xscale, double yscale) {
		____IVV_SET2(set_image_scale, xscale, yscale);
	}

	unsigned int instance_get_image_index(ins_id id) {
		____IVV_GET(get_image_index);
	}

	void instance_set_image_index(ins_id id, unsigned int imgindex) {
		____IVV_SET(set_image_index, imgindex);
	}

	unsigned int instance_get_image_number(ins_id id) {
		____IVV_GET(get_image_number);
	}

	double instance_get_image_speed(ins_id id) {
		____IVV_GET(get_image_speed);
	}

	void instance_set_image_speed(ins_id id, double imgspeed) {
		____IVV_SET(set_image_speed, imgspeed);
	}
	
	rect instance_get_bbox_local(ins_id id) {
		____IVV_GET(get_bbox_local);
	}

	rect instance_get_bbox(ins_id id) {
		____IVV_GET(get_bbox);
	}

#undef ____IVV_GET
#undef ____IVV_SET
#undef ____IVV_SET2

}