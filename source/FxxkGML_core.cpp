#include "FxxkGML_core.h"

void gml::draw_text(double x, double y, std::string text) {
	__basic(__FuncId::draw_text, gmvar(x), gmvar(y), gmvar(text));
}