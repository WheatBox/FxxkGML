#include "myFuncTest.h"

#include <iostream>

int x = -128;

void MyFuncTest(int y, std::string str) {
	gml::draw_text(x, y, str);
	x += 1;
	if(x > 640) {
		x = -128;
	}
}

void vec2_t_test() {
	gml::vec2_t<int> v1(10, 12);
	gml::vec2_t<int> v2(4, 7);

	auto show = [&]() {
		std::cout << "v1: (" << v1.m_x << ", " << v1.m_y << ")" << std::endl;
		std::cout << "v2: (" << v2.m_x << ", " << v2.m_y << ")" << std::endl;
	};

	show();
	v1 += v2;
	show();
	gml::vec2_t<int> v3 = v2 -= v1;
	show();
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;
	v2.m_x -= 100;
	v1 = v2;
	show();
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	v3 = v1 - gml::vec2_t<int>(50, 50);
	show();
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;

	gml::vec2_t<std::string> vs("A", "B");
	vs += gml::vec2_t<std::string>("C", "D") + gml::vec2_t<std::string>("E", "F");
	vs += gml::vec2_t<std::string>("H", "I") + " WORLD!";
	std::cout << vs.m_x << ", " << vs.m_y << std::endl;

	gml::vec2 vec(5, 0);
	std::cout << vec.dirdeg() << std::endl;
	std::cout << vec.m_x << ", " << vec.m_y << " length : " << vec.length() << std::endl;
	vec = vec.rotate(90);
	std::cout << vec.m_x << ", " << vec.m_y << " length : " << vec.length() << std::endl;
	vec = vec.rotate(90);
	std::cout << vec.m_x << ", " << vec.m_y << " length : " << vec.length() << std::endl;
	std::cout << vec.dirdeg() << std::endl;
	vec = vec.rotate(45);
	std::cout << vec.m_x << ", " << vec.m_y << " length : " << vec.length() << std::endl;
	std::cout << vec.dirdeg() << std::endl;

	std::cout << "----------------------------------" << std::endl;
	for(int i = 0; i < 6; i++) {
		vec = vec.rotate(60);
		std::cout << vec.dirdeg() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;
	for(int i = 0; i < 6; i++) {
		vec = vec.rotate(-60);
		std::cout << vec.dirdeg() << std::endl;
	}
	std::cout << "----------------------------------" << std::endl;

	vec = gml::vec2(8, 0).rotate(47);
	std::cout << vec.length() << ", " << vec.dirdeg() << std::endl;
	gml::vec2 ve = gml::vec2(6, 0).rotate(222);
	std::cout << vec.incdeg(ve.m_x, ve.m_y) << std::endl;

	std::cout << "----------------------------------" << std::endl;
	gml::vec2 vv = gml::vec2(3, 4).normalize();
	std::cout << vv.length() << std::endl;
	std::cout << (vv * 5).m_x << ", " << (vv * 5).m_y << std::endl;
}
