#pragma once

#include "FxxkGML_core.h"
#include "../coroutine/coroutine.h"

#define EXPORT extern "C" __declspec(dllexport)

coroutine::routine_t rtGame;

/* ----- 给用户的接口 ----- */
/* - Interface for Users - */

void gmlmain();

/* ----- 给 GM 的接口 ----- */
/* -- Interface for GM -- */

void gmlmainexport() {
	gmlmain();
	gml::funcid = gml::__FuncId::nothing;
}

EXPORT void Entry() {
	rtGame = coroutine::create(gmlmainexport);
}

EXPORT void Resume() {
	coroutine::resume(rtGame);
}

EXPORT void Over() {
	coroutine::destroy(rtGame);
}

EXPORT double GetFuncId() {
	return static_cast<double>(gml::funcid);
}

EXPORT double GetArgReal(double index) {
	return gml::args[static_cast<int>(index)].m_real;
}

EXPORT const char * GetArgString(double index) {
	return gml::args[static_cast<int>(index)].m_string.c_str();
}

/* ----------------------- */

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2) {
	funcid = _fid;
	args[0] = _v0;
	args[1] = _v1;
	args[2] = _v2;
	coroutine::yield();
}