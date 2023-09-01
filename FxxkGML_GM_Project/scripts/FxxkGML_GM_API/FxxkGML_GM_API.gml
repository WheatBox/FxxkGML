enum EFxxkGMLFuncId {
	_nothing = 0,
	_draw_text = 1001,
	_random_range = 1002,
};

#macro ARG external_call
#macro RET external_call
#macro CASE break; case

function FxxkGML(_dll_filename) constructor {
	//__dllEntry = external_define(_dll_filename, "Entry", dll_cdecl, ty_real, 0);
	__dllResume = external_define(_dll_filename, "Resume", dll_cdecl, ty_real, 0);
	__dllOver = external_define(_dll_filename, "Over", dll_cdecl, ty_real, 0);
	
	__dllGetFuncId = external_define(_dll_filename, "GetFuncId", dll_cdecl, ty_real, 0);
	
	__R = external_define(_dll_filename, "GetArgReal", dll_cdecl, ty_real, 1, ty_real);
	__S = external_define(_dll_filename, "GetArgString", dll_cdecl, ty_string, 1, ty_real);
	
	__RetR = external_define(_dll_filename, "ReturnReal", dll_cdecl, ty_real, 1, ty_real);
	__RetS = external_define(_dll_filename, "ReturnString", dll_cdecl, ty_real, 1, ty_string);
	
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
		switch(external_call(__dllGetFuncId)) {
			
			case EFxxkGMLFuncId._nothing:
				return 0;
				
			case EFxxkGMLFuncId._draw_text:
				draw_text(ARG(__R, 0), ARG(__R, 1), ARG(__S, 2));
				
			CASE EFxxkGMLFuncId._random_range:
				RET(__RetR,
					random_range(ARG(__R, 0), ARG(__R, 1))
				);
				
		}
		
		return 1;
	}
}
