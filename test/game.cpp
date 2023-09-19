#include <FxxkGML.h>
#include <wini/wini.h>

#include "myFuncTest.h"

#include <iostream>

fgm::asset spr_test = -1, spr_block = -1;
fgm::asset obj_test = fgm::noone;
fgm::asset obj_collision_list_test = fgm::noone;
fgm::instance me;
fgm::instance ins, ins2, instest2;
double val;
int rot = 0;

void fgm_init() {
	fgm::randomize();
	fgm::show_debug_overlay(true);

	fgm::asset fnt_consolas = fgm::font_add("C:/Windows/Fonts/consola.ttf", 12, false, false, 0, 65535);
	fgm::draw_set_font(fnt_consolas);

	spr_test = fgm::sprite_add("spr_test.png", 1, false, false, 128, 256);
	spr_block = fgm::asset_get_index("spr_block");
	obj_test = fgm::asset_get_index("obj_test");
	obj_collision_list_test = fgm::asset_get_index("obj_collision_list_test");
	val = fgm::random_range(0, 100);

	ins = fgm::instance(fgm::vec2(320, 420), -100, obj_test);
	ins.set_sprite(spr_test);
	
	vec2_t_test();

	fgm::layer mylayer(-1145, "mylayer");
	std::cout << mylayer.get_id() << ", " << fgm::layer_get_depth(mylayer) << ", " << mylayer.get_name() << std::endl;
	mylayer = fgm::layer_get("Background");
	std::cout << mylayer.get_id() << ", " << mylayer.get_depth() << ", " << mylayer.get_name() << std::endl;
	mylayer = fgm::layer_get(0);
	std::cout << mylayer.get_id() << ", " << mylayer.get_depth() << ", " << mylayer.get_name() << std::endl;
	mylayer = fgm::layer_get("mylayer");
	std::cout << fgm::layer_exists(mylayer.get_id()) << std::endl;
	fgm::layer_destroy(mylayer);
	std::cout << mylayer.get_id() << std::endl;
	fgm::layer_get("Background").destroy();
	mylayer = fgm::layer(-10);
	ins2 = fgm::instance_create_layer(100, 100, mylayer, obj_test);
	std::cout << "isnoone: " << (ins2 == fgm::noone) << std::endl;

	wini::wini w;
	w.load("F:/CloudSleep2/FxxkGML/FxxkGML/wini/test/test.ini");
	std::cout << w.get("section2", "key1", 0.0) << std::endl;
	
	rect_t_test();

	instest2 = fgm::instance_create_layer(320, 96, "Instances", fgm::asset_get_index("obj_test2"));
	std::cout << "SPR: " << instest2.get_sprite() << std::endl;
	std::cout << "MASK: " << instest2.get_mask() << std::endl;

	me = fgm::instance(fgm::self);
	me.set_sprite(spr_block);
	me.set_image_speed(2);
	me.set_image_index(5);
	std::cout << "me.spr: " << me.get_sprite() << std::endl;
	std::cout << "me.mask: " << me.get_mask() << std::endl;
	std::cout << "me.pos: " << me.get_x() << ", " << me.get_y() << std::endl;
	std::cout << "me.imgnum: " << me.get_image_number() << std::endl;

	fgm::color_rgb rgb1(240, 248, 255);
	std::cout << std::hex << rgb1.get() << std::dec << std::endl;
	fgm::color_hsv hsv1 = rgb1;
	rgb1 = hsv1.to_bgr();
	fgm::color_t rgb1hex = rgb1;
	std::cout << std::hex << rgb1hex << std::dec << std::endl;
	std::cout << std::hex << rgb1.to_bgr().get() << std::dec << std::endl;
	std::cout << std::hex << hsv1.to_bgr().get() << std::dec << std::endl;
	std::cout << "HSV: " << hsv1.geth() << ", " << hsv1.gets() << ", " << hsv1.getv() << std::endl;

	auto coltest = [&](const fgm::color_rgb & rgb) {
		std::cout << std::hex << rgb1.get() << std::dec << std::endl;
	};
	coltest(hsv1);

	fgm::variable_instance_set_real(me.get_id(), "vartest", 114514);
}

int t = 0;

void fgm_main() {

	ins.move(fgm::vec2(1, 0));
	if(ins.get_x() > 640 + 128) {
		ins.set_x(-128);
	}

	if(t++ == 180) {
		ins.set_depth(-1919);
	}
	
	if(t == 60) {
		ins2.set_visible(!ins2.get_visible());
		instest2.set_mask(spr_block);
	}
	if(t == 120) {
		fgm::instance_destroy(ins2);
		instest2.set_sprite(spr_test);
	}

	me.set_pos(320 + me.get_spr_width() * std::cos(fgm::degtorad(t)), 320 + me.get_spr_height() * std::sin(fgm::degtorad(t)));
	// fgm::instance_set_pos(me.get_id(), 320 + me.get_spr_width() * std::cos(fgm::degtorad(t)), 320 + me.get_spr_height() * std::sin(fgm::degtorad(t)));
	
	me.set_image_blend((std::sin(fgm::degtorad(t)) + 1) * 0.5 * 255);
	me.set_image_angle(t / 2);
	me.set_image_scale((std::sin(fgm::degtorad(t)) + 1) * 0.3 + 0.5, (std::sin(fgm::degtorad(t + 180)) + 1) * 0.3 + 0.5);

	for(int i = 0; i < fgm::instance_number(obj_collision_list_test); i++) {
		fgm::instance_set_image_blend(fgm::instance_find(obj_collision_list_test, i), fgm::c_white);
	}
	std::vector<fgm::ins_id> vins;
	fgm::instance_position_list(250, 285, obj_collision_list_test, & vins, false);
	
	for(auto & it : vins) {
		fgm::instance_set_image_blend(it, fgm::c_teal);
	}

	fgm::instance_set_image_blend(fgm::instance_furthest(me.get_x(), me.get_y(), obj_collision_list_test), fgm::c_red);
	
	if(fgm::keyboard_check_pressed('F')) {
		fgm::show_debug_message("pressed F key");
	}
}

void DrawEvent() {
	MyFuncTest(256, "~~~FLY~~~");
	MyFuncTest(480, std::to_string(ins.get_id()));
	
	std::string str
		= "Hello, world!\n["
		+ std::to_string(val)
		+ "]\n["
		+ std::to_string(fgm::random_range(0, 1))
		+ "]"
	;
	fgm::draw_text(128, 64, str);

	fgm::draw_text(320, 560,
		std::to_string(ins.get_pos(true).m_x) + ", " +
		std::to_string(ins.get_pos(true).m_y)
	);

	fgm::draw_sprite_ext(spr_test, 0, 320, 320, 1.2, 1.2, rot++, 0x0000FF, 0.5);
	fgm::draw_sprite_ext(spr_test, 0, 400, 320, 1, 1, rot, fgm::c_white, 1);

	if(t >= 180) {
		MyFuncTest(512, std::to_string(ins.get_depth(false)));
	} else {
		MyFuncTest(512, std::to_string(ins.get_depth(true)));
	}

	fgm::draw_set_color(fgm::c_black);
	fgm::draw_text(0, 16, "fps:" + std::to_string(fgm::fps_get()));
	fgm::draw_set_color(fgm::c_white);
}

void ChangeAlpha() {
	me.set_image_alpha(static_cast<int>(me.get_image_alpha()) == 1 ? 0.5 : 1);
}

void fgm_assistant(int assistant_index) {
	switch(assistant_index) {
		case 114514:
			DrawEvent();
			break;
		case 233:
			ChangeAlpha();
			break;
	}
}
