#include "layer.h"

namespace fgm {
	
	bool layer_exists(int layer_id) {
		__basic(__FuncId::layer_exists__id, layer_id);
		return g_funcres.m_real;
	}
	
	bool layer_exists(const char * layer_name) {
		return layer_exists(std::string(layer_name));
	}

	bool layer_exists(const std::string & layer_name) {
		__basic(__FuncId::layer_exists, layer_name);
		return g_funcres.m_real;
	}

	layer layer_get(int layer_id) {
		__basic(__FuncId::layer_get__id, layer_id);
		layer res;
		res.point(layer_id, g_funcres.m_string, g_otherress[0].m_real);
		return res;
	}

	layer layer_get(const char * layer_name) {
		return layer_get(std::string(layer_name));
	}

	layer layer_get(const std::string & layer_name) {
		__basic(__FuncId::layer_get, layer_name);
		layer res;
		res.point(g_funcres.m_real, layer_name, g_otherress[0].m_real);
		return res;
	}

	int layer_get_depth(const layer & layer) {
		return layer.get_depth();
	}

	layer layer_create(int depth, const char * name) {
		return { depth, name };
	}

	layer layer_create(int depth, const std::string & name) {
		return { depth, name };
	}

	void layer_destroy(layer & layer) {
		layer.destroy();
	}

	void layer_destroy(const layer && layer) {
		__basic(__FuncId::layer_destroy, layer.get_id());
	}

}
