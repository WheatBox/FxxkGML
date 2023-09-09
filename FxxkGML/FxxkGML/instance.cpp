#include "instance.h"

namespace fgm {

	instance instance_create_layer(double x, double y, const char * layername, asset obj) {
		return instance(x, y, layername, obj);
	}
	
	instance instance_create_layer(double x, double y, const std::string & layername, asset obj) {
		return instance(x, y, layername, obj);
	}

	instance instance_create_layer(double x, double y, const layer & _layer, asset obj) {
		return instance(x, y, _layer, obj);
	}

	instance instance_create_depth(double x, double y, int depth, asset obj) {
		return instance(x, y, depth, obj);
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
		return funcres.m_real;
	}

	instance instance_find(asset obj, int n) {
		// TODO
		return instance();
	}

	instance instance_get(int id) {
		return instance(id);
	}

	instance instance_get_self() {
		return instance(self);
	}

}