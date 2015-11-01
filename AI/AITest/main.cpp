#include <windows.h>
#include <iostream>
#include <memory>
#include "IPlayerStateList.h"
#include "IPlayerState.h"
#include "IMap.h"

typedef int(__cdecl *STRATEGY_PROC)(IMap &map, IPlayerStateList &playerStateList, IPlayerState &currentPlayer);
typedef IPlayerState*(__cdecl *PLAYER_STATE_FACTORY_PROC)(int x, int y, int xVelocity, int yVelocity);
typedef IPlayerStateList*(__cdecl *PLAYER_STATE_LIST_FACTORY_PROC)();
typedef IMap*(__cdecl *MAP_FACTORY_PROC)();

int main() {
	HINSTANCE hinstLib = LoadLibrary(TEXT("StrategyDLL.dll"));
	STRATEGY_PROC DynamicProgrammingStrategyFunc = (STRATEGY_PROC)GetProcAddress(hinstLib, "DynamicProgrammingStrategyFunc");
	PLAYER_STATE_FACTORY_PROC GetPlayerState = (PLAYER_STATE_FACTORY_PROC)GetProcAddress(hinstLib, "GetPlayerState");
	PLAYER_STATE_LIST_FACTORY_PROC GetPlayerStateList = (PLAYER_STATE_LIST_FACTORY_PROC)GetProcAddress(hinstLib, "GetPlayerStateList");
	MAP_FACTORY_PROC GetMap = (MAP_FACTORY_PROC)GetProcAddress(hinstLib, "GetMap");

	// Map map;
	std::shared_ptr<IMap> mapPtr(GetMap());
	mapPtr->fillMapWithTestData();

	// PlayerState currentState(0, 0, 0, 0);
	std::shared_ptr<IPlayerState> playerStatePtr(GetPlayerState(0, 0, 0, 0));

	// PlayerStateList playerStateList
	std::shared_ptr<IPlayerStateList> playerStateListPtr(GetPlayerStateList());
	playerStateListPtr->AddPlayerState(*playerStatePtr);

	std::cout << DynamicProgrammingStrategyFunc(*mapPtr, *playerStateListPtr, *playerStatePtr) << std::endl;

	return 0;
}