cmake_minimum_required (VERSION 3.15)

project (MyGame)

include_directories (FxxkGML)

macro(build _name _outpath)
message(${_outpath})
	add_library (${_name} SHARED
		FxxkGML/FxxkGML_vars.cpp
		FxxkGML/FxxkGML_core.cpp
		${ARGN}
	)
	set_target_properties(${_name} PROPERTIES
		PREFIX ""
		SUFFIX ""
		RUNTIME_OUTPUT_DIRECTORY ${_outpath}
	)
endmacro(build)

build (game.dll ../FxxkGML_GM_Project/datafiles
	test/game.cpp
	test/myFuncTest.cpp
)

add_compile_options (
	PUBLIC "-Wall"
)
