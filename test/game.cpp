// g++ source/FxxkGML_core.cpp test/myFuncTest.cpp test/game.cpp -o test/game.dll -shared

#include "../source/FxxkGML_main.h"

#include "myFuncTest.h"

gml::asset spr_test = -1;
double val;
int rot = 0;
void test();
void gmlinit() {
	spr_test = gml::asset_get_index("spr_test");
	val = gml::random_range(0, 100);
	test();
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
#include <iostream>
void test() {
	gml::vec2<int> v1(10, 12);
	gml::vec2<int> v2(4, 7);

	auto show = [&]() {
		std::cout << "v1: (" << v1.m_x << ", " << v1.m_y << ")" << std::endl;
		std::cout << "v2: (" << v2.m_x << ", " << v2.m_y << ")" << std::endl;
	};

	show();
	v1 += v2;
	show();
	gml::vec2<int> v3 = v2 -= v1;
	show();
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;
	v2.m_x -= 100;
	v1 = v2;
	show();
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	v3 = v1 - gml::vec2<int>(50, 50);
	show();
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;

	gml::vec2<std::string> vs("A", "B");
	vs += gml::vec2<std::string>("C", "D") + gml::vec2<std::string>("E", "F");
	vs += gml::vec2<std::string>("H", "I") + " WORLD!";
	std::cout << vs.m_x << ", " << vs.m_y << std::endl;
}