#include "../source/FxxkGML_core.h"
#include "game2.h"

double x = -128;

void HELLO(int y) {
	gml::draw_text(x, y, "~~~Fly~~~");
	x += 4;
	if(x > 640) {
		x = -128;
	}
}