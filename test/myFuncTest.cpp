#include "myFuncTest.h"

#include <iostream>

int x = -128;

void MyFuncTest(int y, std::string str) {
	fgm::draw_text(x, y, str);
	x += 1;
	if(x > 640) {
		x = -128;
	}
}

void vec2_t_test() {
	fgm::vec2_t<int> v1(10, 12);
	fgm::vec2_t<int> v2(4, 7);

	std::cout << "v1: (" << v1.m_x << ", " << v1.m_y << ")" << std::endl;
	std::cout << "v2: (" << v2.m_x << ", " << v2.m_y << ")" << std::endl;
	v1 += v2;
	std::cout << "v1: (" << v1.m_x << ", " << v1.m_y << ")" << std::endl;
	std::cout << "v2: (" << v2.m_x << ", " << v2.m_y << ")" << std::endl;
	fgm::vec2_t<int> v3 = v2 -= v1;
	std::cout << "v1: (" << v1.m_x << ", " << v1.m_y << ")" << std::endl;
	std::cout << "v2: (" << v2.m_x << ", " << v2.m_y << ")" << std::endl;
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;
	v2.m_x -= 100;
	v1 = v2;
	std::cout << "v1: (" << v1.m_x << ", " << v1.m_y << ")" << std::endl;
	std::cout << "v2: (" << v2.m_x << ", " << v2.m_y << ")" << std::endl;
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	v3 = v1 - fgm::vec2_t<int>(50, 50);
	std::cout << "v1: (" << v1.m_x << ", " << v1.m_y << ")" << std::endl;
	std::cout << "v2: (" << v2.m_x << ", " << v2.m_y << ")" << std::endl;
	std::cout << "v3: (" << v3.m_x << ", " << v3.m_y << ")" << std::endl;

	fgm::vec2_t<std::string> vs("A", "B");
	vs += fgm::vec2_t<std::string>("C", "D") + fgm::vec2_t<std::string>("E", "F");
	vs += fgm::vec2_t<std::string>("H", "I") + " WORLD!";
	std::cout << vs.m_x << ", " << vs.m_y << std::endl;

	fgm::vec2 vec(5, 0);
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

	vec = fgm::vec2(8, 0).rotate(47);
	std::cout << vec.length() << ", " << vec.dirdeg() << std::endl;
	fgm::vec2 ve = fgm::vec2(6, 0).rotate(222);
	std::cout << vec.incdeg(ve.m_x, ve.m_y) << std::endl;

	std::cout << "----------------------------------" << std::endl;
	fgm::vec2 vv = fgm::vec2(3, 4).normalize();
	std::cout << vv.length() << std::endl;
	std::cout << (vv * 5).m_x << ", " << (vv * 5).m_y << std::endl;
}

void rect_t_test() {
	std::cout << "----------------------------------" << std::endl;
	fgm::rect rec { 10, 40, 200, 400 };
	std::cout << "rec:" << rec.m_left << ", " << rec.m_top << " ~ " << rec.m_right << ", " << rec.m_bottom << std::endl;
	std::cout << "rec center: " << rec.centerx() << "," << rec.centery() << std::endl;
	std::cout << "rec size: " << rec.width() << "," << rec.height() << std::endl;
	std::cout << "rec diagonal_length: " << rec.diagonal_length() << std::endl;
	std::cout << "rec left_top: " << rec.left_top().m_x << "," << rec.left_top().m_y << std::endl;
	std::cout << "rec collision (0, 0): " << rec.collision(fgm::vec2(0, 0)) << std::endl;
	std::cout << "rec collision (0, 40): " << rec.collision(fgm::vec2(0, 40)) << std::endl;
	std::cout << "rec collision (10, 40): " << rec.collision(fgm::vec2(10, 40)) << std::endl;
	std::cout << "rec collision (100, 100): " << rec.collision(fgm::vec2(100, 100)) << std::endl;
	std::cout << "rec collision (100, 400): " << rec.collision(fgm::vec2(100, 400)) << std::endl;
	std::cout << "----------------------------------" << std::endl;
	fgm::rect rec2 = fgm::rect(200, 150, 100, 150);
	rec2 -= fgm::rect(400, 400, 0, 0);
	rec2 += fgm::vec2(0, 50);
	std::cout << "rec2:" << rec2.m_left << ", " << rec2.m_top << " ~ " << rec2.m_right << ", " << rec2.m_bottom << std::endl;
	std::cout << "rec2 center: " << rec2.centerx() << "," << rec2.centery() << std::endl;
	std::cout << "rec2 size: " << rec2.width() << "," << rec2.height() << std::endl;
	std::cout << "rec2 diagonal_length: " << rec2.diagonal_length() << std::endl;
	std::cout << "rec2 left_top: " << rec2.left_top().m_x << "," << rec2.left_top().m_y << std::endl;
	std::cout << "rec2 right_bottom: " << rec2.right_bottom().m_x << "," << rec2.right_bottom().m_y << std::endl;
	std::cout << "rec2 collision (0, 0): " << rec2.collision(fgm::vec2(0, 0)) << std::endl;
	std::cout << "rec2 collision (0, 40): " << rec2.collision(fgm::vec2(0, 40)) << std::endl;
	std::cout << "rec2 collision (10, 40): " << rec2.collision(fgm::vec2(10, 40)) << std::endl;
	std::cout << "rec2 collision (100, 100): " << rec2.collision(fgm::vec2(100, 100)) << std::endl;
	std::cout << "rec2 collision (100, 400): " << rec2.collision(fgm::vec2(100, 400)) << std::endl;
	std::cout << "----------------------------------" << std::endl;
	fgm::rect rec3 = fgm::rect(300, 400, 100, 300);
	std::cout << "rec3:" << rec3.m_left << ", " << rec3.m_top << " ~ " << rec3.m_right << ", " << rec3.m_bottom << std::endl;
	std::cout << "rec3 collision (0, 0): " << rec3.collision(fgm::vec2(0, 0)) << std::endl;
	std::cout << "rec3 collision (0, 40): " << rec3.collision(fgm::vec2(0, 40)) << std::endl;
	std::cout << "rec3 collision (10, 40): " << rec3.collision(fgm::vec2(10, 40)) << std::endl;
	std::cout << "rec3 collision (100, 100): " << rec3.collision(fgm::vec2(100, 100)) << std::endl;
	std::cout << "rec3 collision (100, 400): " << rec3.collision(fgm::vec2(100, 400)) << std::endl;
	std::cout << "rec3 collision (200, 350): " << rec3.collision(fgm::vec2(200, 350)) << std::endl;
	std::cout << "rec collision rec2: " << rec.collision(rec2) << std::endl;
	std::cout << "rec collision rec3: " << rec.collision(rec3) << std::endl;
	std::cout << "rec2 collision rec3: " << rec2.collision(rec3) << std::endl;
	std::cout << "----------------------------------" << std::endl;
}
