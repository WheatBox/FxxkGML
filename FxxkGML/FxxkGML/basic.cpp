#include "basic.h"

namespace fgm {
	__gmvar funcres = 0;
	__gmvar otherress[16] = {};
}

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

	/* class instance */

	instance::instance(vec2 & pos, int depth, asset obj) {
		instance(pos.m_x, pos.m_y, depth, obj);
	}

	instance::instance(double x, double y, int depth, asset obj) {
		__basic(__FuncId::instance_create_depth, x, y, depth, obj);
		m_id = funcres.m_real;
		m_obj = obj;
		m_pos = {x, y};
		m_depth = depth;
	}

	instance::instance(vec2 & pos, const char * layer, asset obj) {
	}

	instance::instance(double x, double y, const char * layer, asset obj) {
	}

	instance::instance(vec2 & pos, const std::string & layer, asset obj) {
	}

	instance::instance(double x, double y, const std::string & layer, asset obj) {
	}

	int instance::getdepth(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::__instance_getdepth, m_id);
			m_depth = funcres.m_real;
		}
		return m_depth;
	}

	void instance::setdepth(int depth, bool _synch_to_gm) {
		m_depth = depth;
		if(_synch_to_gm) {
			__basic(__FuncId::__instance_setdepth, m_id, depth);
		}
	}

	double instance::getx(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::__instance_getx, m_id);
			m_pos.m_x = funcres.m_real;
		}
		return m_pos.m_x;
	}

	double instance::gety(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::__instance_gety, m_id);
			m_pos.m_y = funcres.m_real;
		}
		return m_pos.m_y;
	}

	vec2 instance::getpos(bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::__instance_getpos, m_id);
			m_pos.m_x = otherress[0].m_real;
			m_pos.m_y = otherress[1].m_real;
		}
		return m_pos;
	}

	void instance::getpos(double * xdest, double * ydest, bool _synch_from_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::__instance_getpos, m_id);
			m_pos.m_x = otherress[0].m_real;
			m_pos.m_y = otherress[1].m_real;
		}
		* xdest = m_pos.m_x;
		* ydest = m_pos.m_y;
	}

	void instance::setx(double x, bool _synch_to_gm) {
		m_pos.m_x = x;
		if(_synch_to_gm) {
			__basic(__FuncId::__instance_setx, m_id, x);
		}
	}

	void instance::sety(double y, bool _synch_to_gm) {
		m_pos.m_y = y;
		if(_synch_to_gm) {
			__basic(__FuncId::__instance_sety, m_id, y);
		}
	}

	void instance::setpos(const vec2 & _vec2, bool _synch_to_gm) {
		setpos(_vec2.m_x, _vec2.m_y, _synch_to_gm);
	}

	void instance::setpos(double x, double y, bool _synch_to_gm) {
		m_pos.m_x = x;
		m_pos.m_y = y;
		if(_synch_to_gm) {
			__basic(__FuncId::__instance_setpos, m_id, x, y);
		}
	}

	void instance::move(const vec2 & _vec2, bool _synch_from_gm, bool _synch_to_gm) {
		move(_vec2.m_x, _vec2.m_y, _synch_from_gm, _synch_to_gm);
	}
	void instance::move(double xadd, double yadd, bool _synch_from_gm, bool _synch_to_gm) {
		if(_synch_from_gm) {
			__basic(__FuncId::__instance_getpos, m_id);
			m_pos.m_x = otherress[0].m_real;
			m_pos.m_y = otherress[1].m_real;
		}
		m_pos.m_x += xadd;
		m_pos.m_y += yadd;
		if(_synch_to_gm) {
			__basic(__FuncId::__instance_setpos, m_id, m_pos.m_x, m_pos.m_y);
		}
	}

}
