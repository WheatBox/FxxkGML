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

void gml::__basic(__FuncId _fid) {
	funcid = _fid;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0) {
	funcid = _fid;
	args[0] = _v0;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	args[8] = _v8;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	args[8] = _v8; args[9] = _v9;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	args[8] = _v8; args[9] = _v9; args[10] = _v10;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	args[8] = _v8; args[9] = _v9; args[10] = _v10; args[11] = _v11;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11, gmvar _v12) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	args[8] = _v8; args[9] = _v9; args[10] = _v10; args[11] = _v11; args[12] = _v12;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11, gmvar _v12, gmvar _v13) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	args[8] = _v8; args[9] = _v9; args[10] = _v10; args[11] = _v11; args[12] = _v12; args[13] = _v13;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11, gmvar _v12, gmvar _v13, gmvar _v14) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	args[8] = _v8; args[9] = _v9; args[10] = _v10; args[11] = _v11; args[12] = _v12; args[13] = _v13; args[14] = _v14;
	coroutine::yield();
}

void gml::__basic(__FuncId _fid, gmvar _v0, gmvar _v1, gmvar _v2, gmvar _v3, gmvar _v4, gmvar _v5, gmvar _v6, gmvar _v7, gmvar _v8, gmvar _v9, gmvar _v10, gmvar _v11, gmvar _v12, gmvar _v13, gmvar _v14, gmvar _v15) {
	funcid = _fid;
	args[0] = _v0; args[1] = _v1; args[2] = _v2; args[3] = _v3; args[4] = _v4; args[5] = _v5; args[6] = _v6; args[7] = _v7;
	args[8] = _v8; args[9] = _v9; args[10] = _v10; args[11] = _v11; args[12] = _v12; args[13] = _v13; args[14] = _v14; args[15] = _v15;
	coroutine::yield();
}