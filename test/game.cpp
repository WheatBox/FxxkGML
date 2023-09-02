// g++ source/FxxkGML_vars.cpp source/FxxkGML_core.cpp test/myFuncTest.cpp test/game.cpp -o test/game.dll -shared

#include "../source/FxxkGML_main.h"

#include "myFuncTest.h"

gml::asset spr_test = -1;
double val;
int rot = 0;

void gmlinit() {
	spr_test = gml::asset_get_index("spr_test");
	val = gml::random_range(0, 100);
	
	vec2_t_test();
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

	gml::draw_sprite_ext(spr_test, 0, 320, 320, 1.2, 1.2, rot++, 0x0000FF, 0.5);
	gml::draw_sprite_ext(spr_test, 0, 400, 320, 1, 1, rot, gml::c_white, 1);
}
