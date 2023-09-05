#include "instance.h"

namespace fgm {

	instance instance_create_depth(double x, double y, int depth, asset obj) {
		return instance(x, y, depth, obj);
	}

}