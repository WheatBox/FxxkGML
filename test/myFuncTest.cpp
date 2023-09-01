#include "../source/FxxkGML_core.h"

#include "myFuncTest.h"

int x = -128;

void MyFuncTest(int y, std::string str) {
	gml::draw_text(x, y, str);
	x += 4;
	if(x > 640) {
		x = -128;
	}
}