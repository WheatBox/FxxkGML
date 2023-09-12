#pragma once

#include "FxxkGML/core.h"

#define EXPORT extern "C" __declspec(dllexport)

/* ----- 给用户的接口 ----- */
/* - Interface for Users - */

/* ---
 * 初始化，相当于只运行一次的 fgm_main();
 * 主要用于获取各种 Object 和 Sprite 等资源
 * ---
 * Initialization, equivalent to running fgm_main(); only once
 * Mainly used to obtain various resources such as Objects and Sprite
 * ---
 */
void fgm_init();

/* ---
 * 主函数，具体运行在哪里取决于 GM 里如何调用
 *
 * ---
 * The main function, where it runs depends on how it is called in GM
 * 
 * ---
 */
void fgm_main();

/* ---
 * 副函数，具体运行在哪里取决于 GM 里如何调用
 * 本质上和主函数相同
 * ---
 * The assistant function, where it runs depends on how it is called in GM
 * Essentially the same as the main function
 * ---
 */
void fgm_assistant(int assistant_index);
