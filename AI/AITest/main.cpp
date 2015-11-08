#include <windows.h>
#include <iostream>
#include <memory>
#include "IPlayerState.h"
#include "IMap.h"

typedef int(__cdecl *STRATEGY_PROC)(const IMap &_map, const std::vector<std::shared_ptr<IPlayerState>> &_playerStates, int curPlayerPosition);
typedef IPlayerState*(__cdecl *PLAYER_STATE_FACTORY_PROC)(int x, int y, int xVelocity, int yVelocity);

typedef IMap*(__cdecl *MAP_DEFAULT_FACTORY_PROC)();
typedef IMap*(__cdecl *MAP_FACTORY_PROC)(const std::vector< std::vector < int > > &inputCells,
	const std::pair< int, int > &_leftFinishPoint,
	const std::pair< int, int > &_rightFinishPoint);

int main() {
	HINSTANCE hinstLib = LoadLibrary(TEXT("StrategyDLL.dll"));
	STRATEGY_PROC StrategyFunc = (STRATEGY_PROC)GetProcAddress(hinstLib, "StrategyFunc");
	PLAYER_STATE_FACTORY_PROC GetPlayerState = (PLAYER_STATE_FACTORY_PROC)GetProcAddress(hinstLib, "GetPlayerState");
	MAP_DEFAULT_FACTORY_PROC GetDefaultMap = (MAP_DEFAULT_FACTORY_PROC)GetProcAddress(hinstLib, "GetMap");

	// Map map;
	std::shared_ptr<IMap> mapPtr(GetDefaultMap());

	// PlayerState currentState(0, 0, 0, 0);
	std::shared_ptr<IPlayerState> playerStatePtr(GetPlayerState(0, 0, 0, 0));

	std::vector<std::shared_ptr<IPlayerState>> playerStates;
	playerStates.push_back(playerStatePtr);

	std::cout << StrategyFunc(*mapPtr, playerStates, 0) << std::endl;

	return 0;
}
