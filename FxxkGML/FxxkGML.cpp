#include "FxxkGML.h"

#define MINICORO_IMPL
#include "minicoro/minicoro.h"

/* ----- 给 GM 的接口 ----- */
/* -- Interface for GM -- */

mco_coro * __coGame;
fgm::__FuncId __funcid = fgm::__FuncId::nothing;
int __assistant_index = 0;

void fgm_init_export(mco_coro * co) {
	fgm_init();
	__funcid = fgm::__FuncId::nothing;
}

void fgm_main_export(mco_coro * co) {
	fgm_main();
	__funcid = fgm::__FuncId::nothing;
}

void fgm_assistant_export(mco_coro * co) {
	fgm_assistant(__assistant_index);
	__funcid = fgm::__FuncId::nothing;
}

EXPORT double GetVerLeft() {
	return FGM_VERSION_LEFT;
}

EXPORT double GetVerMid() {
	return FGM_VERSION_MID;
}

EXPORT double GetVerRight() {
	return FGM_VERSION_RIGHT;
}

EXPORT void InitEntry() {
	mco_desc desc = mco_desc_init(fgm_init_export, 0);
	desc.user_data = NULL;
	mco_create(& __coGame, & desc);
}

EXPORT void Entry() {
	mco_desc desc = mco_desc_init(fgm_main_export, 0);
	desc.user_data = NULL;
	mco_create(& __coGame, & desc);
}

EXPORT void AssistantEntry(double assistantIndex) {
	__assistant_index = assistantIndex;
	mco_desc desc = mco_desc_init(fgm_assistant_export, 0);
	desc.user_data = NULL;
	mco_create(& __coGame, & desc);
}

EXPORT void Resume() {
	mco_resume(__coGame);
}

EXPORT void Over() {
	mco_destroy(__coGame);
}

EXPORT double GetFuncId() {
	return static_cast<double>(__funcid);
}

EXPORT double GetArgReal(double index) {
	return fgm::funcargs[static_cast<int>(index)].m_real;
}

EXPORT const char * GetArgString(double index) {
	return fgm::funcargs[static_cast<int>(index)].m_string.c_str();
}

EXPORT void ReturnReal(double val) {
	fgm::g_funcres.m_real = val;
	fgm::g_funcres.m_typeid = 0;
}

EXPORT void ReturnString(const char * val) {
	fgm::g_funcres.m_string = val;
	fgm::g_funcres.m_typeid = 1;
}

EXPORT void RetOtherReal(double index, double val) {
	fgm::g_otherress[static_cast<int>(index)].m_typeid = 0;
	fgm::g_otherress[static_cast<int>(index)].m_real = val;
}

EXPORT void RetOtherString(double index, const char * val) {
	fgm::g_otherress[static_cast<int>(index)].m_typeid = 1;
	fgm::g_otherress[static_cast<int>(index)].m_string = val;
}

EXPORT void RetArrayReal(double len, const char * ccparr) {
	double * parr = (double *)ccparr;

	std::size_t ilen = static_cast<int>(len);

	fgm::g_funcres_dvec.resize(ilen);
	for(std::size_t i = 0; i < ilen; i++) {
		fgm::g_funcres_dvec[i] = parr[i];
	}
}

/* ----------------------- */

#define ____SETFUNCID __funcid = _fid;
#define ____YIELDTEMP mco_yield(__coGame);

void fgm::__basic(__FuncId _fid) {
	____SETFUNCID
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0) {
	____SETFUNCID
	funcargs[0] = _v0;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	funcargs[8] = _v8;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	funcargs[8] = _v8; funcargs[9] = _v9;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	funcargs[8] = _v8; funcargs[9] = _v9; funcargs[10] = _v10;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	funcargs[8] = _v8; funcargs[9] = _v9; funcargs[10] = _v10; funcargs[11] = _v11;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11, __gmvar _v12) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	funcargs[8] = _v8; funcargs[9] = _v9; funcargs[10] = _v10; funcargs[11] = _v11; funcargs[12] = _v12;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11, __gmvar _v12, __gmvar _v13) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	funcargs[8] = _v8; funcargs[9] = _v9; funcargs[10] = _v10; funcargs[11] = _v11; funcargs[12] = _v12; funcargs[13] = _v13;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11, __gmvar _v12, __gmvar _v13, __gmvar _v14) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	funcargs[8] = _v8; funcargs[9] = _v9; funcargs[10] = _v10; funcargs[11] = _v11; funcargs[12] = _v12; funcargs[13] = _v13; funcargs[14] = _v14;
	____YIELDTEMP
}

void fgm::__basic(__FuncId _fid, __gmvar _v0, __gmvar _v1, __gmvar _v2, __gmvar _v3, __gmvar _v4, __gmvar _v5, __gmvar _v6, __gmvar _v7, __gmvar _v8, __gmvar _v9, __gmvar _v10, __gmvar _v11, __gmvar _v12, __gmvar _v13, __gmvar _v14, __gmvar _v15) {
	____SETFUNCID
	funcargs[0] = _v0; funcargs[1] = _v1; funcargs[2] = _v2; funcargs[3] = _v3; funcargs[4] = _v4; funcargs[5] = _v5; funcargs[6] = _v6; funcargs[7] = _v7;
	funcargs[8] = _v8; funcargs[9] = _v9; funcargs[10] = _v10; funcargs[11] = _v11; funcargs[12] = _v12; funcargs[13] = _v13; funcargs[14] = _v14; funcargs[15] = _v15;
	____YIELDTEMP
}

#undef ____SETFUNCID
#undef ____YIELDTEMP