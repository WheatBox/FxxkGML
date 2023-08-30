// g++ source/FxxkGML_core.cpp test/game2.cpp test/game.cpp -o test/game.dll -shared

#include "../source/FxxkGML.h"
#include "game2.h"

void gmlmain() {
	gml::draw_text(128, 64, "Hello, world!");
	HELLO();
}
