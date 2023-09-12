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
		__basic(__FuncId::instance_destroy, ins.getid(), execute_event_flag);
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
		__basic(__FuncId::instance_activate_layer, _layer.getid());
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
		__basic(__FuncId::instance_deactivate_layer, _layer.getid());
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

}