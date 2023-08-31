#include "coroutine.h"

#include <iostream>

#define EXPORT extern "C" __declspec(dllexport)

coroutine::routine_t rtGame;

double val = 114;

void Middle() {
	std::cout << "B" << std::endl;
	coroutine::yield();
	std::cout << "C" << std::endl;
}

void Game() {
	std::cout << "A" << std::endl;
	val = 123.0;
	Middle();
	// coroutine::yield();
	std::cout << "D" << std::endl;
	val = 456.0;
}

EXPORT double GetVal() {
	return val;
}

EXPORT void Resume() {
	coroutine::resume(rtGame);
}

EXPORT double Start() {
	std::cout << "Hello, world!" << std::endl;
	std::cout << "main0" << std::endl;
	
	rtGame = coroutine::create(Game);
	coroutine::resume(rtGame);

	std::cout << "main1" << std::endl;
	std::cout << "Over" << std::endl;
	return 0;
}
// int main() {Start();}