# FxxkGML (or FGM)

![FxxkGML](./FxxkGML_icon.png)

### 什么是 FxxkGML ？| What is FxxkGML?

~~C++ Fxxk GML~~

FxxkGML = 凡心侠客 的 GML

FxxkGML = Fan Xin Xia Ke's GML

(Fan Xin Xia Ke means "a knight-errant with an ordinary heart")

---

FxxkGML 可以使 C++ 能够间接用于 GameMaker 引擎中进行开发

同时也会重写或引入一些第三方库以替换一些 GameMaker 中不是很令人满意的功能，或加入新功能

主要用于 Mod 系统或其它的需要在 DLL 中操作游戏资源的场景

当然，如果愿意的话，也可以代替 GML 直接用于开发游戏本身的内容（虽然不太推荐这么做）

---

FxxkGML enables C++ to be indirectly used for development in the GameMaker engine

At the same time, it will also rewrite or introduce some third-party libraries to replace some unsatisfactory features in GameMaker, or add new features

Mainly used in Mod systems or other scenarios where game resources need to be operated in DLLs

Of course, if you are willing, you can also replace GML and directly use it to develop the content of the game itself (although it is not recommended to do so)

---

### 文档 | Document

https://github.com/WheatBox/FxxkGML/wiki

---

### 各个模块 | Modules

#### FxxkGML

	#include <FxxkGML.h>

#### ini 文件解析库 —— wini

#### ini file parser library —— wini

	#include <wini/wini.h>

	// CMakeLists.txt 中需添加：
	// CMakeLists.txt needs to add:
	
	FxxkGML/wini/wini.cpp
	
	// 例如 | For Example:
	build (game.dll ../FxxkGML_GM_Project/datafiles
		test/game.cpp
		FxxkGML/wini/wini.cpp    # 在此处添加 | Add here
	)

---

### 第三方 | Third Party

edubart/minicoro - https://github.com/edubart/minicoro
