#pragma once

#include "FxxkGML/core.h"

#define EXPORT extern "C" __declspec(dllexport)

/* ----- 给用户的接口 ----- */
/* - Interface for Users - */

/* ---
 * 初始化，相当于只运行一次的 gmlmain();
 * 主要用于获取各种 Object 和 Sprite 等资源
 * ---
 * Initialization, equivalent to running gmlmain(); only once
 * Mainly used to obtain various resources such as Objects and Sprite
 * ---
 */
void gmlinit();

/* ---
 * 主函数，具体运行在哪里取决于 GM 里如何调用
 *
 * ---
 * The main function, where it runs depends on how it is called in GM
 * 
 * ---
 */
void gmlmain();
