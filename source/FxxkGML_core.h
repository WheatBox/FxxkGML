#pragma once

#include <string>

// 有啥 GML 的函数都往这塞
// Put your GML functions here
namespace gml {

	struct gmvar {
		gmvar() { m_typeid = 0; m_real = 0; };
		gmvar(bool val) { m_typeid = 0; m_real = val; };
		gmvar(int val) { m_typeid = 0; m_real = val; };
		gmvar(double val) { m_typeid = 0; m_real = val; };
		gmvar(std::string & val) { m_typeid = 1; m_string = val; };

		int m_typeid; // 0 = real, 1 = string

		double m_real;
		std::string m_string;
	};

	enum class __FuncId {
		nothing = 0,
		draw_text,
	};

	static __FuncId funcid;
	static gmvar args[16]; // GM 的函数最多只能使用 16 个参数

	// void __basic(__FuncId _fid);
	// void __basic(__FuncId _fid, gmvar _v0);
	// void __basic(__FuncId _fid, gmvar _v0, gmvar _v1);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2);

	void draw_text(double x, double y, std::string text);

};