#include <windows.h>
#include <iostream>
#include "CMap.hpp"
#include "EMoveDirection.h"

typedef int(__cdecl *MYPROC)(const Map &map, const PlayerState &player);

int main() {
	HINSTANCE hinstLib = LoadLibrary(TEXT("StrategyDLL.dll"));
	MYPROC DynamicProgrammingStrategyFunc = (MYPROC)GetProcAddress(hinstLib, "DynamicProgrammingStrategyFunc");

	Map map;
	map.fillMapWithTestData();
	PlayerState currentState(0, 0, 0, 0);

	EMovementDirection nextMovementDirection = (EMovementDirection)DynamicProgrammingStrategyFunc(map, currentState);

	std::cout << (int)nextMovementDirection << std::endl;
}