// g++ source/FxxkGML_core.cpp test/game2.cpp test/game.cpp -o test/game.dll -shared

#include "../source/FxxkGML.h"
#include "game2.h"

void gmlmain() {
	gml::random_range(0, 100);
	// std::string str = "Hello, world!\n[" + std::to_string(val) + "]";
	// gml::draw_text(128, 64, str);
}
