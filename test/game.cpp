#include <FxxkGML.h>
#include <wini/wini.h>

#include "myFuncTest.h"

#include <iostream>

fgm::asset spr_test = -1, spr_block = -1;
fgm::asset obj_test = fgm::noone;
fgm::instance me;
fgm::instance ins, ins2, instest2;
double val;
int rot = 0;

void gmlinit() {
	spr_test = fgm::asset_get_index("spr_test");
	spr_block = fgm::asset_get_index("spr_block");
	obj_test = fgm::asset_get_index("obj_test");
	val = fgm::random_range(0, 100);

	ins = fgm::instance(fgm::vec2(320, 420), -100, obj_test);
	
	vec2_t_test();

	fgm::layer mylayer(-1145, "mylayer");
	std::cout << mylayer.getid() << ", " << fgm::layer_get_depth(mylayer) << ", " << mylayer.getname() << std::endl;
	mylayer = fgm::layer_get("Background");
	std::cout << mylayer.getid() << ", " << mylayer.getdepth() << ", " << mylayer.getname() << std::endl;
	mylayer = fgm::layer_get(0);
	std::cout << mylayer.getid() << ", " << mylayer.getdepth() << ", " << mylayer.getname() << std::endl;
	mylayer = fgm::layer_get("mylayer");
	std::cout << fgm::layer_exists(mylayer.getid()) << std::endl;
	fgm::layer_destroy(mylayer);
	std::cout << mylayer.getid() << std::endl;
	fgm::layer_get("Background").destroy();
	mylayer = fgm::layer(-10);
	ins2 = fgm::instance_create_layer(100, 100, mylayer, obj_test);
	std::cout << "isnoone: " << (ins2 == fgm::noone) << std::endl;

	wini::wini w;
	w.load("F:/CloudSleep2/FxxkGML/FxxkGML/wini/test/test.ini");
	std::cout << w.get("section2", "key1", 0.0) << std::endl;
	
	rect_t_test();

	instest2 = fgm::instance_create_layer(320, 96, "Instances", fgm::asset_get_index("obj_test2"));
	std::cout << "SPR: " << instest2.getsprite() << std::endl;
	std::cout << "MASK: " << instest2.getmask() << std::endl;

	me = fgm::instance(fgm::self);
	std::cout << "me.spr: " << me.getsprite() << std::endl;
	me.setsprite(spr_block);
	me.set_image_speed(2);
	me.set_image_index(5);
	std::cout << "me.spr: " << me.getsprite() << std::endl;
	std::cout << "me.mask: " << me.getmask() << std::endl;
	std::cout << "me.pos: " << me.getx() << ", " << me.gety() << std::endl;
	std::cout << "me.imgnum: " << me.get_image_number() << std::endl;

	fgm::color_rgb rgb1(240, 248, 255);
	fgm::color_hsv hsv1 = rgb1.to_hsv();
	std::cout << std::hex << rgb1.get() << std::dec << std::endl;
	fgm::color_t rgb1hex = rgb1;
	std::cout << std::hex << rgb1hex << std::dec << std::endl;
	std::cout << "HSV: " << hsv1.geth() << ", " << hsv1.gets() << ", " << hsv1.getv() << std::endl;
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
	if(t == 60) {
		ins2.setvisible(!ins2.getvisible());
		instest2.setmask(spr_block);
	}
	if(t == 120) {
		fgm::instance_destroy(ins2);
		instest2.setsprite(spr_test);
	}

	me.setpos(320 + me.get_spr_width() * std::cos(fgm::degtorad(t)), 320 + me.get_spr_height() * std::sin(fgm::degtorad(t)));
	me.set_image_blend((std::sin(fgm::degtorad(t)) + 1) * 0.5 * 255);
	me.set_image_angle(t / 2);
	me.set_image_scale((std::sin(fgm::degtorad(t)) + 1) * 0.3 + 0.5, (std::sin(fgm::degtorad(t + 180)) + 1) * 0.3 + 0.5);

	fgm::draw_sprite_ext(spr_test, 0, 320, 320, 1.2, 1.2, rot++, 0x0000FF, 0.5);
	fgm::draw_sprite_ext(spr_test, 0, 400, 320, 1, 1, rot, fgm::c_white, 1);
}
