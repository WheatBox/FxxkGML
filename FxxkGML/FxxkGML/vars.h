#pragma once

#include <string>
#include <cmath>
#include <algorithm>

#define FXXKGML_PI    3.1415926535897932
#define DEG2RAD_RATIO 0.0174532925199433
#define RAD2DEG_RATIO 57.295779513082321

namespace fgm {
	
	const int asset_object = 0;
	const int asset_sprite = 1;
	const int asset_sound = 2;
	const int asset_room = 3;
	const int asset_tiles = 9;
	const int asset_path = 5;
	const int asset_script = 6;
	const int asset_font = 7;
	const int asset_timeline = 8;
	const int asset_shader = 10;
	const int asset_animationcurve = 12;
	const int asset_sequence = 11;
	const int asset_particlesystem = 13;
	const int asset_unknown = -1;

}

namespace fgm {

	using asset = int; // Asset.xxx
	using ins_id = int; // Id.Instance
	using sndins_id = int; // Id.Sound (Sound Instance ID)

	const double pi = FXXKGML_PI;

	const ins_id self = -1;
	const ins_id other = -2;
	const ins_id all = -3;
	const ins_id noone = -4;

	const int fa_left = 0;
	const int fa_center = 1;
	const int fa_right = 2;
	
	const int fa_top = 0;
	const int fa_middle = 1;
	const int fa_bottom = 2;

	const int gamespeed_fps = 0;
	const int gamespeed_microseconds = 1;

	/* Virtual Key Constant (vk_*) */

	using vkey_t = unsigned char;
	
	const vkey_t vk_nokey = 0;
	const vkey_t vk_anykey = 1;
	const vkey_t vk_left = 37;
	const vkey_t vk_right = 39;
	const vkey_t vk_up = 38;
	const vkey_t vk_down = 40;
	const vkey_t vk_enter = 13;
	const vkey_t vk_escape = 27;
	const vkey_t vk_space = 32;
	const vkey_t vk_shift = 16;
	const vkey_t vk_control = 17;
	const vkey_t vk_alt = 18;
	const vkey_t vk_backspace = 8;
	const vkey_t vk_tab = 9;
	const vkey_t vk_home = 36;
	const vkey_t vk_end = 35;
	const vkey_t vk_delete = 46;
	const vkey_t vk_insert = 45;
	const vkey_t vk_pageup = 33;
	const vkey_t vk_pagedown = 34;
	const vkey_t vk_pause = 19;
	const vkey_t vk_printscreen = 44;
	const vkey_t vk_f1 = 112;
	const vkey_t vk_f2 = 113;
	const vkey_t vk_f3 = 114;
	const vkey_t vk_f4 = 115;
	const vkey_t vk_f5 = 116;
	const vkey_t vk_f6 = 117;
	const vkey_t vk_f7 = 118;
	const vkey_t vk_f8 = 119;
	const vkey_t vk_f9 = 120;
	const vkey_t vk_f10 = 121;
	const vkey_t vk_f11 = 122;
	const vkey_t vk_f12 = 123;
	const vkey_t vk_numpad0 = 96;
	const vkey_t vk_numpad1 = 97;
	const vkey_t vk_numpad2 = 98;
	const vkey_t vk_numpad3 = 99;
	const vkey_t vk_numpad4 = 100;
	const vkey_t vk_numpad5 = 101;
	const vkey_t vk_numpad6 = 102;
	const vkey_t vk_numpad7 = 103;
	const vkey_t vk_numpad8 = 104;
	const vkey_t vk_numpad9 = 105;
	const vkey_t vk_multiply = 106;
	const vkey_t vk_divide = 111;
	const vkey_t vk_add = 107;
	const vkey_t vk_subtract = 109;
	const vkey_t vk_decimal = 110;

	/* Virtual Key Constant (vk_*) (keyboard_check_direct only) */

	const vkey_t vk_lshift = 160;
	const vkey_t vk_lcontrol = 162;
	const vkey_t vk_lalt = 164;
	const vkey_t vk_rshift = 161;
	const vkey_t vk_rcontrol = 163;
	const vkey_t vk_ralt = 165;

	/* Mouse Button Constant */

	const int mb_left = 1;
	const int mb_middle = 3;
	const int mb_right = 2;
	const int mb_side1 = 4;
	const int mb_side2 = 5;
	const int mb_any = -1;
	const int mb_none = 0;

}

/* ------------ color things ------------ */

namespace fgm {

	/* ----------------------------- */

	using color_t = unsigned int;

	class color_rgb;
	class color_bgr;
	class color_hsv;
	
	// TODO - merge_color();

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
		operator color_bgr() const;
		operator color_hsv() const;

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
		color_bgr(const color_rgb & rgb);
		color_bgr(const color_hsv & hsv);

		color_bgr & operator =(const int & bgrhex) { set(bgrhex); return * this; }
		color_bgr & operator =(const color_t & bgrhex) { set(bgrhex); return * this; }
		color_bgr & operator =(const color_rgb & rgb) { set(rgb); return * this; }
		color_bgr & operator =(const color_hsv & hsv) { set(hsv); return * this; }
		
		operator int() const { return m_bgr; }
		operator color_t() const { return m_bgr; }
		operator color_rgb() const;
		operator color_hsv() const;

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

		color_rgb to_rgb() const;
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

		operator color_rgb() const;
		operator color_bgr() const;

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

	// 在 GameMaker 中，颜色默认都是以 BGR 的形式存在的
	// In GameMaker, colors default to exist in the form of BGR
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
