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
	static gmvar args[16]; // GM 的函数最多只能使用 16 个参数 | functions in GM can only use 16 arguments

	void __basic(__FuncId _fid);
	void __basic(__FuncId _fid, gmvar _v0);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11, gmvar _v12);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11, gmvar _v12, gmvar _v13);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11, gmvar _v12, gmvar _v13, gmvar _v14);
	void __basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11, gmvar _v12, gmvar _v13, gmvar _v14, gmvar _v15);

	void draw_text(double x, double y, std::string text);

};