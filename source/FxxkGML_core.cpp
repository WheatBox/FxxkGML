#include "FxxkGML_core.h"

namespace gml {
	gmvar funcres = 0;
}

void gml::draw_text(double x, double y, std::string text) {
	__basic(__FuncId::draw_text, x, y, text);
}

double gml::random_range(double x1, double x2) {
	__basic(__FuncId::random_range, x1, x2);
	return funcres.m_real;
}
