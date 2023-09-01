// g++ source/FxxkGML_core.cpp test/myFuncTest.cpp test/game.cpp -o test/game.dll -shared

#include "../source/FxxkGML_main.h"

#include "myFuncTest.h"

double val;

void gmlinit() {
	val = gml::random_range(0, 100);
}

void gmlmain() {
	std::string str
		= "Hello, world!\n["
		+ std::to_string(val)
		+ "]\n["
		+ std::to_string(gml::random_range(0, 1))
		+ "]"
	;
	gml::draw_text(128, 64, str);
	MyFuncTest(256, "~~~FLY~~~");
}
