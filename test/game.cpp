// g++ source/FxxkGML_vars.cpp source/FxxkGML_core.cpp test/myFuncTest.cpp test/game.cpp -o test/game.dll -shared

#include "FxxkGML_main.h"

#include "myFuncTest.h"

gml::asset spr_test = -1;
gml::asset obj_test = gml::noone;
gml::instance ins;
double val;
int rot = 0;

void gmlinit() {
	spr_test = gml::asset_get_index("spr_test");
	obj_test = gml::asset_get_index("obj_test");
	val = gml::random_range(0, 100);

	ins = gml::instance_create_depth(320, 320, -100, obj_test);
	
	vec2_t_test();
}

int t = 0;

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
	MyFuncTest(480, std::to_string(ins.getid()));

	gml::draw_text(320, 560,
		std::to_string(ins.getpos(true).m_x) + ", " +
		std::to_string(ins.getpos(true).m_y)
	);

	ins.move(gml::vec2(1, 0));
	if(ins.getx() > 640 + 128) {
		ins.setx(-128);
	}

	if(t++ == 180) {
		ins.setdepth(-1919);
	}
	if(t >= 180) {
		MyFuncTest(512, std::to_string(ins.getdepth(false)));
	} else {
		MyFuncTest(512, std::to_string(ins.getdepth(true)));
	}

	gml::draw_sprite_ext(spr_test, 0, 320, 320, 1.2, 1.2, rot++, 0x0000FF, 0.5);
	gml::draw_sprite_ext(spr_test, 0, 400, 320, 1, 1, rot, gml::c_white, 1);
}
