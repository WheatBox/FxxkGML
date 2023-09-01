#pragma once

#include "FxxkGML_vars.h"

// 有啥 GML 的函数都往这塞
// Put your GML functions here
namespace gml {

	struct __gmvar {
		__gmvar() { m_typeid = 0; m_real = 0; };
		__gmvar(bool val) { m_typeid = 0; m_real = val; };
		__gmvar(int val) { m_typeid = 0; m_real = val; };
		__gmvar(double val) { m_typeid = 0; m_real = val; };
		__gmvar(const char * val) { m_typeid = 1; m_string = val; };
		__gmvar(std::string & val) { m_typeid = 1; m_string = val; };

		int m_typeid; // 0 = real, 1 = string

		double m_real;
		std::string m_string;
	};

	enum class __FuncId {
		nothing = 0,
		draw_text = 1001,
		random_range = 1002,
		asset_get_index = 1003,
		draw_sprite_ext = 1004
	};

	static __FuncId funcid;
	static __gmvar funcargs[16]; // GM 的函数最多只能使用 16 个参数 | functions in GM can only use 16 arguments
	
	extern __gmvar funcres;

	void __basic(__FuncId _fid);
	void __basic(__FuncId _fid, __gmvar _v0);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11, __gmvar _v12);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11, __gmvar _v12, __gmvar _v13);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11, __gmvar _v12, __gmvar _v13, __gmvar _v14);
	void __basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11, __gmvar _v12, __gmvar _v13, __gmvar _v14, __gmvar _v15);

	void draw_text(double x, double y, std::string text);
	double random_range(double x1, double x2);
	asset asset_get_index(std::string name);
	void draw_sprite_ext(asset sprite, int subming, double x, double y, double xscale, double yscale, double rot, int col, double alpha);

};