#include "vars.h"

namespace fgm {

/* ------ class color_rgb/bgr/hsv ------ */
#pragma region __CLASS_COLOR_RGB_BGR_HSV__

	/* rgb */

	color_rgb::color_rgb(const color_bgr & bgr) {
		set(bgr);
	}

	color_rgb::color_rgb(const color_hsv & hsv) {
		set(hsv);
	}

	color_rgb::operator color_bgr() const { return to_bgr(); }

	color_rgb::operator color_hsv() const { return to_hsv(); }

	void color_rgb::set(const color_bgr & bgr) {
		set(bgr.getr(), bgr.getg(), bgr.getb());
	}

	void color_rgb::set(const color_hsv & hsv) {
		* this = hsv.to_rgb();
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

	/* bgr */

	color_bgr::color_bgr(const color_rgb & rgb) {
		set(rgb);
	}

	color_bgr::color_bgr(const color_hsv & hsv) {
		set(hsv);
	}

	color_bgr::operator color_rgb() const { return to_rgb(); }

	color_bgr::operator color_hsv() const { return to_hsv(); }

	void color_bgr::set(const color_rgb & rgb) {
		set(rgb.getb(), rgb.getg(), rgb.getr());
	}
	
	void color_bgr::set(const color_hsv & hsv) {
		* this = hsv.to_bgr();
	}

	color_rgb color_bgr::to_rgb() const {
		return { m_r, m_g, m_b };
	}

	color_hsv color_bgr::to_hsv() const {
		return to_rgb().to_hsv();
	}

	/* hsv */

	color_hsv::color_hsv(const color_rgb & rgb) {
		set(rgb);
	}

	color_hsv::color_hsv(const color_bgr & bgr) {
		set(bgr);
	}

	color_hsv::operator color_rgb() const { return to_rgb(); }

	color_hsv::operator color_bgr() const { return to_bgr(); }

	void color_hsv::set(const color_rgb & rgb) {
		* this = rgb.to_hsv();
	}

	void color_hsv::set(const color_bgr & bgr) {
		* this = bgr.to_hsv();
	}

	color_rgb color_hsv::to_rgb() const {
		double v = static_cast<double>(m_v) / 100.0;
		double s = static_cast<double>(m_s) / 100.0;

		double h_div_60 = m_h / 60.0;
		int i = floor(h_div_60);
		double f = h_div_60 - static_cast<double>(i);

		int resp = round(v * (1.0 - s) * 255.0);
		int resq = round(v * (1.0 - f * s) * 255.0);
		int rest = round(v * (1.0 - (1.0 - f) * s) * 255.0);
		int resv = round(v * 255.0);

		switch(i) {
			case 0:
			return { resv, rest, resp };
			case 1:
			return { resq, resv, resp };
			case 2:
			return { resp, resv, rest };
			case 3:
			return { resp, resq, resv };
			case 4:
			return { rest, resp, resv };
			case 5:
			return { resv, resp, resq };
		}

		return {};
	}

	color_bgr color_hsv::to_bgr() const { return to_rgb().to_bgr(); }

#pragma endregion __CLASS_COLOR_RGB_BGR_HSV__

};
