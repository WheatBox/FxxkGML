#pragma once

#include "vars.h"

namespace fgm {

	/* 角度转换为弧度
	 * degree to radian */
	double degtorad(double deg);

	/* 弧度转换为角度
	 * radian to degree */
	double radtodeg(double rad);

	/* 随机化种子
	 * randomize the seed */
	void randomize();
	
	/* 随机化种子
	 * randomise the seed */
	void randomise();

	/* 生成随机数（带小数）
	 * Generate random numbers (with decimals) */
	double random_range(double n1, double n2);

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
		
		vec2_t<T> operator +(const vec2_t<T> & v) const { return { this->m_x + v.m_x, this->m_y + v.m_y }; };
		vec2_t<T> operator -(const vec2_t<T> & v) const { return { this->m_x - v.m_x, this->m_y - v.m_y }; };
		vec2_t<T> operator *(const vec2_t<T> & v) const { return { this->m_x * v.m_x, this->m_y * v.m_y }; };

		vec2_t<T> operator +(const T & val) const { return { this->m_x + val, this->m_y + val }; };
		vec2_t<T> operator -(const T & val) const { return { this->m_x - val, this->m_y - val }; };
		vec2_t<T> operator *(const T & val) const { return { this->m_x * val, this->m_y * val }; };

		double dot(T x, T y) const { return this->m_x * x + this->m_y * y; };
		double dot(const vec2_t<T> & v) const { return this->m_x * v.m_x + this->m_y * v.m_y; };
		double cross(T x, T y) const { return this->m_x * y - this->m_y * x; };
		double cross(const vec2_t<T> & v) const { return this->m_x * v.m_y - this->m_y * v.m_x; };

		double length() const { return sqrt(m_x * m_x + m_y * m_y); }

		/* 方向，弧度，0 ~ 2pi
		 * direction, radian, 0 ~ 2pi
		 */
		double dirrad() const {
			double res = acos(m_x / length());
			return ((m_y < 0) ? (2 * FXXKGML_PI - res) : res);
		}
		/* 方向，角度，0 ~ 360
		 * direction, degree, 0 ~ 360
		 */
		double dirdeg() const { return radtodeg(dirrad()); }

		/* 夹角，弧度，填入目标向量的分量
		 * included angle, radian, fill in the components of the target vector
		 */
		double incrad(T x, T y) const { return acos(dot(x, y) / (length() * sqrt(x * x + y * y))); }
		/* 夹角，弧度，填入目标向量
		 * included angle, radian, fill in the target vector
		 */
		double incrad(const vec2_t<T> & v) const { return incrad(v.m_x, v.m_y); }
		/* 夹角，角度，填入目标向量的分量
		 * included angle, degree, fill in the components of the target vector
		 */
		double incdeg(T x, T y) const { return radtodeg(incrad(x, y)); }
		/* 夹角，角度，填入目标向量
		 * included angle, degree, fill in the target vector
		 */
		double incdeg(const vec2_t<T> & v) const { return radtodeg(incrad(v.m_x, v.m_y)); }

		/* 旋转，弧度，原向量不变，返回变换后的向量
		 * rotate, radian, keep original vector, return the transformed vector
		 */
		vec2_t<T> rotrad(double rad) const {
			double cosr = cos(rad), sinr = sin(rad);
			return {
				m_x * cosr - m_y * sinr
				, m_y * cosr + m_x * sinr
			};
		}
		/* 旋转，角度，原向量不变，返回变换后的向量
		 * rotate, degree, keep original vector, return the transformed vector
		 */
		vec2_t<T> rotate(double deg) const {
			return rotrad(degtorad(deg));
		}

		/* 归一化，原向量不变，返回变换后的向量
		 * normalize, keep original vector, return the transformed vector
		 */
		vec2_t<T> normalize() const {
			double len = length();
			return { m_x / len, m_y / len };
		}

		T m_x;
		T m_y;
	};

	using vec2 = vec2_t<double>;

	template<typename T>
	class rect_t {
	public:
		rect_t() = default;
		rect_t(T left, T top, T right, T bottom) { m_left = left; m_top = top; m_right = right; m_bottom = bottom; }
		rect_t(vec2_t<T> left_top, vec2_t<T> right_bottom) {
			m_left = left_top.m_x;
			m_top = left_top.m_y;
			m_right = right_bottom.m_x;
			m_bottom = right_bottom.m_y;
		}

		rect_t<T> & operator =(const rect_t<T> & r) { this->m_left = r.m_left; this->m_top = r.m_top; this->m_right = r.m_right; this->m_bottom = r.m_bottom; return * this; };
		rect_t<T> & operator +=(const rect_t<T> & r) { this->m_left += r.m_left; this->m_top += r.m_top; this->m_right += r.m_right; this->m_bottom += r.m_bottom; return * this; };
		rect_t<T> & operator -=(const rect_t<T> & r) { this->m_left -= r.m_left; this->m_top -= r.m_top; this->m_right -= r.m_right; this->m_bottom -= r.m_bottom; return * this; };

		rect_t<T> & operator +=(const vec2_t<T> & v) { this->m_left += v.m_x; this->m_top += v.m_y; this->m_right += v.m_x; this->m_bottom += v.m_y; return * this; };
		rect_t<T> & operator -=(const vec2_t<T> & v) { this->m_left -= v.m_x; this->m_top -= v.m_y; this->m_right -= v.m_x; this->m_bottom -= v.m_y; return * this; };
		
		rect_t<T> operator +(const rect_t<T> & r) const { return { this->m_left + r.m_left, this->m_top + r.m_top, this->m_right + r.m_right, this->m_bottom + r.m_bottom }; };
		rect_t<T> operator -(const rect_t<T> & r) const { return { this->m_left - r.m_left, this->m_top - r.m_top, this->m_right - r.m_right, this->m_bottom - r.m_bottom }; };
		
		rect_t<T> operator +(const vec2_t<T> & v) const { return { this->m_left + v.m_x, this->m_top + v.m_y, this->m_right + v.m_x, this->m_bottom + v.m_y }; };
		rect_t<T> operator -(const vec2_t<T> & v) const { return { this->m_left - v.m_x, this->m_top - v.m_y, this->m_right - v.m_x, this->m_bottom - v.m_y }; };

		vec2_t<T> left_top() const { return { m_left, m_top }; };
		vec2_t<T> left_bottom() const { return { m_left, m_bottom }; };
		vec2_t<T> right_top() const { return { m_right, m_top }; };
		vec2_t<T> right_bottom() const { return { m_right, m_bottom }; };

		T width() const { return std::abs(m_right - m_left); }
		T height() const { return std::abs(m_bottom - m_top); }
		vec2_t<T> size() const { return { width(), height() }; }

		T centerx() const { return m_left + (m_right - m_left) * 0.5; }
		T centery() const { return m_top + (m_bottom - m_top) * 0.5; }
		vec2_t<T> center() const { return { centerx(), centery() }; }

		/* 求对角线长度
		 * Get diagonal length
		 */
		T diagonal_length() const { T w = width(), h = height(); return sqrt(w * w + h * h); }

		/* 检测与另一点的碰撞，若碰撞则返回 true
		 * Detect collision with another point. Returns true if there is a collision
		 */
		bool collision(const vec2_t<T> & v) const { return collision(v.m_x, v.m_y); }
		/* 检测与另一点的碰撞，若碰撞则返回 true
		 * Detect collision with another point. Returns true if there is a collision
		 */
		bool collision(T x, T y) const {
			return ((m_left < m_right) ? (x >= m_left && x <= m_right) : (x <= m_left && x >= m_right))
				&& ((m_top < m_bottom) ? (y >= m_top && y <= m_bottom) : (y <= m_top && y >= m_bottom));
		}

		/* 检测与另一矩形的碰撞，若碰撞则返回 true
		 * Detect collision with another rectangle. Returns true if there is a collision
		 */
		bool collision(const rect_t<T> & rect) const { return collision(rect.m_left, rect.m_top, rect.m_right, rect.m_bottom); }
		/* 检测与另一矩形的碰撞，若碰撞则返回 true
		 * Detect collision with another rectangle. Returns true if there is a collision
		 */
		bool collision(T x1, T y1, T x2, T y2) const {
			T whalf = (x2 - x1) * 0.5;
			T hhalf = (y2 - y1) * 0.5;
			return (std::abs(centerx() - (x1 + whalf)) <= width() / 2 + std::abs(whalf))
				&& (std::abs(centery() - (y1 + hhalf)) <= height() / 2 + std::abs(hhalf));
		}

		T m_left;
		T m_top;
		T m_right;
		T m_bottom;
	};

	using rect = rect_t<double>;

}