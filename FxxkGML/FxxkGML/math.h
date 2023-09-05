#pragma once

#include "vars.h"

#include <cmath>

namespace fgm {

	/* 角度转换为弧度
	 * degree to radian */
	double degtorad(double deg);
	/* 弧度转换为角度
	 * radian to degree */
	double radtodeg(double rad);

	template<typename T>
	class vec2_t {
	public:
		vec2_t() = default;
		vec2_t(T x, T y) { m_x = x; m_y = y; }

		vec2_t<T> & operator =(const vec2_t<T> & v) { this->m_x = v.m_x; this->m_y = v.m_y; return * this; }
		vec2_t<T> & operator +=(const vec2_t<T> & v) { this->m_x += v.m_x; this->m_y += v.m_y; return * this; }
		vec2_t<T> & operator -=(const vec2_t<T> & v) { this->m_x -= v.m_x; this->m_y -= v.m_y; return * this; }
		vec2_t<T> & operator *=(const vec2_t<T> & v) { this->m_x *= v.m_x; this->m_y *= v.m_y; return * this; }
		
		vec2_t<T> & operator =(const T & val) { this->m_x = val; this->m_y = val; return * this; }
		vec2_t<T> & operator +=(const T & val) { this->m_x += val; this->m_y += val; return * this; }
		vec2_t<T> & operator -=(const T & val) { this->m_x -= val; this->m_y -= val; return * this; }
		vec2_t<T> & operator *=(const T & val) { this->m_x *= val; this->m_y *= val; return * this; }
		
		vec2_t<T> operator +(const vec2_t<T> & v) { return vec2_t<T>(this->m_x + v.m_x, this->m_y + v.m_y); };
		vec2_t<T> operator -(const vec2_t<T> & v) { return vec2_t<T>(this->m_x - v.m_x, this->m_y - v.m_y); };
		vec2_t<T> operator *(const vec2_t<T> & v) { return vec2_t<T>(this->m_x * v.m_x, this->m_y * v.m_y); };

		vec2_t<T> operator +(const T & val) { return vec2_t<T>(this->m_x + val, this->m_y + val); };
		vec2_t<T> operator -(const T & val) { return vec2_t<T>(this->m_x - val, this->m_y - val); };
		vec2_t<T> operator *(const T & val) { return vec2_t<T>(this->m_x * val, this->m_y * val); };

		double dot(T x, T y) { return this->m_x * x + this->m_y * y; };
		double dot(const vec2_t<T> & v) { return this->m_x * v.m_x + this->m_y * v.m_y; };
		double cross(T x, T y) { return this->m_x * y - this->m_y * x; };
		double cross(const vec2_t<T> & v) { return this->m_x * v.m_y - this->m_y * v.m_x; };

		double length() { return sqrt(m_x * m_x + m_y * m_y); }

		/* 方向，弧度，0 ~ 2pi
		 * direction, radian, 0 ~ 2pi
		 */
		double dirrad() {
			double res = acos(m_x / length());
			return ((m_y < 0) ? (2 * FXXKGML_PI - res) : res);
		}
		/* 方向，角度，0 ~ 360
		 * direction, degree, 0 ~ 360
		 */
		double dirdeg() { return radtodeg(dirrad()); }

		/* 夹角，弧度，填入目标向量的分量
		 * included angle, radian, fill in the components of the target vector
		 */
		double incrad(T x, T y) { return acos(dot(x, y) / (length() * sqrt(x * x + y * y))); }
		/* 夹角，弧度，填入目标向量
		 * included angle, radian, fill in the target vector
		 */
		double incrad(const vec2_t<T> & v) { return incrad(v.m_x, v.m_y); }
		/* 夹角，角度，填入目标向量的分量
		 * included angle, degree, fill in the components of the target vector
		 */
		double incdeg(T x, T y) { return radtodeg(incrad(x, y)); }
		/* 夹角，角度，填入目标向量
		 * included angle, degree, fill in the target vector
		 */
		double incdeg(const vec2_t<T> & v) { return radtodeg(incrad(v.m_x, v.m_y)); }

		/* 旋转，弧度，原向量不变，返回变换后的向量
		 * rotate, radian, keep original vector, return the transformed vector
		 */
		vec2_t<T> rotrad(double rad) {
			double cosr = cos(rad), sinr = sin(rad);
			return vec2_t<T>(
				m_x * cosr - m_y * sinr
				, m_y * cosr + m_x * sinr
			);
		}
		/* 旋转，角度，原向量不变，返回变换后的向量
		 * rotate, degree, keep original vector, return the transformed vector
		 */
		vec2_t<T> rotate(double deg) {
			return rotrad(degtorad(deg));
		}

		/* 归一化，原向量不变，返回变换后的向量
		 * normalize, keep original vector, return the transformed vector
		 */
		vec2_t<T> normalize() {
			double len = length();
			return vec2_t<T>(m_x / len, m_y / len);
		}

		T m_x;
		T m_y;
	};

	typedef vec2_t<double> vec2;

}