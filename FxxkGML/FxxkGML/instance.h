#pragma once

#include "basic.h"

namespace fgm {

	instance instance_create_layer(double x, double y, const layer & _layer, asset obj);
	instance instance_create_depth(double x, double y, int depth, asset obj);
	void instance_destroy(int id, bool execute_event_flag = true);
	void instance_destroy(instance & ins, bool execute_event_flag = true);
	void instance_destroy(const instance && ins, bool execute_event_flag = true);
	bool instance_exists(int id_or_obj);
	instance instance_find(asset obj, int n);

}
