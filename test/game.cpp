#include <FxxkGML.h>

#include "myFuncTest.h"

fgm::asset spr_test = -1;
fgm::asset obj_test = fgm::noone;
fgm::instance ins;
double val;
int rot = 0;

void gmlinit() {
	spr_test = fgm::asset_get_index("spr_test");
	obj_test = fgm::asset_get_index("obj_test");
	val = fgm::random_range(0, 100);

	ins = fgm::instance(320, 420, -100, obj_test);
	
	vec2_t_test();
}

int t = 0;

void gmlmain() {
	std::string str
		= "Hello, world!\n["
		+ std::to_string(val)
		+ "]\n["
		+ std::to_string(fgm::random_range(0, 1))
		+ "]"
	;
	fgm::draw_text(128, 64, str);
	
	MyFuncTest(256, "~~~FLY~~~");
	MyFuncTest(480, std::to_string(ins.getid()));

	fgm::draw_text(320, 560,
		std::to_string(ins.getpos(true).m_x) + ", " +
		std::to_string(ins.getpos(true).m_y)
	);

	ins.move(fgm::vec2(1, 0));
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

	fgm::draw_sprite_ext(spr_test, 0, 320, 320, 1.2, 1.2, rot++, 0x0000FF, 0.5);
	fgm::draw_sprite_ext(spr_test, 0, 400, 320, 1, 1, rot, fgm::c_white, 1);
}
