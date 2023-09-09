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
	
	_cinstance___init = -1999,
	
	_instance_create_layer = 2001,
	_instance_create_depth = 2002,
	_instance_destroy = 2003,
	_instance_exists = 2004,
	_instance_create_layer__str = 2025,
	_instance_get = 2026,
	
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

function FxxkGML(_dll_filename) constructor {
	if(!file_exists(_dll_filename)) {
		show_error("无法找到文件：" + _dll_filename + " | Can not find the file: " + _dll_filename, true);
	}
	
	//__dllEntry = external_define(_dll_filename, "Entry", dll_cdecl, ty_real, 0);
	__dllResume = external_define(_dll_filename, "Resume", dll_cdecl, ty_real, 0);
	__dllOver = external_define(_dll_filename, "Over", dll_cdecl, ty_real, 0);
	
	__dllGetFuncId = external_define(_dll_filename, "GetFuncId", dll_cdecl, ty_real, 0);
	
	__R = external_define(_dll_filename, "GetArgReal", dll_cdecl, ty_real, 1, ty_real);
	__S = external_define(_dll_filename, "GetArgString", dll_cdecl, ty_string, 1, ty_real);
	
	__RetR = external_define(_dll_filename, "ReturnReal", dll_cdecl, ty_real, 1, ty_real);
	__RetS = external_define(_dll_filename, "ReturnString", dll_cdecl, ty_real, 1, ty_string);
	
	__OthR = external_define(_dll_filename, "RetOtherReal", dll_cdecl, ty_real, 2, ty_real, ty_real);
	__OthS = external_define(_dll_filename, "RetOtherString", dll_cdecl, ty_real, 2, ty_real, ty_string);
	
	/* --------------------------------------------- */
	/*                这 里 是 主 函 数                */
	/*           Here Is The Main Function           */
	/* --------------------------------------------- /*
	*/                                               /*
	*/      static Main = function() {               /*
	*/          external_call(__dllEntry);           /*
	*/          for(;;) {                            /*
	*/              external_call(__dllResume);      /*
	*/              if(__RunFunc() == 0)             /*
	*/                  break;                       /*
	*/          }                                    /*
	*/          external_call(__dllOver);            /*
	*/      }                                        /*
	*/                                               /*
	/* --------------------------------------------- */
	
	/* --- 初始化 | Initialization --- */
	__dllEntry = external_define(_dll_filename, "InitEntry", dll_cdecl, ty_real, 0);
	Main();
	__dllEntry = external_define(_dll_filename, "Entry", dll_cdecl, ty_real, 0);
	/* ------------------------------ */
	
	static __RunFunc = function() {
		static _vartmp = undefined;
		
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
				_vartmp = ARG(__R, 0);
				RET(__OthR, 0, _vartmp.x);
				RET(__OthR, 1, _vartmp.y);
			CASE EFxxkGMLFuncId._cinstance_setx:
				(ARG(__R, 0)).x = ARG(__R, 1);
			CASE EFxxkGMLFuncId._cinstance_sety:
				(ARG(__R, 0)).y = ARG(__R, 1);
			CASE EFxxkGMLFuncId._cinstance_setpos:
				_vartmp = ARG(__R, 0);
				_vartmp.x = ARG(__R, 1);
				_vartmp.y = ARG(__R, 2);
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
				_vartmp = ARG(__R, 0);
				RET(__OthR, 0, _vartmp.sprite_width);
				RET(__OthR, 1, _vartmp.sprite_height);
			CASE EFxxkGMLFuncId._cinstance_getsprxoff:
				RET(__RetR, (ARG(__R, 0)).sprite_xoffset);
			CASE EFxxkGMLFuncId._cinstance_getspryoff:
				RET(__RetR, (ARG(__R, 0)).sprite_yoffset);
			CASE EFxxkGMLFuncId._cinstance_getsproffset:
				_vartmp = ARG(__R, 0);
				RET(__OthR, 0, _vartmp.sprite_xoffset);
				RET(__OthR, 1, _vartmp.sprite_yoffset);
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
				_vartmp = ARG(__R, 0);
				RET(__OthR, 0, _vartmp.image_xscale);
				RET(__OthR, 1, _vartmp.image_yscale);
			CASE EFxxkGMLFuncId._cinstance_setimgscale:
				_vartmp = ARG(__R, 0);
				_vartmp.image_xscale = ARG(__R, 1);
				_vartmp.image_yscale = ARG(__R, 2);
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
			CASE EFxxkGMLFuncId._cinstance___init:
				_vartmp = ARG(__R, 0);
				RET(__OthR, 0, _vartmp.visible | (_vartmp.solid << 1) | (_vartmp.persistent << 2));
				RET(__OthR, 1, _vartmp.sprite_index);
				RET(__OthR, 2, _vartmp.mask_index);
				RET(__OthR, 3, _vartmp.sprite_width);
				RET(__OthR, 4, _vartmp.sprite_height);
				RET(__OthR, 5, _vartmp.sprite_xoffset);
				RET(__OthR, 6, _vartmp.sprite_yoffset);
				RET(__OthR, 7, _vartmp.image_number);
				
			CASE EFxxkGMLFuncId._instance_create_layer:
				RET(__RetR,
					instance_create_layer(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3)));
			CASE EFxxkGMLFuncId._instance_create_depth:
				RET(__RetR,
					instance_create_depth(ARG(__R, 0), ARG(__R, 1), ARG(__R, 2), ARG(__R, 3)));
			CASE EFxxkGMLFuncId._instance_destroy:
				instance_destroy(ARG(__R, 0), ARG(__R, 1));
			CASE EFxxkGMLFuncId._instance_exists:
				RET(__RetR,
					instance_exists(ARG(__R, 0)));
			CASE EFxxkGMLFuncId._instance_create_layer__str:
				_vartmp = ARG(__S, 2);
				RET(__RetR,
					instance_create_layer(ARG(__R, 0), ARG(__R, 1), _vartmp, ARG(__R, 3)));
				RET(__OthR, 0, layer_get_id(_vartmp));
				RET(__OthR, 1, layer_get_depth(_vartmp));
				
			CASE EFxxkGMLFuncId._instance_get:
				_vartmp = ARG(__R, 0);
				with(other) {
					_vartmp = _vartmp.id;
				}
				RET(__RetR, _vartmp);
				RET(__OthR, 0, _vartmp.object_index);
				RET(__OthR, 1, _vartmp.x);
				RET(__OthR, 2, _vartmp.y);
				RET(__OthR, 3, _vartmp.depth);
				RET(__OthR, 4, _vartmp.layer);
				if(_vartmp.layer != -1) {
					RET(__OthR, 5, layer_get_name(_vartmp.layer));
				}
					
			CASE EFxxkGMLFuncId._layer_exists:
				RET(__RetR, layer_exists(ARG(__S, 0)));
			CASE EFxxkGMLFuncId._layer_exists__id:
				RET(__RetR, layer_exists(ARG(__R, 0)));
			CASE EFxxkGMLFuncId._layer_get:
				_vartmp = ARG(__S, 0);
				RET(__RetR, layer_get_id(_vartmp));
				RET(__OthR, 0, layer_get_depth(_vartmp));
			CASE EFxxkGMLFuncId._layer_get__id:
				_vartmp = ARG(__R, 0);
				RET(__RetS, layer_get_name(_vartmp));
				RET(__OthR, 0, layer_get_depth(_vartmp));
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
}
