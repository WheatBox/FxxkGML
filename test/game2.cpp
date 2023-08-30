#include "../source/FxxkGML_core.h"
#include "game2.h"

double x = -128;
double y = 128;

void HELLO() {
	gml::draw_text(x, y, "~~~Fly~~~");
	x += 4;
	if(x > 640) {
		x = -128;
	}
}