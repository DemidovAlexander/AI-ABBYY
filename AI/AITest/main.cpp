#include <windows.h>
#include <iostream>
#include <memory>
#include "IPlayerState.h"
#include "IMap.h"

typedef int(__cdecl *STRATEGY_PROC)(IMap &map, IPlayerState &player);
typedef IPlayerState*(__cdecl *PLAYER_STATE_FACTORY_PROC)();
typedef IMap*(__cdecl *MAP_FACTORY_PROC)();

int main() {
	HINSTANCE hinstLib = LoadLibrary(TEXT("StrategyDLL.dll"));
	STRATEGY_PROC DynamicProgrammingStrategyFunc = (STRATEGY_PROC)GetProcAddress(hinstLib, "DynamicProgrammingStrategyFunc");
	PLAYER_STATE_FACTORY_PROC GetPlayerState = (PLAYER_STATE_FACTORY_PROC)GetProcAddress(hinstLib, "GetPlayerState");
	MAP_FACTORY_PROC GetMap = (MAP_FACTORY_PROC)GetProcAddress(hinstLib, "GetMap");

	// Map map;
	std::shared_ptr<IMap> mapPtr(GetMap());
	mapPtr->fillMapWithTestData();

	// PlayerState currentState(0, 0, 0, 0);
	std::shared_ptr<IPlayerState> playerStatePTR(GetPlayerState());

	std::cout << DynamicProgrammingStrategyFunc(*mapPtr, *playerStatePTR) << std::endl;

	return 0;
}