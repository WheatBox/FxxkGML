#pragma once

namespace fgm {
	enum class __FuncId {
		nothing = 0,

		/* class instance -1000+ */

		cinstance_getdepth = -1001,
		cinstance_setdepth = -1002,
		cinstance_getx = -1003,
		cinstance_gety = -1004,
		cinstance_getpos = -1005,
		cinstance_setx = -1006,
		cinstance_sety = -1007,
		cinstance_setpos = -1008,
		cinstance_getobj = -1009,

		/* draw.h 1000+ */

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

		/* layer.h 3000+ */

		layer_exists = 3001,
		layer_exists__id = 3002,
		// layer_get_id = 3003,
		layer_get = 3004,
		layer_get__id = 3005,
		layer_get_depth = 3006,
		layer_get_id_at_depth = 3007,
		// layer_get_name = 3008,
		layer_get_all = 3009,
		layer_get_all_elements = 3010,
		layer_get_element_layer = 3011,
		layer_get_element_type = 3012,
		layer_get_x = 3013,
		layer_get_y = 3014,
		layer_get_hspeed = 3015,
		layer_get_vspeed = 3016,
		layer_create = 3017,
		layer_destroy = 3018,
		layer_x = 3019,
		layer_y = 3020,
		layer_hspeed = 3021,
		layer_vspeed = 3022,
		layer_add_instance = 3023,
		layer_has_instance = 3024,
		layer_instance_get_instance = 3024,
		layer_destroy_instances = 3025,
		layer_element_move = 3026,
		layer_set_visible = 3027,
		layer_get_visible = 3028,
		layer_depth = 3029,
		layer_force_draw_depth = 3030,
		layer_is_draw_depth_forced = 3031,
		layer_get_forced_depth = 3032,
		layer_script_begin = 3033,
		layer_script_end = 3034,
		layer_shader = 3035,
		layer_get_script_begin = 3036,
		layer_get_script_end = 3037,
		layer_get_shader = 3038,
		layer_set_target_room = 3039,
		layer_get_target_room = 3040,
		layer_reset_target_room = 3041,

		draw_text = 10001,
		random_range = 10002,
		asset_get_index = 10003,
		draw_sprite_ext = 10004,
	};
}