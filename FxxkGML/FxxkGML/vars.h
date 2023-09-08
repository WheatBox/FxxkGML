#pragma once

#include <string>

#define FXXKGML_PI    3.1415926535897932
#define DEG2RAD_RATIO 0.0174532925199433
#define RAD2DEG_RATIO 57.295779513082321

namespace fgm {

	const double pi = FXXKGML_PI;

	const int self = -1;
	const int other = -2;
	const int all = -3;
	const int noone = -4;

	using color_t = unsigned int;

	const color_t c_aqua     = 16776960;
	const color_t c_black    = 0;
	const color_t c_blue     = 16711680;
	const color_t c_dkgray   = 4210752;
	const color_t c_fuchsia  = 16711935;
	const color_t c_gray     = 8421504;
	const color_t c_green    = 32768;
	const color_t c_lime     = 65280;
	const color_t c_ltgray   = 12632256;
	const color_t c_maroon   = 128;
	const color_t c_navy     = 8388608;
	const color_t c_olive    = 32896;
	const color_t c_orange   = 4235519;
	const color_t c_purple   = 8388736;
	const color_t c_red      = 255;
	const color_t c_silver   = 12632256;
	const color_t c_teal     = 8421376;
	const color_t c_white    = 16777215;
	const color_t c_yellow   = 65535;

}
