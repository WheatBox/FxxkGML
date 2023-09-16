#macro FGM_VERSION_LEFT 0
#macro FGM_VERSION_MID 0
#macro FGM_VERSION_RIGHT 1

enum EFxxkGMLFuncId {
	_nothing = 0,
	
/* miscellaneous.h 100 ~ 999 */

	_delta_time_get = 101,

	_game_save_id_get = 102,
	_game_display_name_get = 103,
	_game_project_name_get = 104,
	_game_end = 105,
	_game_restart = 106,
	_game_change = 107,
	_game_load_buffer = 108,
	_game_save_buffer = 109,
	_game_set_speed = 110,
	_game_get_speed = 111,

	_highscore_add = 112,
	_highscore_name = 113,
	_highscore_value = 114,
	_highscore_clear = 115,

	_cursor_sprite_get = 116,
	_cursor_sprite_set = 117,
	
	_asset_get_index = 118,
	_asset_get_type = 119,
	
/* class instance -1000+ */
	
	_cinstance_getdepth = -1001,
	_cinstance_setdepth = -1002,
	_cinstance_getx = -1003,
	_cinstance_gety = -1004,
	_cinstance_getpos = -1005,
	_cinstance_setx = -1006,
	_cinstance_sety = -1007,
	_cinstance_setpos = -1008,
	_cinstance_getobj = -1009,
	_cinstance_getvisible = -1010,
	_cinstance_setvisible = -1011,
	_cinstance_getsolid = -1012,
	_cinstance_setsolid = -1013,
	_cinstance_getpersistent = -1014,
	_cinstance_setpersistent = -1015,
	_cinstance_getspr = -1016,
	_cinstance_setspr = -1017,
	_cinstance_getmask = -1018,
	_cinstance_setmask = -1019,
	_cinstance_getsprwidth = -1020,
	_cinstance_getsprheight = -1021,
	_cinstance_getsprsize = -1022,
	_cinstance_getsprxoff = -1023,
	_cinstance_getspryoff = -1024,
	_cinstance_getsproffset = -1025,
	_cinstance_getimgalpha = -1026,
	_cinstance_setimgalpha = -1027,
	_cinstance_getimgangle = -1028,
	_cinstance_setimgangle = -1029,
	_cinstance_getimgblend = -1030,
	_cinstance_setimgblend = -1031,
	_cinstance_getimgxscale = -1032,
	_cinstance_setimgxscale = -1033,
	_cinstance_getimgyscale = -1034,
	_cinstance_setimgyscale = -1035,
	_cinstance_getimgscale = -1036,
	_cinstance_setimgscale = -1037,
	_cinstance_getimgindex = -1038,
	_cinstance_setimgindex = -1039,
	_cinstance_getimgspeed = -1040,
	_cinstance_setimgspeed = -1041,
	_cinstance_getimgnumber = -1042,
	_cinstance_getbboxlocal = -1043,
	_cinstance_getlayer = -1044,
	_cinstance_setlayer = -1045,
	
	_cinstance___init = -1999,
	
/* draw.h 1000+ */

	_draw_enable_drawevent = 1998,
	_draw_flush = 1999,

	// Colour And Alpha
	
	_draw_getpixel = 1001,
	// _draw_getpixel_ext = 1002,
	_draw_get_colour = 1003,
	_draw_get_alpha = 1004,
	_draw_clear = 1005,
	_draw_clear_alpha = 1006,
	_draw_set_alpha = 1007,
	_draw_set_colour = 1008,
	
	// Basic Forms
		
	_draw_arrow = 1009,
	_draw_circle = 1010,
	_draw_circle_colour = 1011,
	_draw_ellipse = 1012,
	_draw_ellipse_colour = 1013,
	_draw_line = 1014,
	_draw_line_colour = 1015,
	_draw_line_width = 1016,
	_draw_line_width_colour = 1017,
	_draw_point = 1018,
	_draw_point_colour = 1019,
	_draw_rectangle = 1020,
	_draw_rectangle_colour = 1021,
	_draw_roundrect = 1022,
	_draw_roundrect_colour = 1023,
	_draw_roundrect_ext = 1024,
	_draw_roundrect_colour_ext = 1025,
	_draw_triangle = 1026,
	_draw_triangle_colour = 1027,
	_draw_set_circle_precision = 1028,
	// _draw_button = 1029,
	// _draw_healthbar = 1030,
	_draw_path = 1031,
	
	// Sprites And Tiles
	
	_draw_self = 1032,
	_draw_sprite = 1033,
	_draw_sprite_ext = 1034,
	_draw_sprite_general = 1035,
	_draw_sprite_part = 1036,
	_draw_sprite_part_ext = 1037,
	_draw_sprite_stretched = 1038,
	_draw_sprite_stretched_ext = 1039,
	_draw_sprite_pos = 1040,
	_draw_sprite_tiled = 1041,
	_draw_sprite_tiled_ext = 1042,
	_draw_enable_swf_aa = 1043,
	_draw_set_swf_aa_level = 1044,
	_draw_get_swf_aa_level = 1045,
	_draw_skeleton = 1046,
	_draw_skeleton_instance = 1047,
	_draw_skeleton_collision = 1048,
	_draw_skeleton_time = 1049,
	_draw_tile = 1050,
	_draw_tilemap = 1051,
	
	// Text
	
	_draw_set_font = 1052,
	_draw_set_halign = 1053,
	_draw_set_valign = 1054,
	_draw_get_font = 1055,
	_draw_get_halign = 1056,
	_draw_get_valign = 1057,
	_draw_text = 1058,
	_draw_text_ext = 1059,
	_draw_text_colour = 1060,
	_draw_text_transformed = 1061,
	_draw_text_ext_colour = 1062,
	_draw_text_ext_transformed = 1063,
	_draw_text_transformed_colour = 1064,
	_draw_text_ext_transformed_colour = 1065,
	_draw_highscore = 1066,
	
/* instance.h 2000+ */
	
	_instance_create_layer = 2001,
	_instance_create_layer__str = 2002,
	_instance_create_depth = 2003,
	_instance_destroy = 2004,
	_instance_exists = 2005,
	_instance_find = 2007,
	_instance_furthest = 2008,
	_instance_nearest = 2009,
	_instance_number = 2010,
	_instance_place = 2011,
	_instance_place_list = 2012,
	_instance_position = 2013,
	_instance_position_list = 2014,
	_instance_id_get = 2015,
	_instance_count_get = 2016,
	_instance_activate_all = 2017,
	_instance_activate_object = 2018,
	_instance_activate_region = 2019,
	_instance_activate_layer = 2020,
	_instance_activate_layer__str = 2021,
	_instance_deactivate_all = 2022,
	_instance_deactivate_object = 2023,
	_instance_deactivate_region = 2024,
	_instance_deactivate_layer = 2025,
	_instance_deactivate_layer__str = 2026,
	_instance_get = 2027,
	
/* layer.h 3000+ */
	
	_layer_exists = 3001,
	_layer_exists__id = 3002,
	_layer_get = 3004,
	_layer_get__id = 3005,
	_layer_get_depth = 3006,
	
	_layer_create = 3017,
	_layer_destroy = 3018,
	
	_layer_depth = 3029,
	
/* game_input.h 4000+ */

	// Keyboard Input
	
	_io_clear = 4001,
	_keyboard_check = 4002,
	_keyboard_check_pressed = 4003,
	_keyboard_check_released = 4004,
	_keyboard_check_direct = 4005,
	_keyboard_clear = 4006,
	_keyboard_set_map = 4007,
	_keyboard_get_map = 4008,
	_keyboard_unset_map = 4009,
	_keyboard_set_numlock = 4010,
	_keyboard_get_numlock = 4011,
	_keyboard_key_press = 4012,
	_keyboard_key_release = 4013,
	_keyboard_key_get = 4014,
	_keyboard_lastkey_get = 4015,
	_keyboard_lastchar_get = 4016,
	_keyboard_string_get = 4017,
	_keyboard_key_set = 4018,
	_keyboard_lastkey_set = 4019,
	_keyboard_lastchar_set = 4020,
	_keyboard_string_set = 4021,
	
	// Mouse Input
	
	_mouse_button_get = 4022,
	_mouse_button_set = 4023,
	_mouse_check_button = 4024,
	_mouse_check_button_pressed = 4025,
	_mouse_check_button_released = 4026,
	_mouse_clear = 4027,
	_mouse_lastbutton_get = 4028,
	_mouse_lastbutton_set = 4029,
	_mouse_wheel_up = 4030,
	_mouse_wheel_down = 4031,
	_mouse_x_get = 4032,
	_mouse_y_get = 4033,
	_mouse_pos_get = 4034,

	_window_mouse_get_x = 4035,
	_window_mouse_get_y = 4036,
	_window_mouse_get_pos = 4037,
	_window_mouse_set = 4038,
	_window_view_mouse_get_x = 4039,
	_window_view_mouse_get_y = 4040,
	_window_view_mouse_get_pos = 4041,
	_window_views_mouse_get_x = 4042,
	_window_views_mouse_get_y = 4043,
	_window_views_mouse_get_pos = 4044,
	
	// Device Input
	
	_device_mouse_check_button = 4045,
	_device_mouse_check_button_pressed = 4046,
	_device_mouse_check_button_released = 4047,
	_device_mouse_dbclick_enable = 4048,
	_device_mouse_x = 4049,
	_device_mouse_y = 4050,
	_device_mouse_pos = 4051,
	_device_mouse_raw_x = 4052,
	_device_mouse_raw_y = 4053,
	_device_mouse_raw_pos = 4054,
	_device_mouse_x_to_gui = 4055,
	_device_mouse_y_to_gui = 4056,
	_device_mouse_pos_to_gui = 4057,
	_device_is_keypad_open = 4058,
	_device_get_tilt_x = 4059,
	_device_get_tilt_y = 4060,
	_device_get_tilt_z = 4061,
	
/* debug.h 5000+ */

	// debug_mode = 5001,
	// debug_event = 5002,
	// debug_get_callstack = 5003,
	// exception_unhandled_handler = 5004,
	// get_integer = 5005,
	// get_string = 5006,
	_show_error = 5007,
	_show_message = 5008,
	_show_question = 5009,
	_show_debug_message = 5010,
	// show_debug_message_ext = 5011,
	_code_is_compiled = 5012,
	_fps_get = 5013,
	_fps_real_get = 5014,
	
	// Toggling

	_show_debug_overlay = 5015,
	_show_debug_log = 5016,
	_is_debug_overlay_open = 5017,

	// Views

	_dbg_view = 5018,
	_dbg_view_delete = 5019,
	_dbg_section = 5020,
	_dbg_section_delete = 5021,

	// Controls

	_dbg_button = 5022,
	_dbg_checkbox = 5023,
	_dbg_colour = 5024,
	_dbg_drop_down = 5025,
	_dbg_same_line = 5026,
	_dbg_slider = 5027,
	_dbg_sprite = 5028,
	_dbg_text = 5029,
	_dbg_text_input = 5030,
	_dbg_watch = 5031,
	
/* audio.h 6000+ */

	// Asset Info

	_audio_exists = 6001,
	_audio_get_name = 6002,
	_audio_get_type = 6003,
	_audio_sound_length = 6004,
	_audio_sound_is_playable = 6005,

	// Playing Sounds

	_audio_play_sound = 6006,
	_audio_play_sound__fullargs = 6007,
	// _audio_play_sound_ext = 6008, // TODO
	_audio_play_sound_at = 6009,
	_audio_play_sound_at__fullargs = 6010,
	_audio_pause_sound = 6011,
	_audio_pause_all = 6012,
	_audio_resume_sound = 6013,
	_audio_resume_all = 6014,
	_audio_stop_sound = 6015,
	_audio_stop_all = 6016,
	_audio_is_playing = 6017,
	_audio_is_paused = 6018,
	
};

#macro ARG external_call
#macro RET external_call
#macro CASE break; case

#macro ARG_R_0to0 ARG(__R, 0)
#macro ARG_R_0to1 ARG(__R, 0), ARG(__R, 1)
#macro ARG_R_0to2 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2)
#macro ARG_R_0to3 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3)
#macro ARG_R_0to4 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4)
#macro ARG_R_0to5 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5)
#macro ARG_R_0to6 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6)
#macro ARG_R_0to7 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7)
#macro ARG_R_0to8 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8)
#macro ARG_R_0to9 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9)
#macro ARG_R_0to10 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10)
#macro ARG_R_0to11 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10), ARG(__R, 11)
#macro ARG_R_0to12 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10), ARG(__R, 11), ARG(__R, 12)
#macro ARG_R_0to13 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10), ARG(__R, 11), ARG(__R, 12), ARG(__R, 13)
#macro ARG_R_0to14 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10), ARG(__R, 11), ARG(__R, 12), ARG(__R, 13), ARG(__R, 14)
#macro ARG_R_0to15 ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10), ARG(__R, 11), ARG(__R, 12), ARG(__R, 13), ARG(__R, 14), ARG(__R, 15)

function FxxkGML_Init(_dll_filename) {
	
	if(!file_exists(_dll_filename)) {
		show_error("无法找到文件：" + _dll_filename + " | Can not find the file: " + _dll_filename, true);
	}
	
	__dllGetVersionLeft = external_define(_dll_filename, "GetVerLeft", dll_cdecl, ty_real, 0);
	__dllGetVersionMid = external_define(_dll_filename, "GetVerMid", dll_cdecl, ty_real, 0);
	__dllGetVersionRight = external_define(_dll_filename, "GetVerRight", dll_cdecl, ty_real, 0);
	
	//__dllEntry = external_define(_dll_filename, "Entry", dll_cdecl, ty_real, 0);
	__dllAssistantEntry = external_define(_dll_filename, "AssistantEntry", dll_cdecl, ty_real, 1, ty_real);
	__dllResume = external_define(_dll_filename, "Resume", dll_cdecl, ty_real, 0);
	__dllOver = external_define(_dll_filename, "Over", dll_cdecl, ty_real, 0);
	
	__dllGetFuncId = external_define(_dll_filename, "GetFuncId", dll_cdecl, ty_real, 0);
	
	__R = external_define(_dll_filename, "GetArgReal", dll_cdecl, ty_real, 1, ty_real);
	__S = external_define(_dll_filename, "GetArgString", dll_cdecl, ty_string, 1, ty_real);
	
	__RetR = external_define(_dll_filename, "ReturnReal", dll_cdecl, ty_real, 1, ty_real);
	__RetS = external_define(_dll_filename, "ReturnString", dll_cdecl, ty_real, 1, ty_string);
	
	__OthR = external_define(_dll_filename, "RetOtherReal", dll_cdecl, ty_real, 2, ty_real, ty_real);
	__OthS = external_define(_dll_filename, "RetOtherString", dll_cdecl, ty_real, 2, ty_real, ty_string);
	
	__ArrR = external_define(_dll_filename, "RetArrayReal", dll_cdecl, ty_real, 2, ty_real, ty_string);
	
	/* --- 初始化 | Initialization --- */
	__dllEntry = external_define(_dll_filename, "InitEntry", dll_cdecl, ty_real, 0);
	FxxkGML_Main();
	__dllEntry = external_define(_dll_filename, "Entry", dll_cdecl, ty_real, 0);
	/* ------------------------------ */
}

function FxxkGML_GetVersion() {
	return {
		left : external_call(__dllGetVersionLeft),
		mid : external_call(__dllGetVersionMid),
		right : external_call(__dllGetVersionRight),
	};
}
	
	/* --------------------------------------------- */
	/*                这 里 是 主 函 数                */
	/*           Here Is The Main Function           */
	/* --------------------------------------------- /*
	*/                                               /*
	*/      function FxxkGML_Main() {                /*
	*/          external_call(__dllEntry);           /*
	*/          for(;;) {                            /*
	*/              external_call(__dllResume);      /*
	*/              if(__FxxkGML_RunFunc() == 0)     /*
	*/                  break;                       /*
	*/          }                                    /*
	*/          external_call(__dllOver);            /*
	*/      }                                        /*
	*/                                               /*
	/* --------------------------------------------- */

	/* ------------------------------------------------------ */
	/*                    这 里 是 副 函 数                     */
	/*             Here Is The Assistant Function             */
	/* ------------------------------------------------------ /*
	*/                                                        /*
	*/      function FxxkGML_Assistant(assistantIndex) {      /*
	*/          external_call(__dllAssistantEntry             /*
	*/                        , assistantIndex);              /*
	*/          for(;;) {                                     /*
	*/              external_call(__dllResume);               /*
	*/              if(__FxxkGML_RunFunc() == 0)              /*
	*/                  break;                                /*
	*/          }                                             /*
	*/          external_call(__dllOver);                     /*
	*/      }                                                 /*
	*/                                                        /*
	/* ------------------------------------------------------ */
	
function __FxxkGML_RunFunc() {
	static ___vartmp = undefined;
	static ___listtmp = undefined;
	static ___itmp = 0, ___lentmp = 0;
	
	switch(external_call(__dllGetFuncId)) {
		
		case EFxxkGMLFuncId._nothing:
			return 0;
			
		CASE EFxxkGMLFuncId._delta_time_get:
			RET(__RetR, delta_time);

		CASE EFxxkGMLFuncId._game_save_id_get:
			RET(__RetS, game_save_id);
		CASE EFxxkGMLFuncId._game_display_name_get:
			RET(__RetS, game_display_name);
		CASE EFxxkGMLFuncId._game_project_name_get:
			RET(__RetS, game_project_name);
		CASE EFxxkGMLFuncId._game_end:
			game_end(ARG_R_0to0);
		CASE EFxxkGMLFuncId._game_restart:
			game_restart();
		CASE EFxxkGMLFuncId._game_change:
			game_change(ARG(__S, 0), ARG(__S, 1));
		CASE EFxxkGMLFuncId._game_load_buffer:
			game_load_buffer(ARG_R_0to0);
		CASE EFxxkGMLFuncId._game_save_buffer:
			game_save_buffer(ARG_R_0to0);
		CASE EFxxkGMLFuncId._game_set_speed:
			game_set_speed(ARG_R_0to1);
		CASE EFxxkGMLFuncId._game_get_speed:
			RET(__RetR, game_get_speed(ARG_R_0to0));

		CASE EFxxkGMLFuncId._highscore_add:
			highscore_add(ARG(__S, 0), ARG(__R, 1));
		CASE EFxxkGMLFuncId._highscore_name:
			RET(__RetS, highscore_name(ARG_R_0to0));
		CASE EFxxkGMLFuncId._highscore_value:
			RET(__RetR, highscore_value(ARG_R_0to0));
		CASE EFxxkGMLFuncId._highscore_clear:
			highscore_clear();

		CASE EFxxkGMLFuncId._cursor_sprite_get:
			RET(__RetR, cursor_sprite);
		CASE EFxxkGMLFuncId._cursor_sprite_set:
			cursor_sprite = ARG(__R, 0);
			
		CASE EFxxkGMLFuncId._asset_get_index:
			RET(__RetR, asset_get_index(ARG(__S, 0)));
		CASE EFxxkGMLFuncId._asset_get_type:
			RET(__RetR, asset_get_type(ARG(__S, 0)));
			
		CASE EFxxkGMLFuncId._cinstance_getdepth:
			RET(__RetR, (ARG(__R, 0)).depth);
		CASE EFxxkGMLFuncId._cinstance_setdepth:
			(ARG(__R, 0)).depth = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getx:
			RET(__RetR, (ARG(__R, 0)).x);
		CASE EFxxkGMLFuncId._cinstance_gety:
			RET(__RetR, (ARG(__R, 0)).y);
		CASE EFxxkGMLFuncId._cinstance_getpos:
			___vartmp = ARG(__R, 0);
			RET(__OthR, 0, ___vartmp.x);
			RET(__OthR, 1, ___vartmp.y);
		CASE EFxxkGMLFuncId._cinstance_setx:
			(ARG(__R, 0)).x = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_sety:
			(ARG(__R, 0)).y = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_setpos:
			___vartmp = ARG(__R, 0);
			___vartmp.x = ARG(__R, 1);
			___vartmp.y = ARG(__R, 2);
		CASE EFxxkGMLFuncId._cinstance_getobj:
			RET(__RetR, (ARG(__R, 0)).object_index);
		CASE EFxxkGMLFuncId._cinstance_getvisible:
			RET(__RetR, (ARG(__R, 0)).visible);
		CASE EFxxkGMLFuncId._cinstance_setvisible:
			(ARG(__R, 0)).visible = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getsolid:
			RET(__RetR, (ARG(__R, 0)).solid);
		CASE EFxxkGMLFuncId._cinstance_setsolid:
			(ARG(__R, 0)).solid = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getpersistent:
			RET(__RetR, (ARG(__R, 0)).persistent);
		CASE EFxxkGMLFuncId._cinstance_setpersistent:
			(ARG(__R, 0)).persistent = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getspr:
			RET(__RetR, (ARG(__R, 0)).sprite_index);
		CASE EFxxkGMLFuncId._cinstance_setspr:
			(ARG(__R, 0)).sprite_index = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getmask:
			RET(__RetR, (ARG(__R, 0)).mask_index);
		CASE EFxxkGMLFuncId._cinstance_setmask:
			(ARG(__R, 0)).mask_index = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getsprwidth:
			RET(__RetR, (ARG(__R, 0)).sprite_width);
		CASE EFxxkGMLFuncId._cinstance_getsprheight:
			RET(__RetR, (ARG(__R, 0)).sprite_height);
		CASE EFxxkGMLFuncId._cinstance_getsprsize:
			___vartmp = ARG(__R, 0);
			RET(__OthR, 0, ___vartmp.sprite_width);
			RET(__OthR, 1, ___vartmp.sprite_height);
		CASE EFxxkGMLFuncId._cinstance_getsprxoff:
			RET(__RetR, (ARG(__R, 0)).sprite_xoffset);
		CASE EFxxkGMLFuncId._cinstance_getspryoff:
			RET(__RetR, (ARG(__R, 0)).sprite_yoffset);
		CASE EFxxkGMLFuncId._cinstance_getsproffset:
			___vartmp = ARG(__R, 0);
			RET(__OthR, 0, ___vartmp.sprite_xoffset);
			RET(__OthR, 1, ___vartmp.sprite_yoffset);
		CASE EFxxkGMLFuncId._cinstance_getimgalpha:
			RET(__RetR, (ARG(__R, 0)).image_alpha);
		CASE EFxxkGMLFuncId._cinstance_setimgalpha:
			(ARG(__R, 0)).image_alpha = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getimgangle:
			RET(__RetR, (ARG(__R, 0)).image_angle);
		CASE EFxxkGMLFuncId._cinstance_setimgangle:
			(ARG(__R, 0)).image_angle = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getimgblend:
			RET(__RetR, (ARG(__R, 0)).image_blend);
		CASE EFxxkGMLFuncId._cinstance_setimgblend:
			(ARG(__R, 0)).image_blend = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getimgxscale:
			RET(__RetR, (ARG(__R, 0)).image_xscale);
		CASE EFxxkGMLFuncId._cinstance_setimgxscale:
			(ARG(__R, 0)).image_xscale = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getimgyscale:
			RET(__RetR, (ARG(__R, 0)).image_yscale);
		CASE EFxxkGMLFuncId._cinstance_setimgyscale:
			(ARG(__R, 0)).image_yscale = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getimgscale:
			___vartmp = ARG(__R, 0);
			RET(__OthR, 0, ___vartmp.image_xscale);
			RET(__OthR, 1, ___vartmp.image_yscale);
		CASE EFxxkGMLFuncId._cinstance_setimgscale:
			___vartmp = ARG(__R, 0);
			___vartmp.image_xscale = ARG(__R, 1);
			___vartmp.image_yscale = ARG(__R, 2);
		CASE EFxxkGMLFuncId._cinstance_getimgindex:
			RET(__RetR, (ARG(__R, 0)).image_index);
		CASE EFxxkGMLFuncId._cinstance_setimgindex:
			(ARG(__R, 0)).image_index = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getimgspeed:
			RET(__RetR, (ARG(__R, 0)).image_speed);
		CASE EFxxkGMLFuncId._cinstance_setimgspeed:
			(ARG(__R, 0)).image_speed = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance_getimgnumber:
			RET(__RetR, (ARG(__R, 0)).image_number);
		CASE EFxxkGMLFuncId._cinstance_getbboxlocal:
			___vartmp = ARG(__R, 0);
			RET(__OthR, 0, ___vartmp.bbox_left - ___vartmp.x);
			RET(__OthR, 1, ___vartmp.bbox_top - ___vartmp.y);
			RET(__OthR, 2, ___vartmp.bbox_right - ___vartmp.x);
			RET(__OthR, 3, ___vartmp.bbox_bottom - ___vartmp.y);
		CASE EFxxkGMLFuncId._cinstance_getlayer:
			___vartmp = ARG(__R, 0);
			RET(__OthR, 0, layer_get_id(___vartmp.layer));
			RET(__OthS, 1, layer_get_name(___vartmp.layer));
			RET(__OthR, 2, layer_get_depth(___vartmp.layer));
		CASE EFxxkGMLFuncId._cinstance_setlayer:
			(ARG(__R, 0)).layer = ARG(__R, 1);
		CASE EFxxkGMLFuncId._cinstance___init:
			___vartmp = ARG(__R, 0);
			RET(__OthR, 0, ___vartmp.visible | (___vartmp.solid << 1) | (___vartmp.persistent << 2));
			
			RET(__OthR, 1, ___vartmp.sprite_index);
			RET(__OthR, 2, ___vartmp.mask_index);
			
			RET(__OthR, 3, ___vartmp.sprite_width);
			RET(__OthR, 4, ___vartmp.sprite_height);
			RET(__OthR, 5, ___vartmp.sprite_xoffset);
			RET(__OthR, 6, ___vartmp.sprite_yoffset);
			
			RET(__OthR, 7, ___vartmp.image_number);
			
			RET(__OthR, 8, ___vartmp.bbox_left - ___vartmp.x);
			RET(__OthR, 9, ___vartmp.bbox_top - ___vartmp.y);
			RET(__OthR, 10, ___vartmp.bbox_right - ___vartmp.x);
			RET(__OthR, 11, ___vartmp.bbox_bottom - ___vartmp.y);
			
		CASE EFxxkGMLFuncId._draw_enable_drawevent:
			draw_enable_drawevent(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_flush:
			draw_flush();
		CASE EFxxkGMLFuncId._draw_getpixel:
			RET(__RetR,
				draw_getpixel(ARG_R_0to1));
		CASE EFxxkGMLFuncId._draw_get_colour:
			RET(__RetR, draw_get_color());
		CASE EFxxkGMLFuncId._draw_get_alpha:
			RET(__RetR, draw_get_alpha());
		CASE EFxxkGMLFuncId._draw_clear:
			draw_clear(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_clear_alpha:
			draw_clear_alpha(ARG_R_0to1);
		CASE EFxxkGMLFuncId._draw_set_alpha:
			draw_set_alpha(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_set_colour:
			draw_set_color(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_arrow:
			draw_arrow(ARG_R_0to4);
		CASE EFxxkGMLFuncId._draw_circle:
			draw_circle(ARG_R_0to3);
		CASE EFxxkGMLFuncId._draw_circle_colour:
			draw_circle_color(ARG_R_0to5);
		CASE EFxxkGMLFuncId._draw_ellipse:
			draw_ellipse(ARG_R_0to4);
		CASE EFxxkGMLFuncId._draw_ellipse_colour:
			draw_ellipse_color(ARG_R_0to6);
		CASE EFxxkGMLFuncId._draw_line:
			draw_line(ARG_R_0to3);
		CASE EFxxkGMLFuncId._draw_line_colour:
			draw_line_color(ARG_R_0to5);
		CASE EFxxkGMLFuncId._draw_line_width:
			draw_line_width(ARG_R_0to4);
		CASE EFxxkGMLFuncId._draw_line_width_colour:
			draw_line_width_color(ARG_R_0to6);
		CASE EFxxkGMLFuncId._draw_point:
			draw_point(ARG_R_0to1);
		CASE EFxxkGMLFuncId._draw_point_colour:
			draw_point_color(ARG_R_0to2);
		CASE EFxxkGMLFuncId._draw_rectangle:
			draw_rectangle(ARG_R_0to4);
		CASE EFxxkGMLFuncId._draw_rectangle_colour:
			draw_rectangle_color(ARG_R_0to8);
		CASE EFxxkGMLFuncId._draw_roundrect:
			draw_roundrect(ARG_R_0to4);
		CASE EFxxkGMLFuncId._draw_roundrect_colour:
			draw_roundrect_color(ARG_R_0to6);
		CASE EFxxkGMLFuncId._draw_roundrect_ext:
			draw_roundrect_ext(ARG_R_0to6);
		CASE EFxxkGMLFuncId._draw_roundrect_colour_ext:
			draw_roundrect_color_ext(ARG_R_0to8);
		CASE EFxxkGMLFuncId._draw_triangle:
			draw_triangle(ARG_R_0to6);
		CASE EFxxkGMLFuncId._draw_triangle_colour:
			draw_triangle_color(ARG_R_0to9);
		CASE EFxxkGMLFuncId._draw_set_circle_precision:
			draw_set_circle_precision(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_path:
			draw_path(ARG_R_0to3);
		CASE EFxxkGMLFuncId._draw_self:
			draw_self();
		CASE EFxxkGMLFuncId._draw_sprite:
			draw_sprite(ARG_R_0to3);
		CASE EFxxkGMLFuncId._draw_sprite_ext:
			draw_sprite_ext(ARG_R_0to8);
		CASE EFxxkGMLFuncId._draw_sprite_general:
			draw_sprite_general(ARG_R_0to15);
		CASE EFxxkGMLFuncId._draw_sprite_part:
			draw_sprite_part(ARG_R_0to7);
		CASE EFxxkGMLFuncId._draw_sprite_part_ext:
			draw_sprite_part_ext(ARG_R_0to11);
		CASE EFxxkGMLFuncId._draw_sprite_stretched:
			draw_sprite_stretched(ARG_R_0to5);
		CASE EFxxkGMLFuncId._draw_sprite_stretched_ext:
			draw_sprite_stretched_ext(ARG_R_0to7);
		CASE EFxxkGMLFuncId._draw_sprite_pos:
			draw_sprite_pos(ARG_R_0to10);
		CASE EFxxkGMLFuncId._draw_sprite_tiled:
			draw_sprite_tiled(ARG_R_0to3);
		CASE EFxxkGMLFuncId._draw_sprite_tiled_ext:
			draw_sprite_tiled_ext(ARG_R_0to7);
		CASE EFxxkGMLFuncId._draw_enable_swf_aa:
			draw_enable_swf_aa(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_set_swf_aa_level:
			draw_set_swf_aa_level(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_get_swf_aa_level:
			RET(__RetR, draw_get_swf_aa_level());
		CASE EFxxkGMLFuncId._draw_skeleton:
			draw_skeleton(ARG(__R, 0), ARG(__S, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10));
		CASE EFxxkGMLFuncId._draw_skeleton_instance:
			draw_skeleton_instance(ARG(__R, 0), ARG(__S, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10));
		CASE EFxxkGMLFuncId._draw_skeleton_collision:
			draw_skeleton_collision(ARG(__R, 0), ARG(__S, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8));
		CASE EFxxkGMLFuncId._draw_skeleton_time:
			draw_skeleton_time(ARG(__R, 0), ARG(__S, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10));
		CASE EFxxkGMLFuncId._draw_tile:
			draw_tile(ARG_R_0to4);
		CASE EFxxkGMLFuncId._draw_tilemap:
			draw_tilemap(ARG_R_0to2);
		CASE EFxxkGMLFuncId._draw_set_font:
			draw_set_font(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_set_halign:
			draw_set_halign(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_set_valign:
			draw_set_valign(ARG_R_0to0);
		CASE EFxxkGMLFuncId._draw_get_font:
			RET(__RetR, draw_get_font());
		CASE EFxxkGMLFuncId._draw_get_halign:
			RET(__RetR, draw_get_halign());
		CASE EFxxkGMLFuncId._draw_get_valign:
			RET(__RetR, draw_get_valign());
		CASE EFxxkGMLFuncId._draw_text:
			draw_text(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2));
		CASE EFxxkGMLFuncId._draw_text_ext:
			draw_text_ext(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4));
		CASE EFxxkGMLFuncId._draw_text_colour:
			draw_text_colour(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7));
		CASE EFxxkGMLFuncId._draw_text_transformed:
			draw_text_transformed(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5));
		CASE EFxxkGMLFuncId._draw_text_ext_colour:
			draw_text_ext_colour(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9));
		CASE EFxxkGMLFuncId._draw_text_ext_transformed:
			draw_text_ext_transformed(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7));
		CASE EFxxkGMLFuncId._draw_text_transformed_colour:
			draw_text_transformed_colour(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10));
		CASE EFxxkGMLFuncId._draw_text_ext_transformed_colour:
			draw_text_ext_transformed_colour(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8), ARG(__R, 9), ARG(__R, 10), ARG(__R, 11), ARG(__R, 12));
		CASE EFxxkGMLFuncId._draw_highscore:
			draw_highscore(ARG_R_0to3);
			
		CASE EFxxkGMLFuncId._instance_create_layer:
			RET(__RetR,
				instance_create_layer(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3)));
		CASE EFxxkGMLFuncId._instance_create_layer__str:
			___vartmp = ARG(__S, 2);
			RET(__RetR,
				instance_create_layer(ARG(__R, 0), ARG(__R, 1), ___vartmp, ARG(__R, 3)));
			RET(__OthR, 0, layer_get_id(___vartmp));
			RET(__OthR, 1, layer_get_depth(___vartmp));
		CASE EFxxkGMLFuncId._instance_create_depth:
			RET(__RetR,
				instance_create_depth(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3)));
		CASE EFxxkGMLFuncId._instance_destroy:
			instance_destroy(ARG(__R, 0), ARG(__R, 1));
		CASE EFxxkGMLFuncId._instance_exists:
			RET(__RetR,
				instance_exists(ARG(__R, 0)));
		CASE EFxxkGMLFuncId._instance_find:
			RET(__RetR,
				instance_find(ARG(__R, 0), ARG(__R, 1)));
		CASE EFxxkGMLFuncId._instance_furthest:
			RET(__RetR,
				instance_furthest(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2)));
		CASE EFxxkGMLFuncId._instance_nearest:
			RET(__RetR,
				instance_nearest(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2)));
		CASE EFxxkGMLFuncId._instance_number:
			RET(__RetR,
				instance_number(ARG(__R, 0)));
		CASE EFxxkGMLFuncId._instance_place:
			RET(__RetR,
				instance_place(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2)));
		CASE EFxxkGMLFuncId._instance_place_list:
			RETLIST_R_CREATE;
			RET(__RetR,
				instance_place_list(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), RETLIST_R, ARG(__R, 4)));
			RETLIST_R_RETURN;
			RETLIST_R_DESTROY;
		CASE EFxxkGMLFuncId._instance_position:
			RET(__RetR,
				instance_position(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2)));
		CASE EFxxkGMLFuncId._instance_position_list:
			RETLIST_R_CREATE;
			RET(__RetR,
				instance_position_list(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), RETLIST_R, ARG(__R, 4)));
			RETLIST_R_RETURN;
			RETLIST_R_DESTROY;
		CASE EFxxkGMLFuncId._instance_id_get:
			RET(__RetR,
				instance_id_get(ARG(__R, 0)));
		CASE EFxxkGMLFuncId._instance_count_get:
			RET(__RetR,
				instance_count);
		CASE EFxxkGMLFuncId._instance_activate_all:
			instance_activate_all();
		CASE EFxxkGMLFuncId._instance_activate_object:
			instance_activate_object(ARG(__R, 0));
		CASE EFxxkGMLFuncId._instance_activate_region:
			instance_activate_region(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4));
		CASE EFxxkGMLFuncId._instance_activate_layer:
			instance_activate_layer(ARG(__R, 0));
		CASE EFxxkGMLFuncId._instance_activate_layer__str:
			instance_activate_layer(ARG(__S, 0));
		CASE EFxxkGMLFuncId._instance_deactivate_all:
			instance_deactivate_all(ARG(__R, 0));
		CASE EFxxkGMLFuncId._instance_deactivate_object:
			instance_deactivate_object(ARG(__R, 0));
		CASE EFxxkGMLFuncId._instance_deactivate_region:
			instance_deactivate_region(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5));
		CASE EFxxkGMLFuncId._instance_deactivate_layer:
			instance_deactivate_layer(ARG(__R, 0));
		CASE EFxxkGMLFuncId._instance_deactivate_layer__str:
			instance_deactivate_layer(ARG(__S, 0));
			
		CASE EFxxkGMLFuncId._instance_get:
			___vartmp = ARG(__R, 0).id;
			RET(__RetR, ___vartmp);
			RET(__OthR, 0, ___vartmp.object_index);
			RET(__OthR, 1, ___vartmp.x);
			RET(__OthR, 2, ___vartmp.y);
			RET(__OthR, 3, ___vartmp.depth);
			RET(__OthR, 4, layer_get_id(___vartmp.layer));
			if(___vartmp.layer != -1 && ___vartmp.layer != "") {
				RET(__OthR, 5, layer_get_name(___vartmp.layer));
			}
			
		CASE EFxxkGMLFuncId._layer_exists:
			RET(__RetR, layer_exists(ARG(__S, 0)));
		CASE EFxxkGMLFuncId._layer_exists__id:
			RET(__RetR, layer_exists(ARG(__R, 0)));
		CASE EFxxkGMLFuncId._layer_get:
			___vartmp = ARG(__S, 0);
			RET(__RetR, layer_get_id(___vartmp));
			RET(__OthR, 0, layer_get_depth(___vartmp));
		CASE EFxxkGMLFuncId._layer_get__id:
			___vartmp = ARG(__R, 0);
			RET(__RetS, layer_get_name(___vartmp));
			RET(__OthR, 0, layer_get_depth(___vartmp));
		CASE EFxxkGMLFuncId._layer_get_depth:
			RET(__RetR, layer_get_depth(ARG(__R, 0)));
		CASE EFxxkGMLFuncId._layer_depth:
			layer_depth(ARG(__R, 0), ARG(__R, 1));
			
		CASE EFxxkGMLFuncId._layer_create:
			RET(__RetR, layer_create(ARG(__R, 0), ARG(__S, 1)));
		CASE EFxxkGMLFuncId._layer_destroy:
			layer_destroy(ARG(__R, 0));
			
		CASE EFxxkGMLFuncId._io_clear:
			io_clear();
		CASE EFxxkGMLFuncId._keyboard_check:
			RET(__RetR, keyboard_check(ARG_R_0to0));
		CASE EFxxkGMLFuncId._keyboard_check_pressed:
			RET(__RetR, keyboard_check_pressed(ARG_R_0to0));
		CASE EFxxkGMLFuncId._keyboard_check_released:
			RET(__RetR, keyboard_check_released(ARG_R_0to0));
		CASE EFxxkGMLFuncId._keyboard_check_direct:
			RET(__RetR, keyboard_check_direct(ARG_R_0to0));
		CASE EFxxkGMLFuncId._keyboard_clear:
			keyboard_clear(ARG_R_0to0);
		CASE EFxxkGMLFuncId._keyboard_set_map:
			keyboard_set_map(ARG_R_0to1);
		CASE EFxxkGMLFuncId._keyboard_get_map:
			RET(__RetR, keyboard_get_map(ARG_R_0to0));
		CASE EFxxkGMLFuncId._keyboard_unset_map:
			keyboard_unset_map();
		CASE EFxxkGMLFuncId._keyboard_set_numlock:
			keyboard_set_numlock(ARG_R_0to0);
		CASE EFxxkGMLFuncId._keyboard_get_numlock:
			RET(__RetR, keyboard_get_numlock());
		CASE EFxxkGMLFuncId._keyboard_key_press:
			keyboard_key_press(ARG_R_0to0);
		CASE EFxxkGMLFuncId._keyboard_key_release:
			keyboard_key_release(ARG_R_0to0);
		CASE EFxxkGMLFuncId._keyboard_key_get:
			RET(__RetR, keyboard_key);
		CASE EFxxkGMLFuncId._keyboard_lastkey_get:
			RET(__RetR, keyboard_lastkey);
		CASE EFxxkGMLFuncId._keyboard_lastchar_get:
			RET(__RetS, keyboard_lastchar);
		CASE EFxxkGMLFuncId._keyboard_string_get:
			RET(__RetS, keyboard_string);
		CASE EFxxkGMLFuncId._keyboard_key_set:
			keyboard_key = ARG(__R, 0);
		CASE EFxxkGMLFuncId._keyboard_lastkey_set:
			keyboard_lastkey = ARG(__R, 0);
		CASE EFxxkGMLFuncId._keyboard_lastchar_set:
			keyboard_lastchar = ARG(__S, 0);
		CASE EFxxkGMLFuncId._keyboard_string_set:
			keyboard_string = ARG(__S, 0);
			
		CASE EFxxkGMLFuncId._mouse_button_get:
			RET(__RetR, mouse_button);
		CASE EFxxkGMLFuncId._mouse_button_set:
			mouse_button = ARG(__R, 0);
		CASE EFxxkGMLFuncId._mouse_check_button:
			RET(__RetR, mouse_check_button(ARG_R_0to0));
		CASE EFxxkGMLFuncId._mouse_check_button_pressed:
			RET(__RetR, mouse_check_button_pressed(ARG_R_0to0));
		CASE EFxxkGMLFuncId._mouse_check_button_released:
			RET(__RetR, mouse_check_button_released(ARG_R_0to0));
		CASE EFxxkGMLFuncId._mouse_clear:
			RET(__RetR, mouse_clear(ARG_R_0to0));
		CASE EFxxkGMLFuncId._mouse_lastbutton_get:
			RET(__RetR, mouse_lastbutton);
		CASE EFxxkGMLFuncId._mouse_lastbutton_set:
			mouse_lastbutton = ARG(__R, 0);
		CASE EFxxkGMLFuncId._mouse_wheel_up:
			RET(__RetR, mouse_wheel_up());
		CASE EFxxkGMLFuncId._mouse_wheel_down:
			RET(__RetR, mouse_wheel_down());
		CASE EFxxkGMLFuncId._mouse_x_get:
			RET(__RetR, mouse_x);
		CASE EFxxkGMLFuncId._mouse_y_get:
			RET(__RetR, mouse_y);
		CASE EFxxkGMLFuncId._mouse_pos_get:
			RET(__OthR, 0, mouse_x);
			RET(__OthR, 1, mouse_y);
		CASE EFxxkGMLFuncId._window_mouse_get_x:
			RET(__RetR, window_mouse_get_x());
		CASE EFxxkGMLFuncId._window_mouse_get_y:
			RET(__RetR, window_mouse_get_y());
		CASE EFxxkGMLFuncId._window_mouse_get_pos:
			RET(__OthR, 0, window_mouse_get_x());
			RET(__OthR, 1, window_mouse_get_y());
		CASE EFxxkGMLFuncId._window_mouse_set:
			window_mouse_set(ARG_R_0to1);
		CASE EFxxkGMLFuncId._window_view_mouse_get_x:
			RET(__RetR, window_view_mouse_get_x(ARG_R_0to0));
		CASE EFxxkGMLFuncId._window_view_mouse_get_y:
			RET(__RetR, window_view_mouse_get_y(ARG_R_0to0));
		CASE EFxxkGMLFuncId._window_view_mouse_get_pos:
			RET(__OthR, 0, window_view_mouse_get_x(ARG_R_0to0));
			RET(__OthR, 1, window_view_mouse_get_y(ARG_R_0to0));
		CASE EFxxkGMLFuncId._window_views_mouse_get_x:
			RET(__RetR, window_views_mouse_get_x());
		CASE EFxxkGMLFuncId._window_views_mouse_get_y:
			RET(__RetR, window_views_mouse_get_y());
		CASE EFxxkGMLFuncId._window_views_mouse_get_pos:
			RET(__OthR, 0, window_views_mouse_get_x());
			RET(__OthR, 1, window_views_mouse_get_y());
			
		CASE EFxxkGMLFuncId._device_mouse_check_button:
			RET(__RetR, device_mouse_check_button(ARG_R_0to1));
		CASE EFxxkGMLFuncId._device_mouse_check_button_pressed:
			RET(__RetR, device_mouse_check_button_pressed(ARG_R_0to1));
		CASE EFxxkGMLFuncId._device_mouse_check_button_released:
			RET(__RetR, device_mouse_check_button_released(ARG_R_0to1));
		CASE EFxxkGMLFuncId._device_mouse_dbclick_enable:
			RET(__RetR, device_mouse_dbclick_enable(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_x:
			RET(__RetR, device_mouse_x(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_y:
			RET(__RetR, device_mouse_y(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_pos:
			RET(__OthR, 0, device_mouse_x(ARG_R_0to0));
			RET(__OthR, 1, device_mouse_y(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_raw_x:
			RET(__RetR, device_mouse_raw_x(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_raw_y:
			RET(__RetR, device_mouse_raw_y(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_raw_pos:
			RET(__OthR, 0, device_mouse_raw_x(ARG_R_0to0));
			RET(__OthR, 1, device_mouse_raw_y(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_x_to_gui:
			RET(__RetR, device_mouse_x_to_gui(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_y_to_gui:
			RET(__RetR, device_mouse_y_to_gui(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_mouse_pos_to_gui:
			RET(__OthR, 0, device_mouse_x_to_gui(ARG_R_0to0));
			RET(__OthR, 1, device_mouse_y_to_gui(ARG_R_0to0));
		CASE EFxxkGMLFuncId._device_is_keypad_open:
			RET(__RetR, device_is_keypad_open());
		CASE EFxxkGMLFuncId._device_get_tilt_x:
			RET(__RetR, device_get_tilt_x());
		CASE EFxxkGMLFuncId._device_get_tilt_y:
			RET(__RetR, device_get_tilt_y());
		CASE EFxxkGMLFuncId._device_get_tilt_z:
			RET(__RetR, device_get_tilt_z());
			
		CASE EFxxkGMLFuncId._show_error:
			show_error(ARG(__S, 0), ARG(__R, 1));
		CASE EFxxkGMLFuncId._show_message:
			show_message(ARG(__S, 0));
		CASE EFxxkGMLFuncId._show_question:
			RET(__RetR, show_question(ARG(__S, 0)));
		CASE EFxxkGMLFuncId._show_debug_message:
			show_debug_message(ARG(__S, 0));
		CASE EFxxkGMLFuncId._code_is_compiled:
			RET(__RetR, code_is_compiled());
		CASE EFxxkGMLFuncId._fps_get:
			RET(__RetR, fps);
		CASE EFxxkGMLFuncId._fps_real_get:
			RET(__RetR, fps_real);
		CASE EFxxkGMLFuncId._show_debug_overlay:
			show_debug_overlay(ARG_R_0to3);
		CASE EFxxkGMLFuncId._show_debug_log:
			show_debug_log(ARG_R_0to0);
		CASE EFxxkGMLFuncId._is_debug_overlay_open:
			RET(__RetR, is_debug_overlay_open());
		CASE EFxxkGMLFuncId._dbg_view: // TODO
		CASE EFxxkGMLFuncId._dbg_view_delete:
		CASE EFxxkGMLFuncId._dbg_section:
		CASE EFxxkGMLFuncId._dbg_section_delete:
		
		CASE EFxxkGMLFuncId._audio_exists:
			RET(__RetR, audio_exists(ARG_R_0to0));
		CASE EFxxkGMLFuncId._audio_get_name:
			RET(__RetS, audio_get_name(ARG_R_0to0));
		CASE EFxxkGMLFuncId._audio_get_type:
			RET(__RetR, audio_get_type(ARG_R_0to0));
		CASE EFxxkGMLFuncId._audio_sound_length:
			RET(__RetR, audio_sound_length(ARG_R_0to0));
		CASE EFxxkGMLFuncId._audio_sound_is_playable:
			RET(__RetR, audio_sound_is_playable(ARG_R_0to0));
			
		CASE EFxxkGMLFuncId._audio_play_sound:
			RET(__RetR, audio_play_sound(ARG_R_0to2));
		CASE EFxxkGMLFuncId._audio_play_sound__fullargs:
			RET(__RetR, audio_play_sound(ARG_R_0to6));
		// CASE EFxxkGMLFuncId._audio_play_sound_ext:
		CASE EFxxkGMLFuncId._audio_play_sound_at:
			RET(__RetR, audio_play_sound_at(ARG_R_0to8));
		CASE EFxxkGMLFuncId._audio_play_sound_at__fullargs:
			RET(__RetR, audio_play_sound_at(ARG_R_0to12));
		CASE EFxxkGMLFuncId._audio_pause_sound:
			audio_pause_sound(ARG_R_0to0);
		CASE EFxxkGMLFuncId._audio_pause_all:
			audio_pause_all();
		CASE EFxxkGMLFuncId._audio_resume_sound:
			audio_resume_sound(ARG_R_0to0);
		CASE EFxxkGMLFuncId._audio_resume_all:
			audio_resume_all();
		CASE EFxxkGMLFuncId._audio_stop_sound:
			audio_stop_sound(ARG_R_0to0);
		CASE EFxxkGMLFuncId._audio_stop_all:
			audio_stop_all();
		CASE EFxxkGMLFuncId._audio_is_playing:
			RET(__RetR, audio_is_playing(ARG_R_0to0));
		CASE EFxxkGMLFuncId._audio_is_paused:
			RET(__RetR, audio_is_paused(ARG_R_0to0));
						
	}
	
	return 1;
}

globalvar __BufferRTemp;
__BufferRTemp = buffer_create(0, buffer_grow, 8);

#macro RETLIST_R ___listtmp

#macro RETLIST_R_SET ___listtmp = 

#macro RETLIST_R_CREATE ___listtmp = ds_list_create()
#macro RETLIST_R_DESTROY ds_list_destroy(___listtmp)

#macro RETLIST_R_RETURN ___itmp = 0; \
	buffer_resize(__BufferRTemp, 0); \
	___lentmp = ds_list_size(___listtmp); \
	for(___itmp = 0; ___itmp < ___lentmp; ___itmp++) { \
		buffer_write(__BufferRTemp, buffer_f64, ___listtmp[| ___itmp]); \
	} \
	RET(__ArrR, ___lentmp, buffer_get_address(__BufferRTemp))
