#pragma once

namespace fgm {
	enum class __FuncId {

	/* FxxkGML Control 0 ~ 99 */
		
		nothing = 0,
		
		FxxkGML_Init = 1,
		FxxkGML_Main = 2,
		FxxkGML_Assistant = 3,
		FxxkGML_GetVersion = 4,

	/* miscellaneous.h 100 ~ 999 */

		delta_time_get = 101,

		game_save_id_get = 102,
		game_display_name_get = 103,
		game_project_name_get = 104,
		game_end = 105,
		game_restart = 106,
		game_change = 107,
		game_load_buffer = 108,
		game_save_buffer = 109,
		game_set_speed = 110,
		game_get_speed = 111,

		highscore_add = 112,
		highscore_name = 113,
		highscore_value = 114,
		highscore_clear = 115,

		cursor_sprite_get = 116,
		cursor_sprite_set = 117,

		asset_get_index = 118,
		asset_get_type = 119,

		// variable_instance_get_names = 120,
		// variable_instance_names_count = 121,
		variable_instance_exists = 122,
		variable_instance_get_real = 123,
		variable_instance_get_string = 124,
		variable_instance_set_real = 125,
		variable_instance_set_string = 126,
		variable_global_exists = 127,
		variable_global_get_real = 128,
		variable_global_get_string = 129,
		variable_global_set_real = 130,
		variable_global_set_string = 131,

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
		cinstance_getvisible = -1010,
		cinstance_setvisible = -1011,
		cinstance_getsolid = -1012,
		cinstance_setsolid = -1013,
		cinstance_getpersistent = -1014,
		cinstance_setpersistent = -1015,
		cinstance_getspr = -1016,
		cinstance_setspr = -1017,
		cinstance_getmask = -1018,
		cinstance_setmask = -1019,
		cinstance_getsprwidth = -1020,
		cinstance_getsprheight = -1021,
		cinstance_getsprsize = -1022,
		cinstance_getsprxoff = -1023,
		cinstance_getspryoff = -1024,
		cinstance_getsproffset = -1025,
		cinstance_getimgalpha = -1026,
		cinstance_setimgalpha = -1027,
		cinstance_getimgangle = -1028,
		cinstance_setimgangle = -1029,
		cinstance_getimgblend = -1030,
		cinstance_setimgblend = -1031,
		cinstance_getimgxscale = -1032,
		cinstance_setimgxscale = -1033,
		cinstance_getimgyscale = -1034,
		cinstance_setimgyscale = -1035,
		cinstance_getimgscale = -1036,
		cinstance_setimgscale = -1037,
		cinstance_getimgindex = -1038,
		cinstance_setimgindex = -1039,
		cinstance_getimgspeed = -1040,
		cinstance_setimgspeed = -1041,
		cinstance_getimgnumber = -1042,
		cinstance_getbboxlocal = -1043,
		cinstance_getlayer = -1044,
		cinstance_setlayer = -1045,

		cinstance___init = -1999,

	/* draw.h 1000+ */

		draw_enable_drawevent = 1998,
		draw_flush = 1999,

		// Colour And Alpha

		draw_getpixel = 1001,
		// draw_getpixel_ext = 1002,
		draw_get_colour = 1003,
		draw_get_alpha = 1004,
		draw_clear = 1005,
		draw_clear_alpha = 1006,
		draw_set_alpha = 1007,
		draw_set_colour = 1008,

		// Basic Forms
		
		draw_arrow = 1009,
		draw_circle = 1010,
		draw_circle_colour = 1011,
		draw_ellipse = 1012,
		draw_ellipse_colour = 1013,
		draw_line = 1014,
		draw_line_colour = 1015,
		draw_line_width = 1016,
		draw_line_width_colour = 1017,
		draw_point = 1018,
		draw_point_colour = 1019,
		draw_rectangle = 1020,
		draw_rectangle_colour = 1021,
		draw_roundrect = 1022,
		draw_roundrect_colour = 1023,
		draw_roundrect_ext = 1024,
		draw_roundrect_colour_ext = 1025,
		draw_triangle = 1026,
		draw_triangle_colour = 1027,
		draw_set_circle_precision = 1028,
		// draw_button = 1029,
		// draw_healthbar = 1030,
		draw_path = 1031,

		// Sprites And Tiles

		draw_self = 1032,
		draw_sprite = 1033,
		draw_sprite_ext = 1034,
		draw_sprite_general = 1035,
		draw_sprite_part = 1036,
		draw_sprite_part_ext = 1037,
		draw_sprite_stretched = 1038,
		draw_sprite_stretched_ext = 1039,
		draw_sprite_pos = 1040,
		draw_sprite_tiled = 1041,
		draw_sprite_tiled_ext = 1042,
		draw_enable_swf_aa = 1043,
		draw_set_swf_aa_level = 1044,
		draw_get_swf_aa_level = 1045,
		draw_skeleton = 1046,
		draw_skeleton_instance = 1047,
		draw_skeleton_collision = 1048,
		draw_skeleton_time = 1049,
		draw_tile = 1050,
		draw_tilemap = 1051,

		// Text

		draw_set_font = 1052,
		draw_set_halign = 1053,
		draw_set_valign = 1054,
		draw_get_font = 1055,
		draw_get_halign = 1056,
		draw_get_valign = 1057,
		draw_text = 1058,
		draw_text_ext = 1059,
		draw_text_colour = 1060,
		draw_text_transformed = 1061,
		draw_text_ext_colour = 1062,
		draw_text_ext_transformed = 1063,
		draw_text_transformed_colour = 1064,
		draw_text_ext_transformed_colour = 1065,
		draw_highscore = 1066,

	/* instance.h 2000+ */

		instance_create_layer = 2001,
		instance_create_layer__str = 2002,
		instance_create_depth = 2003,
		instance_destroy = 2004,
		instance_exists = 2005,
		// instance_change = 2005,
		// instance_copy = 2006,
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
		instance_activate_layer__str = 2021,
		instance_deactivate_all = 2022,
		instance_deactivate_object = 2023,
		instance_deactivate_region = 2024,
		instance_deactivate_layer = 2025,
		instance_deactivate_layer__str = 2026,
		instance_get = 2027,

	/* layer.h 3000+ */
	// TODO
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

	/* game_input.h 4000+ */

		// Keyboard Input

		io_clear = 4001,
		keyboard_check = 4002,
		keyboard_check_pressed = 4003,
		keyboard_check_released = 4004,
		keyboard_check_direct = 4005,
		keyboard_clear = 4006,
		keyboard_set_map = 4007,
		keyboard_get_map = 4008,
		keyboard_unset_map = 4009,
		keyboard_set_numlock = 4010,
		keyboard_get_numlock = 4011,
		keyboard_key_press = 4012,
		keyboard_key_release = 4013,

		keyboard_key_get = 4014,
		keyboard_lastkey_get = 4015,
		keyboard_lastchar_get = 4016,
		keyboard_string_get = 4017,
		keyboard_key_set = 4018,
		keyboard_lastkey_set = 4019,
		keyboard_lastchar_set = 4020,
		keyboard_string_set = 4021,

		// Mouse Input

		mouse_button_get = 4022,
		mouse_button_set = 4023,
		mouse_check_button = 4024,
		mouse_check_button_pressed = 4025,
		mouse_check_button_released = 4026,
		mouse_clear = 4027,
		mouse_lastbutton_get = 4028,
		mouse_lastbutton_set = 4029,
		mouse_wheel_up = 4030,
		mouse_wheel_down = 4031,
		mouse_x_get = 4032,
		mouse_y_get = 4033,
		mouse_pos_get = 4034,

		window_mouse_get_x = 4035,
		window_mouse_get_y = 4036,
		window_mouse_get_pos = 4037,
		window_mouse_set = 4038,
		window_view_mouse_get_x = 4039,
		window_view_mouse_get_y = 4040,
		window_view_mouse_get_pos = 4041,
		window_views_mouse_get_x = 4042,
		window_views_mouse_get_y = 4043,
		window_views_mouse_get_pos = 4044,

		// Device Input

		device_mouse_check_button = 4045,
		device_mouse_check_button_pressed = 4046,
		device_mouse_check_button_released = 4047,
		device_mouse_dbclick_enable = 4048,
		device_mouse_x = 4049,
		device_mouse_y = 4050,
		device_mouse_pos = 4051,
		device_mouse_raw_x = 4052,
		device_mouse_raw_y = 4053,
		device_mouse_raw_pos = 4054,
		device_mouse_x_to_gui = 4055,
		device_mouse_y_to_gui = 4056,
		device_mouse_pos_to_gui = 4057,
		device_is_keypad_open = 4058,
		device_get_tilt_x = 4059,
		device_get_tilt_y = 4060,
		device_get_tilt_z = 4061,

	/* debug.h 5000+ */

		// debug_mode = 5001,
		// debug_event = 5002,
		// debug_get_callstack = 5003,
		// exception_unhandled_handler = 5004,
		// get_integer = 5005,
		// get_string = 5006,
		show_error = 5007,
		show_message = 5008,
		show_question = 5009,
		show_debug_message = 5010,
		// show_debug_message_ext = 5011,
		code_is_compiled = 5012,
		fps_get = 5013,
		fps_real_get = 5014,

		// Toggling

		show_debug_overlay = 5015,
		show_debug_log = 5016,
		is_debug_overlay_open = 5017,

		// Views // TODO

		dbg_view = 5018,
		dbg_view_delete = 5019,
		dbg_section = 5020,
		dbg_section_delete = 5021,

		// Controls // TODO

		dbg_button = 5022,
		dbg_checkbox = 5023,
		dbg_colour = 5024,
		dbg_drop_down = 5025,
		dbg_same_line = 5026,
		dbg_slider = 5027,
		dbg_sprite = 5028,
		dbg_text = 5029,
		dbg_text_input = 5030,
		dbg_watch = 5031,

	/* audio.h 6000+ */

		// Asset Info

		audio_exists = 6001,
		audio_get_name = 6002,
		audio_get_type = 6003,
		audio_sound_length = 6004,
		audio_sound_is_playable = 6005,

		// Playing Sounds

		audio_play_sound = 6006,
		audio_play_sound__fullargs = 6007,
		// audio_play_sound_ext = 6008, // TODO
		audio_play_sound_at = 6009,
		audio_play_sound_at__fullargs = 6010,
		audio_pause_sound = 6011,
		audio_pause_all = 6012,
		audio_resume_sound = 6013,
		audio_resume_all = 6014,
		audio_stop_sound = 6015,
		audio_stop_all = 6016,
		audio_is_playing = 6017,
		audio_is_paused = 6018,

		/*// Audio Properties
		
		audio_sound_gain
		audio_sound_get_gain
		audio_sound_pitch
		audio_sound_get_pitch
		audio_sound_set_track_position
		audio_sound_get_track_position
		audio_sound_set_listener_mask
		audio_sound_get_listener_mask

		// Audio Loop Points

		audio_sound_loop
		audio_sound_get_loop
		audio_sound_loop_start
		audio_sound_get_loop_start
		audio_sound_loop_end
		audio_sound_get_loop_end
		
		// Configuration
		
		audio_master_gain
		audio_set_master_gain
		audio_get_master_gain
		audio_channel_num
		audio_falloff_set_model
		audio_system_is_available
		audio_system_is_initialised
		
		// Debugging

		audio_debug

		// Gain Conversion
		
		lin_to_db
		db_to_lin*/
		
		// Audio Streams

		audio_create_stream = 6043,
		audio_destroy_stream = 6044,

	/* sprite.h 7000+ */

		sprite_exists = 7001,
		sprite_get_name = 7002,
		sprite_get_number = 7003,
		sprite_get_speed = 7004,
		sprite_get_speed_type = 7005,
		sprite_get_width = 7006,
		sprite_get_height = 7007,
		sprite_get_size = 7008,
		sprite_get_xoffset = 7009,
		sprite_get_yoffset = 7010,
		sprite_get_offset = 7011,
		sprite_get_bbox_bottom = 7012,
		sprite_get_bbox_left = 7013,
		sprite_get_bbox_right = 7014,
		sprite_get_bbox_top = 7015,
		sprite_get_bbox = 7016,
		sprite_get_bbox_mode = 7017,
		// sprite_get_nineslice = 7018, // TODO
		// sprite_get_tpe = 7019, // HTML5 only

		// TODO
		// sprite_get_texture = 7020,
		// sprite_get_uvs = 7021,
		// sprite_get_info = 7022,

		// Asset Properties
		
		sprite_collision_mask = 7023,
		sprite_set_offset = 7024,
		sprite_set_bbox_mode = 7025,
		sprite_set_bbox = 7026,
		sprite_set_speed = 7027,
		// sprite_set_nineslice = 7028, // TODO
		
		// Creating & Modifying Sprites
		
		sprite_add = 7029,
		// sprite_add_ext = 7030, // TODO
		sprite_delete = 7031,
		sprite_replace = 7032,
		sprite_duplicate = 7033,
		sprite_assign = 7034,
		sprite_merge = 7035,
		sprite_set_alpha_from_sprite = 7036,
		// sprite_nineslice_create = 7037,
		sprite_create_from_surface = 7038,
		sprite_add_from_surface = 7039,
		
		// Saving Sprites
		
		sprite_save = 7040,
		sprite_save_strip = 7041,
		
		// Blending (HTML5)
		
		// sprite_set_cache_size
		// sprite_set_cache_size_ext
		
		// Prefetching
		
		sprite_prefetch = 7042,
		// sprite_prefetch_multi = 7043, // TODO
		sprite_flush = 7044,
		// sprite_flush_multi = 7045, // TODO

	/* font.h 8000+ */

		// Asset Info

		font_exists = 8001,
		font_get_name = 8002,
		font_get_fontname = 8003,
		font_get_first = 8004,
		font_get_last = 8005,
		font_get_italic = 8006,
		font_get_bold = 8007,
		font_get_size = 8008,
		font_get_info = 8009,
		
		// Texture
		// TODO

		// font_get_texture = 8010,
		// font_get_uvs = 8011,
		// font_cache_glyph = 8012,
		
		//  Adding/Removing Fonts

		font_add = 8013,
		font_add_sprite = 8014,
		font_add_sprite_ext = 8015,
		font_replace_sprite = 8016,
		font_replace_sprite_ext = 8017,
		font_delete = 8018,
		
		// Configuration

		font_texture_page_size = 8019,
		font_set_cache_size = 8020,
		font_add_enable_aa = 8021,
		font_add_get_enable_aa = 8022,
		
		// SDF

		font_enable_sdf = 8023,
		font_get_sdf_enabled = 8024,
		font_sdf_spread = 8025,
		font_get_sdf_spread = 8026,
		font_enable_effects = 8027,

	};
}