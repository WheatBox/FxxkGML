#pragma once

#include "basic.h"

namespace fgm {
	
	bool layer_exists(int layer_id);
	bool layer_exists(const char * layer_name);
	bool layer_exists(const std::string & layer_name);
	layer layer_get(int layer_id);
	layer layer_get(const char * layer_name);
	layer layer_get(const std::string & layer_name);
	int layer_get_depth(const layer & layer);

	layer layer_create(int depth, const char * name = "");
	layer layer_create(int depth, const std::string & name = "");
	void layer_destroy(layer & layer);
	void layer_destroy(const layer && layer);

}
