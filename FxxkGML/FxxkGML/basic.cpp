#include "basic.h"
#include <iostream>
namespace fgm {
	__gmvar funcres = 0;
	__gmvar otherress[16] = {};
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"

namespace fgm {

	void draw_text(double x, double y, const std::string & text) {
		__basic(__FuncId::draw_text, x, y, text);
	}

	double random_range(double x1, double x2) {
		__basic(__FuncId::random_range, x1, x2);
		return funcres.m_real;
	}

	asset asset_get_index(const std::string & name) {
		__basic(__FuncId::asset_get_index, name);
		return funcres.m_real;
	}

	void draw_sprite_ext(asset sprite, int subming, double x, double y, double xscale, double yscale, double rot, int col, double alpha) {
		__basic(__FuncId::draw_sprite_ext, sprite, subming, x, y, xscale, yscale, rot, col, alpha);
	}

/* ------ class layer ------ */
#pragma region __CLASSLAYER__

	layer::layer(int depth)
		: layer(depth, std::string("")) {}

	layer::layer(int depth, const char * name)
		: layer(depth, std::string(name)) {}

	layer::layer(int depth, const std::string & name) {
		__basic(__FuncId::layer_create, depth, name);
		m_id = funcres.m_real;
		m_name = name;
		m_depth = depth;
	}

	void layer::destroy() {
		__basic(__FuncId::layer_destroy, m_id);
		m_id = -1;
		m_name = "";
		m_depth = 0;
	}

	int layer::getdepth(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::layer_get_depth, m_id);
			m_depth = funcres.m_real;
		}
		return m_depth;
	}

	void layer::setdepth(int depth, bool _synch_to_gm) {
		m_depth = depth;
		if(_synch_to_gm) {
			__basic(__FuncId::layer_depth, m_id, depth);
		}
	}

#pragma endregion __CLASSLAYER__

/* ------ class instance ------ */
#pragma region __CLASSINSTANCE__

#define __GET_ONE_VALUE__(fid, dest) \
	if(_synch_from_gm) { \
		__basic(fid, m_id); \
		dest = funcres.m_real; \
	} \
	return dest;

#define __SET_ONE_VALUE__(fid, dest, val) \
	dest = val; \
	if(_synch_to_gm) { \
		__basic(fid, m_id, val); \
	}

	instance::instance()
		: instance(noone) {}

	instance::instance(int id_or_self) {
		if(id_or_self == noone) {
			m_id = noone;
			m_obj = noone;
		} else {
			__basic(__FuncId::instance_get, id_or_self);
			m_id = funcres.m_real;
			m_obj = otherress[0].m_real;
			m_pos = { otherress[1].m_real, otherress[2].m_real };
			m_depth = otherress[3].m_real;

			if(otherress[4].m_real != -1) {
				m_layer.point(otherress[4].m_real, otherress[5].m_string, m_depth);
			}

			__init();
		}
	}

	instance::instance(const vec2 & pos, int depth, asset obj)
		: instance(pos.m_x, pos.m_y, depth, obj) {}

	instance::instance(double x, double y, int depth, asset obj) {
		__basic(__FuncId::instance_create_depth, x, y, depth, obj);
		m_id = funcres.m_real;
		m_obj = obj;
		m_pos = {x, y};
		m_depth = depth;

		__init();
	}
	
	instance::instance(const vec2 & pos, const layer & _layer, asset obj)
		: instance(pos.m_x, pos.m_y, _layer, obj) {}
	
	instance::instance(double x, double y, const layer & _layer, asset obj) {
		__basic(__FuncId::instance_create_layer, x, y, _layer.getid(), obj);
		m_id = funcres.m_real;
		m_obj = obj;
		m_pos = {x, y};
		m_layer = _layer;
		m_depth = _layer.getdepth();
		
		__init();
	}

	instance::instance(const vec2 & pos, const char * layername, asset obj)
		: instance(pos.m_x, pos.m_y, std::string(layername), obj) {}
	
	instance::instance(const vec2 & pos, const std::string & layername, asset obj)
		: instance(pos.m_x, pos.m_y, layername, obj) {}
	
	instance::instance(double x, double y, const char * layername, asset obj)
		: instance(x, y, std::string(layername), obj) {}
	
	instance::instance(double x, double y, const std::string & layername, asset obj) {
		__basic(__FuncId::instance_create_layer__str, x, y, layername, obj);
		m_id = funcres.m_real;
		m_obj = obj;
		m_pos = {x, y};
		m_layer.point(otherress[0].m_real, layername, otherress[1].m_real);
		m_depth = m_layer.getdepth();
		
		__init();
	}

	void instance::__init() {
		__basic(__FuncId::cinstance___init, m_id);
		int other0 = static_cast<int>(otherress[0].m_real);
		m_visible = (other0 & 0b1) == 0b1;
		m_solid = (other0 & 0b10) == 0b10;
		m_persistent = (other0 & 0b100) == 0b100;

		m_sprite = otherress[1].m_real;
		m_mask = otherress[2].m_real;
		m_sprsize.m_x = otherress[3].m_real;
		m_sprsize.m_y = otherress[4].m_real;
		m_sproffset = { otherress[5].m_real, otherress[6].m_real };
		m_imgnumber = otherress[7].m_real;
	}

	void instance::destroy(bool execute_event_flag) {
		__basic(__FuncId::instance_destroy, m_id, execute_event_flag);
		m_id = noone;
		m_obj = noone;
	}

	asset instance::getobject(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getobj, m_obj);
	}

	int instance::getdepth(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getdepth, m_depth);
	}

	void instance::setdepth(int depth, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setdepth, m_depth, depth);
	}

	double instance::getx(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getx, m_pos.m_x);
	}

	double instance::gety(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_gety, m_pos.m_y);
	}

	vec2 instance::getpos(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::cinstance_getpos, m_id);
			m_pos.m_x = otherress[0].m_real;
			m_pos.m_y = otherress[1].m_real;
		}
		return m_pos;
	}

	void instance::getpos(double * xdest, double * ydest, bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::cinstance_getpos, m_id);
			m_pos.m_x = otherress[0].m_real;
			m_pos.m_y = otherress[1].m_real;
		}
		* xdest = m_pos.m_x;
		* ydest = m_pos.m_y;
	}

	void instance::setx(double x, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setx, m_pos.m_x, x);
	}

	void instance::sety(double y, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_sety, m_pos.m_y, y);
	}

	void instance::setpos(const vec2 & _vec2, bool _synch_to_gm) {
		setpos(_vec2.m_x, _vec2.m_y, _synch_to_gm);
	}

	void instance::setpos(double x, double y, bool _synch_to_gm) {
		m_pos.m_x = x;
		m_pos.m_y = y;
		if(_synch_to_gm) {
			__basic(__FuncId::cinstance_setpos, m_id, x, y);
		}
	}

	void instance::move(const vec2 & _vec2, bool _synch_from_gm, bool _synch_to_gm) {
		move(_vec2.m_x, _vec2.m_y, _synch_from_gm, _synch_to_gm);
	}
	
	void instance::move(double xadd, double yadd, bool _synch_from_gm, bool _synch_to_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::cinstance_getpos, m_id);
			m_pos.m_x = otherress[0].m_real;
			m_pos.m_y = otherress[1].m_real;
		}
		m_pos.m_x += xadd;
		m_pos.m_y += yadd;
		if(_synch_to_gm) {
			__basic(__FuncId::cinstance_setpos, m_id, m_pos.m_x, m_pos.m_y);
		}
	}

	bool instance::getvisible(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getvisible, m_visible);
	}

	void instance::setvisible(bool visible, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setvisible, m_visible, visible);
	}

	bool instance::getsolid(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getsolid, m_solid);
	}

	void instance::setsolid(bool solid, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setsolid, m_solid, solid);
	}

	bool instance::getpersistent(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getpersistent, m_persistent);
	}

	void instance::setpersistent(bool persistent, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setpersistent, m_persistent, persistent);
	}

	asset instance::getsprite(bool _synch_from_gm) {
		asset beforespr = m_sprite;
		__GET_ONE_VALUE__(__FuncId::cinstance_getspr, m_sprite);
		if(_synch_from_gm && m_sprite != beforespr) {
			get_spr_size(true);
			get_spr_offset(true);
			get_image_number(true);
		}
	}

	void instance::setsprite(asset sprindex, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setspr, m_sprite, sprindex);
		if(_synch_to_gm) {
			get_spr_size(true);
			get_spr_offset(true);
			get_image_number(true);
		}
	}

	asset instance::getmask(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getmask, m_mask);
	}

	void instance::setmask(asset sprindex, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setmask, m_mask, sprindex);
	}

	double instance::get_spr_width(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getsprwidth, m_sprsize.m_x);
	}

	double instance::get_spr_height(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getsprheight, m_sprsize.m_y);
	}

	vec2 instance::get_spr_size(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::cinstance_getsprsize, m_id);
			m_sprsize.m_x = otherress[0].m_real;
			m_sprsize.m_y = otherress[1].m_real;
		}
		return m_sprsize;
	}

	double instance::get_spr_xoff(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getsprxoff, m_sproffset.m_x);
	}

	double instance::get_spr_yoff(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getspryoff, m_sproffset.m_y);
	}
	
	vec2 instance::get_spr_offset(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::cinstance_getsproffset, m_id);
			m_sproffset.m_x = otherress[0].m_real;
			m_sproffset.m_y = otherress[1].m_real;
		}
		return m_sproffset;
	}

	double instance::get_image_alpha(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getimgalpha, m_imgalpha);
	}

	void instance::set_image_alpha(double alpha, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setimgalpha, m_imgalpha, alpha);
	}

	double instance::get_image_angle(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getimgangle, m_imgangle);
	}

	void instance::set_image_angle(double angle, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setimgangle, m_imgangle, angle);
	}

	color_t instance::get_image_blend(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getimgblend, m_imgblend);
	}

	void instance::set_image_blend(color_t col, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setimgblend, m_imgblend, col);
	}

	double instance::get_image_xscale(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getimgxscale, m_imgscale.m_x);
	}

	void instance::set_image_xscale(double xscale, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setimgxscale, m_imgscale.m_x, xscale);
	}

	double instance::get_image_yscale(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getimgyscale, m_imgscale.m_y);
	}

	void instance::set_image_yscale(double yscale, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setimgyscale, m_imgscale.m_y, yscale);
	}

	vec2 instance::get_image_scale(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::cinstance_getimgscale, m_id);
			m_imgscale.m_x = otherress[0].m_real;
			m_imgscale.m_y = otherress[1].m_real;
		}
		return m_imgscale;
	}

	void instance::set_image_scale(vec2 scale, bool _synch_to_gm) {
		set_image_scale(scale.m_x, scale.m_y, _synch_to_gm);
	}
	
	void instance::set_image_scale(double xscale, double yscale, bool _synch_to_gm) {
		m_imgscale.m_x = xscale;
		m_imgscale.m_y = yscale;
		if(_synch_to_gm) {
			__basic(__FuncId::cinstance_setimgscale, m_id, xscale, yscale);
		}
	}

	unsigned int instance::get_image_index(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getimgindex, m_imgindex);
	}

	void instance::set_image_index(unsigned int imgindex, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setimgindex, m_imgindex, imgindex);
	}

	double instance::get_image_speed(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getimgspeed, m_imgspeed);
	}

	void instance::set_image_speed(double imgspeed, bool _synch_to_gm) {
		__SET_ONE_VALUE__(__FuncId::cinstance_setimgspeed, m_imgspeed, imgspeed);
	}

	unsigned int instance::get_image_number(bool _synch_from_gm) {
		__GET_ONE_VALUE__(__FuncId::cinstance_getimgnumber, m_imgnumber);
	}
	
#pragma endregion __CLASSINSTANCE__

}

#pragma GCC diagnostic pop
