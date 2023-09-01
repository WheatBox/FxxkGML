#pragma once

#include <string>

namespace gml {

	typedef double asset;

	template<typename T>
	class vec2 {
	public:
		vec2() = default;
		vec2(T x, T y) { m_x = x; m_y = y; }

		vec2<T> & operator =(const vec2<T> & v) { this->m_x = v.m_x; this->m_y = v.m_y; return * this; }
		vec2<T> & operator +=(const vec2<T> & v) { this->m_x += v.m_x; this->m_y += v.m_y; return * this; }
		vec2<T> & operator -=(const vec2<T> & v) { this->m_x -= v.m_x; this->m_y -= v.m_y; return * this; }
		vec2<T> & operator *=(const vec2<T> & v) { this->m_x *= v.m_x; this->m_y *= v.m_y; return * this; }
		
		vec2<T> & operator =(const T & val) { this->m_x = val; this->m_y = val; return * this; }
		vec2<T> & operator +=(const T & val) { this->m_x += val; this->m_y += val; return * this; }
		vec2<T> & operator -=(const T & val) { this->m_x -= val; this->m_y -= val; return * this; }
		vec2<T> & operator *=(const T & val) { this->m_x *= val; this->m_y *= val; return * this; }
		
		vec2<T> operator +(const vec2<T> & v) { return vec2<T>(this->m_x + v.m_x, this->m_y + v.m_y); };
		vec2<T> operator -(const vec2<T> & v) { return vec2<T>(this->m_x - v.m_x, this->m_y - v.m_y); };
		vec2<T> operator *(const vec2<T> & v) { return vec2<T>(this->m_x * v.m_x, this->m_y * v.m_y); };

		vec2<T> operator +(const T & val) { return vec2<T>(this->m_x + val, this->m_y + val); };
		vec2<T> operator -(const T & val) { return vec2<T>(this->m_x - val, this->m_y - val); };
		vec2<T> operator *(const T & val) { return vec2<T>(this->m_x * val, this->m_y * val); };

		T dot(const vec2<T> & v) { return this->m_x * v.m_x + this->m_y * v.m_y; };
		T cross(const vec2<T> & v) { return this->m_x * v.m_y - this->m_y * v.m_x; };

		T m_x;
		T m_y;
	};

	class instance {
	public:

		double getx(bool _synch_from_gm = false);
		double gety(bool _synch_from_gm = false);
		vec2<double> getpos(bool _synch_from_gm = false);
		void getpos(double * xdest, double * ydest, bool _synch_from_gm = false);

		void setx(bool _synch_to_gm = true);
		void sety(bool _synch_to_gm = true);
		void setpos(vec2<double> _vec2, bool _synch_to_gm = true);
		void setpos(double x, double y, bool _synch_to_gm = true);

		void movepos(vec2<double> _vec2, bool _synch_to_gm = true);
		void movepos(double xadd, double yadd, bool _synch_to_gm = true);
		
	private:
		
		double m_x;
		double m_y;
	};

	const int noone = -4;

	const int c_aqua     = 16776960;
	const int c_black    = 0;
	const int c_blue     = 16711680;
	const int c_dkgray   = 4210752;
	const int c_fuchsia  = 16711935;
	const int c_gray     = 8421504;
	const int c_green    = 32768;
	const int c_lime     = 65280;
	const int c_ltgray   = 12632256;
	const int c_maroon   = 128;
	const int c_navy     = 8388608;
	const int c_olive    = 32896;
	const int c_orange   = 4235519;
	const int c_purple   = 8388736;
	const int c_red      = 255;
	const int c_silver   = 12632256;
	const int c_teal     = 8421376;
	const int c_white    = 16777215;
	const int c_yellow   = 65535;

}
