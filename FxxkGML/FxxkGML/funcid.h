#pragma once

namespace fgm {
	enum class __FuncId {
		nothing = 0,

		__instance_getdepth = 1001,
		__instance_setdepth = 1002,
		__instance_getx = 1003,
		__instance_gety = 1004,
		__instance_getpos = 1005,
		__instance_setx = 1006,
		__instance_sety = 1007,
		__instance_setpos = 1008,

		/* instance.h 2000+ */

		instance_create_layer = 2001,
		instance_create_depth = 2002,
		instance_destroy = 2003,
		instance_exists = 2004,
		instance_change = 2005,
		instance_copy = 2006,
		instance_find = 2007,
		instance_furthest = 2008,
		instance_nearest = 2009,
		instance_number = 2010,
		instance_place = 2011,
		instance_place_list = 2012,
		instance_position = 2013,
		instance_position_list = 2014,
		instance_id_get = 2015,
		instance_count_get = 2016,
		instance_activate_all = 2017,
		instance_activate_object = 2018,
		instance_activate_region = 2019,
		instance_activate_layer = 2020,
		instance_deactivate_all = 2021,
		instance_deactivate_object = 2022,
		instance_deactivate_region = 2023,
		instance_deactivate_layer = 2024,

		draw_text = 10001,
		random_range = 10002,
		asset_get_index = 10003,
		draw_sprite_ext = 10004,
	};
}