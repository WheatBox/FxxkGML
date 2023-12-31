#pragma once

#include "funcid.h"
#include "math.h"

#include <vector>

namespace fgm {

	/* ------- class layer -------- */

	class layer {
	public:
		layer() { m_id = -1; m_name = ""; };

		layer(int depth);
		layer(int depth, const char * name);
		layer(int depth, const std::string & name);

		void destroy();

		int get_id() const { return m_id; }
		std::string get_name() const { return m_name; }

		int get_depth() const { return m_depth; }
		int get_depth(bool _synch_from_gm);
		void set_depth(int depth, bool _synch_to_gm = true);

	private:

		int m_id;
		std::string m_name;

		int m_depth = 0;

	public:

		void point(int id, const char * name, int depth) { m_id = id; m_name = name; m_depth = depth; }
		void point(int id, const std::string & name, int depth) { m_id = id; m_name = name; m_depth = depth; }

	};

	/* ------ class instance ------ */

	class instance {
	public:
		instance();

		// get an existing instance
		instance(ins_id id_or_self);

		// create a new instance
		instance(const vec2 & pos, int depth, asset obj);
		instance(double x, double y, int depth, asset obj);
		instance(const vec2 & pos, const layer & _layer, asset obj);
		instance(double x, double y, const layer & _layer, asset obj);
		instance(const vec2 & pos, const char * _layer, asset obj);
		instance(const vec2 & pos, const std::string & _layer, asset obj);
		instance(double x, double y, const char * _layer, asset obj);
		instance(double x, double y, const std::string & _layer, asset obj);

	private:
		void __init();

	public:

		bool operator ==(const instance & ins) { return m_id == ins.get_id(); }
		bool operator ==(const ins_id & id) { return m_id == id; }

		// void change(asset obj, bool perf);

		// execute_event_flag : Set to true or false to perform the Destroy event or not (optional, default is true)
		void destroy(bool execute_event_flag = true);

		ins_id get_id() const { return m_id; }
		asset get_object() const { return m_obj; }
		asset get_object(bool _synch_from_gm);

		/* ------- Depth & Layer ------- */

		int get_depth() const { return m_depth; }
		int get_depth(bool _synch_from_gm);
		void set_depth(int depth, bool _synch_to_gm = true);

		layer get_layer() const { return m_layer; };
		layer get_layer(bool _synch_from_gm);
		void set_layer(const layer & _layer, bool _synch_to_gm = true);

		/* ---------- Position ---------- */

		double get_x() const { return m_pos.m_x; }
		double get_y() const { return m_pos.m_y; }
		vec2 get_pos() const { return m_pos; }
		double get_x(bool _synch_from_gm);
		double get_y(bool _synch_from_gm);
		vec2 get_pos(bool _synch_from_gm);
		void get_pos(double * xdest, double * ydest, bool _synch_from_gm = false);

		void set_x(double x, bool _synch_to_gm = true);
		void set_y(double y, bool _synch_to_gm = true);
		void set_pos(const vec2 & _vec2, bool _synch_to_gm = true);
		void set_pos(double x, double y, bool _synch_to_gm = true);

		void move(const vec2 & _vec2, bool _synch_from_gm = false, bool _synch_to_gm = true);
		void move(double xadd, double yadd, bool _synch_from_gm = false, bool _synch_to_gm = true);

		/* ------------------------------- */

		bool get_visible() const { return m_visible; }
		bool get_visible(bool _synch_from_gm);
		void set_visible(bool visible, bool _synch_to_gm = true);

		bool get_solid() const { return m_solid; }
		bool get_solid(bool _synch_from_gm);
		void set_solid(bool solid, bool _synch_to_gm = true);

		bool get_persistent() const { return m_persistent; }
		bool get_persistent(bool _synch_from_gm);
		void set_persistent(bool persistent, bool _synch_to_gm = true);

		/* -------- Sprite & Image -------- */

		asset get_sprite() const { return m_sprite; }
		asset get_sprite(bool _synch_from_gm, bool _synch_bbox_local_from_gm = true);
		void set_sprite(asset sprindex, bool _synch_to_gm = true, bool _synch_bbox_local_from_gm = true);

		asset get_mask() const { return m_mask; }
		asset get_mask(bool _synch_from_gm, bool _synch_bbox_local_from_gm = true);
		void set_mask(asset sprindex, bool _synch_to_gm = true, bool _synch_bbox_local_from_gm = true);

		double get_spr_width() const { return m_sprsize.m_x; }
		double get_spr_width(bool _synch_from_gm);
		double get_spr_height() const { return m_sprsize.m_y; }
		double get_spr_height(bool _synch_from_gm);
		vec2 get_spr_size() const { return m_sprsize; }
		vec2 get_spr_size(bool _synch_from_gm);

		double get_spr_xoff() const { return m_sproffset.m_x; }
		double get_spr_xoff(bool _synch_from_gm);
		double get_spr_yoff() const { return m_sproffset.m_y; }
		double get_spr_yoff(bool _synch_from_gm);
		vec2 get_spr_offset() const { return m_sproffset; }
		vec2 get_spr_offset(bool _synch_from_gm);

		double get_image_alpha() const { return m_imgalpha; }
		double get_image_alpha(bool _synch_from_gm);
		void set_image_alpha(double alpha, bool _synch_to_gm = true);

		double get_image_angle() const { return m_imgangle; }
		double get_image_angle(bool _synch_from_gm, bool _synch_bbox_local_from_gm = true);
		void set_image_angle(double angle, bool _synch_to_gm = true, bool _synch_bbox_local_from_gm = true);

		color_t get_image_blend() const { return m_imgblend; }
		color_t get_image_blend(bool _synch_from_gm);
		void set_image_blend(color_t col, bool _synch_to_gm = true);

		double get_image_xscale() const { return m_imgscale.m_x; }
		double get_image_xscale(bool _synch_from_gm, bool _synch_bbox_local_from_gm = true);
		void set_image_xscale(double xscale, bool _synch_to_gm = true, bool _synch_bbox_local_from_gm = true);

		double get_image_yscale() const { return m_imgscale.m_y; }
		double get_image_yscale(bool _synch_from_gm, bool _synch_bbox_local_from_gm = true);
		void set_image_yscale(double yscale, bool _synch_to_gm = true, bool _synch_bbox_local_from_gm = true);

		vec2 get_image_scale() const { return m_imgscale; }
		vec2 get_image_scale(bool _synch_from_gm, bool _synch_bbox_local_from_gm = true);
		void set_image_scale(const vec2 & scale, bool _synch_to_gm = true, bool _synch_bbox_local_from_gm = true);
		void set_image_scale(double xscale, double yscale, bool _synch_to_gm = true, bool _synch_bbox_local_from_gm = true);

		unsigned int get_image_index() const { return m_imgindex; }
		unsigned int get_image_index(bool _synch_from_gm);
		void set_image_index(unsigned int imgindex, bool _synch_to_gm = true);

		unsigned int get_image_number() const { return m_imgnumber; }
		unsigned int get_image_number(bool _synch_from_gm);

		double get_image_speed() const { return m_imgspeed; }
		double get_image_speed(bool _synch_from_gm);
		void set_image_speed(double imgspeed, bool _synch_to_gm = true);

		rect get_bbox_local() const { return m_bboxlocal; }
		rect get_bbox_local(bool _synch_from_gm);

		rect get_bbox() const { return get_bbox_local() + m_pos; }
		rect get_bbox(bool _synch_from_gm) { return get_bbox_local(true) + m_pos; };
		
	protected:
		
		ins_id m_id;

	private:

		asset m_obj;

		int m_depth = 0;
		layer m_layer;

		vec2 m_pos;

		bool m_visible = true;
		bool m_solid = false;
		bool m_persistent = false;

		asset m_sprite = -1;
		asset m_mask = -1;

		vec2 m_sprsize;
		vec2 m_sproffset;

		double m_imgalpha = 1;
		double m_imgangle = 0;
		color_t m_imgblend = c_white;
		vec2 m_imgscale { 1, 1 };
		unsigned int m_imgindex = 0;
		double m_imgspeed = 1;

		unsigned int m_imgnumber = 0;

		// bbox_left/top/right/bottom，但在这里是相对坐标
		// bbox_left/top/right/bottom, but it's relative coordinates here
		rect m_bboxlocal;

		/* TODO */

		// path_index
		// path_position
		// path_positionprevious
		// path_speed
		// path_scale
		// path_orientation
		// path_endaction

		// in_sequence
		// sequence_instance
	};

	/* ---------------------------- */

	struct __gmvar {
		__gmvar() { m_typeid = 0; m_real = 0; };
		__gmvar(bool val) { m_typeid = 0; m_real = val; };
		__gmvar(char val) { m_typeid = 0; m_real = val; };
		__gmvar(unsigned char val) { m_typeid = 0; m_real = val; };
		__gmvar(int val) { m_typeid = 0; m_real = val; };
		__gmvar(unsigned int val) { m_typeid = 0; m_real = val; };
		__gmvar(float val) { m_typeid = 0; m_real = val; };
		__gmvar(double val) { m_typeid = 0; m_real = val; };
		__gmvar(const char * val) { m_typeid = 1; m_string = val; };
		__gmvar(const std::string & val) { m_typeid = 1; m_string = val.c_str(); };

		int m_typeid; // 0 = real, 1 = string

		double m_real;
		std::string m_string;
	};

	static __gmvar funcargs[16]; // GM 的函数最多只能使用 16 个参数 | functions in GM can only use 16 arguments
	
	extern __gmvar g_funcres;
	extern __gmvar g_otherress[16]; // 有需要的话再去更改这个长度 | change this length if necessary
	extern std::vector<double> g_funcres_dvec;

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
