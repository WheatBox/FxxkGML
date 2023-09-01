#include "FxxkGML_core.h"

namespace gml {
	__gmvar funcres = 0;
}

void gml::draw_text(double x, double y, std::string text) {
	__basic(__FuncId::draw_text, x, y, text);
}

double gml::random_range(double x1, double x2) {
	__basic(__FuncId::random_range, x1, x2);
	return funcres.m_real;
}

gml::asset gml::asset_get_index(std::string name) {
	__basic(__FuncId::asset_get_index, name);
	return funcres.m_real;
}

void gml::draw_sprite_ext(asset sprite, int subming, double x, double y, double xscale, double yscale, double rot, int col, double alpha) {
	__basic(__FuncId::draw_sprite_ext, sprite, subming, x, y, xscale, yscale, rot, col, alpha);
}
