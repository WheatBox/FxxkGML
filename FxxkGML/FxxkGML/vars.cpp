#include "vars.h"

namespace fgm {

/* ------ class color_rgb/bgr/hsv ------ */
#pragma region __CLASS_COLOR_RGB_BGR_HSV__

	color_rgb::color_rgb(const color_bgr & bgr) {
		set(bgr);
	}

	color_rgb::color_rgb(const color_hsv & hsv) {
		set(hsv);
	}

	void color_rgb::set(const color_bgr & bgr) {
		set(bgr.getr(), bgr.getg(), bgr.getb());
	}

	void color_rgb::set(const color_hsv & hsv) {
		// TODO
	}

	color_bgr color_rgb::to_bgr() const {
		return { m_b, m_g, m_r };
	}

	color_hsv color_rgb::to_hsv() const {
		double r1 = static_cast<double>(m_r) / 255.0;
		double g1 = static_cast<double>(m_g) / 255.0;
		double b1 = static_cast<double>(m_b) / 255.0;
		
		double v = std::max({ r1, g1, b1 });
		double v_minus_min = v - std::min({ r1, g1, b1 });

		double s = (v == 0) ? 0 : (v_minus_min / v);

		int h = 0;

		if(v_minus_min == 0) {

		} else
		if(v == r1) {
			h = 60.0 * (g1 - b1) / v_minus_min;
		} else if(v == g1) {
			h = 120.0 + 60.0 * (b1 - r1) / v_minus_min;
		} else {
			h = 240.0 + 60.0 * (r1 - g1) / v_minus_min;
		}

		if(h < 0) {
			h += 360;
		}

		return color_hsv(h, round(s * 100.0), round(v * 100.0));
	}

#pragma endregion __CLASS_COLOR_RGB_BGR_HSV__

};
