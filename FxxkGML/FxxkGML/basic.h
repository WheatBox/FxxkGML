#pragma once

#include "funcid.h"
#include "math.h"

namespace fgm {

	typedef int asset;

	/* ------- class layer -------- */

	class layer {
	public:
		layer() { m_id = -1; m_name = ""; };

		layer(int depth);
		layer(int depth, const char * name);
		layer(int depth, const std::string & name);

		void destroy();

		int getid() const { return m_id; }
		std::string getname() const { return m_name; }

		int getdepth() const { return m_depth; }
		int getdepth(bool _synch_from_gm);
		void setdepth(int depth, bool _synch_to_gm = true);

	private:

		int m_id;
		std::string m_name;

		int m_depth = 0;

	public:

		void point(int id, const std::string & name, int depth) { m_id = id; m_name = name; m_depth = depth; }

	};

	/* ------ class instance ------ */

	class instance {
	public:
		instance() { m_id = noone; m_obj = noone; };

		instance(const vec2 & pos, int depth, asset obj);
		instance(double x, double y, int depth, asset obj);
		instance(const vec2 & pos, const layer & _layer, asset obj);
		instance(double x, double y, const layer & _layer, asset obj);

		// perf : Whether to perform that new object's Create and Destroy events (true) or not (false).
		void change(asset obj, bool perf);

		// execute_event_flag : Set to true or false to perform the Destroy event or not (optional, default is true)
		void destroy(bool execute_event_flag = true);

		int getid() const { return m_id; }
		asset getobj() const { return m_obj; }
		asset getobj(bool _synch_from_gm);

		/* ------- Depth & Layer ------- */

		int getdepth() const { return m_depth; }
		int getdepth(bool _synch_from_gm);
		void setdepth(int depth, bool _synch_to_gm = true);

		layer getlayer() const { return m_layer; };
		layer getlayer(bool _synch_from_gm);
		void setlayer(const layer & _layer, bool _synch_to_gm = true);

		/* ---------- 关于方位 ---------- */
		/* ------ About Position ------ */

		double getx() const { return m_pos.m_x; }
		double gety() const { return m_pos.m_y; }
		vec2 getpos() const { return m_pos; }
		double getx(bool _synch_from_gm);
		double gety(bool _synch_from_gm);
		vec2 getpos(bool _synch_from_gm);
		void getpos(double * xdest, double * ydest, bool _synch_from_gm = false);

		void setx(double x, bool _synch_to_gm = true);
		void sety(double y, bool _synch_to_gm = true);
		void setpos(const vec2 & _vec2, bool _synch_to_gm = true);
		void setpos(double x, double y, bool _synch_to_gm = true);

		void move(const vec2 & _vec2, bool _synch_from_gm = false, bool _synch_to_gm = true);
		void move(double xadd, double yadd, bool _synch_from_gm = false, bool _synch_to_gm = true);

		/* ------------------------------- */
		
	private:
		
		int m_id;
		asset m_obj;
		asset m_spr; // TODO
		asset m_mask; // TODO

		int m_depth = 0;
		layer m_layer;

		vec2 m_pos;
		vec2 m_scale {1, 1};
	};

	// TODO - 把这些都拆分成一个个头文件（别忘了.cpp里的那些）
	void draw_text(double x, double y, const std::string & text);
	double random_range(double x1, double x2);
	asset asset_get_index(const std::string & name);
	void draw_sprite_ext(asset sprite, int subming, double x, double y, double xscale, double yscale, double rot, int col, double alpha);

	/* ---------------------------- */

	struct __gmvar {
		__gmvar() { m_typeid = 0; m_real = 0; };
		__gmvar(bool val) { m_typeid = 0; m_real = val; };
		__gmvar(int val) { m_typeid = 0; m_real = val; };
		__gmvar(double val) { m_typeid = 0; m_real = val; };
		__gmvar(const char * val) { m_typeid = 1; m_string = val; };
		__gmvar(const std::string & val) { m_typeid = 1; m_string = val; };

		int m_typeid; // 0 = real, 1 = string

		double m_real;
		std::string m_string;
	};

	static __gmvar funcargs[16]; // GM 的函数最多只能使用 16 个参数 | functions in GM can only use 16 arguments
	
	extern __gmvar funcres;
	extern __gmvar otherress[16]; // 有需要的话再去更改这个长度 | change this length if necessary

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
}
