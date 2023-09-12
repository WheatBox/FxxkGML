enum EFxxkGMLFuncId {
	_nothing = 0,
	
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
	
	_layer_exists = 3001,
	_layer_exists__id = 3002,
	_layer_get = 3004,
	_layer_get__id = 3005,
	_layer_get_depth = 3006,
	
	_layer_create = 3017,
	_layer_destroy = 3018,
	
	_layer_depth = 3029,
	
	_draw_text = 10001,
	_random_range = 10002,
	_asset_get_index = 10003,
	_draw_sprite_ext = 10004,
};

#macro ARG external_call
#macro RET external_call
#macro CASE break; case

function FxxkGML_Init(_dll_filename) {
	
	if(!file_exists(_dll_filename)) {
		show_error("无法找到文件：" + _dll_filename + " | Can not find the file: " + _dll_filename, true);
	}
	
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
			
		CASE EFxxkGMLFuncId._draw_text:
			draw_text(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2));
			
		CASE EFxxkGMLFuncId._random_range:
			RET(__RetR,
				random_range(ARG(__R, 0), ARG(__R, 1)));
			
		CASE EFxxkGMLFuncId._asset_get_index:
			RET(__RetR,
				asset_get_index(ARG(__S, 0)));
			
		CASE EFxxkGMLFuncId._draw_sprite_ext:
			draw_sprite_ext(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3), ARG(__R, 4), ARG(__R, 5), ARG(__R, 6), ARG(__R, 7), ARG(__R, 8));
			
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
