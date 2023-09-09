#pragma once

#include <string>
#include <cmath>
#include <algorithm>

#define FXXKGML_PI    3.1415926535897932
#define DEG2RAD_RATIO 0.0174532925199433
#define RAD2DEG_RATIO 57.295779513082321

namespace fgm {

	const double pi = FXXKGML_PI;

	const int self = -1;
	const int other = -2;
	const int all = -3;
	const int noone = -4;

}

/* ------------ color things ------------ */

namespace fgm {

	/* ----------------------------- */

	using color_t = unsigned int;

	class color_rgb;
	class color_bgr;
	class color_hsv;

	/* ------ class color_rgb ------ */

	class color_rgb {
	public:
		color_rgb() { m_r = 0; m_g = 0; m_b = 0; m_rgb = 0; }
		color_rgb(int r, int g, int b) { m_r = r; m_g = g; m_b = b; unite(); }
		color_rgb(int rgbhex) { set(rgbhex); }
		color_rgb(color_t rgbhex) { set(rgbhex); }
		color_rgb(const color_bgr & bgr);
		color_rgb(const color_hsv & hsv);

		color_rgb & operator =(const int & rgbhex) { set(rgbhex); return * this; }
		color_rgb & operator =(const color_t & rgbhex) { set(rgbhex); return * this; }
		color_rgb & operator =(const color_bgr & bgr) { set(bgr); return * this; }
		color_rgb & operator =(const color_hsv & hsv) { set(hsv); return * this; }

		operator int() const { return m_rgb; }
		operator color_t() const { return m_rgb; }

		int getr() const { return m_r; }
		int getg() const { return m_g; }
		int getb() const { return m_b; }
		color_t get() const { return m_rgb; }

		void setr(int r) { m_r = r; unite(); }
		void setg(int g) { m_g = g; unite(); }
		void setb(int b) { m_b = b; unite(); }
		void set(int r, int g, int b) { m_r = r; m_g = g; m_b = b; unite(); }
		void set(color_t rgbhex) { m_rgb = rgbhex; split(); }
		
		void set(const color_bgr & bgr);
		void set(const color_hsv & hsv);

		color_bgr to_bgr() const;
		color_hsv to_hsv() const;

	private:

		void unite() {
			m_rgb = (m_r << 16) | (m_g << 8) | m_b;
		}

		void split() {
			m_r = (m_rgb >> 16) & 0b11111111;
			m_g = (m_rgb >> 8) & 0b11111111;
			m_b = (m_rgb) & 0b11111111;
		}

	private:
		int m_r; // 0 ~ 255
		int m_g; // 0 ~ 255
		int m_b; // 0 ~ 255
		color_t m_rgb; // 0x000000 ~ 0xffffff
	};

	/* ------ class color_bgr ------ */

	class color_bgr {
	public:
		color_bgr() { m_b = 0; m_g = 0; m_r = 0; m_bgr = 0; }
		color_bgr(int b, int g, int r) { m_b = b; m_g = g; m_r = r; unite(); }
		color_bgr(int bgrhex) { set(bgrhex); }
		color_bgr(color_t bgrhex) { set(bgrhex); }
		color_bgr(const color_rgb & bgr);
		color_bgr(const color_hsv & hsv);

		color_bgr & operator =(const int & bgrhex) { set(bgrhex); return * this; }
		color_bgr & operator =(const color_t & bgrhex) { set(bgrhex); return * this; }
		color_bgr & operator =(const color_rgb & rgb) { set(rgb); return * this; }
		color_bgr & operator =(const color_hsv & hsv) { set(hsv); return * this; }
		
		operator int() const { return m_bgr; }
		operator color_t() const { return m_bgr; }

		int getb() const { return m_b; }
		int getg() const { return m_g; }
		int getr() const { return m_r; }
		color_t get() const { return m_bgr; }

		void setb(int b) { m_b = b; unite(); }
		void setg(int g) { m_g = g; unite(); }
		void setr(int r) { m_r = r; unite(); }
		void set(int b, int g, int r) { m_b = b; m_g = g; m_r = r; unite(); }
		void set(color_t bgrhex) { m_bgr = bgrhex; split(); }

		void set(const color_rgb & rgb);
		void set(const color_hsv & hsv);

		color_bgr to_bgr() const;
		color_hsv to_hsv() const;

	private:

		void unite() {
			m_bgr = (m_b << 16) | (m_g << 8) | m_r;
		}

		void split() {
			m_b = (m_bgr >> 16) & 0b11111111;
			m_g = (m_bgr >> 8) & 0b11111111;
			m_r = (m_bgr) & 0b11111111;
		}

	private:
		int m_b; // 0 ~ 255
		int m_g; // 0 ~ 255
		int m_r; // 0 ~ 255
		color_t m_bgr; // 0x000000 ~ 0xffffff
	};

	/* ------ class color_hsv ------ */

	class color_hsv {
	public:
		color_hsv() { m_h = 0; m_s = 0; m_v = 0; }
		color_hsv(int h, int s, int v) { m_h = h; m_s = s; m_v = v; }
		color_hsv(const color_rgb & rgb);
		color_hsv(const color_bgr & bgr);

		color_hsv & operator =(const color_rgb & rgb) { set(rgb); return * this; }
		color_hsv & operator =(const color_bgr & bgr) { set(bgr); return * this; }

		int geth() const { return m_h; }
		int gets() const { return m_s; }
		int getv() const { return m_v; }

		void seth(int h) { m_h = h; }
		void sets(int s) { m_s = s; }
		void setv(int v) { m_v = v; }
		void set(int h, int s, int v) { m_h = h; m_s = s; m_v = v; }

		void set(const color_rgb & rgb);
		void set(const color_bgr & bgr);

		color_rgb to_rgb() const;
		color_bgr to_bgr() const;

	private:
		int m_h; // 0 ~ 359
		int m_s; // 0 ~ 100
		int m_v; // 0 ~ 100
	};

	const color_bgr c_aqua     = 16776960;
	const color_bgr c_black    = 0;
	const color_bgr c_blue     = 16711680;
	const color_bgr c_dkgray   = 4210752;
	const color_bgr c_fuchsia  = 16711935;
	const color_bgr c_gray     = 8421504;
	const color_bgr c_green    = 32768;
	const color_bgr c_lime     = 65280;
	const color_bgr c_ltgray   = 12632256;
	const color_bgr c_maroon   = 128;
	const color_bgr c_navy     = 8388608;
	const color_bgr c_olive    = 32896;
	const color_bgr c_orange   = 4235519;
	const color_bgr c_purple   = 8388736;
	const color_bgr c_red      = 255;
	const color_bgr c_silver   = 12632256;
	const color_bgr c_teal     = 8421376;
	const color_bgr c_white    = 16777215;
	const color_bgr c_yellow   = 65535;

}
