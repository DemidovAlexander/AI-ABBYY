#include "StrategyDll.h"
#include "IPlayerState.h"
#include "IMap.h"
#include "CPlayerState.hpp"
#include "CMap.hpp"
#include "EMoveDirection.h"
//#include "CAStarStrategyOnYAGSBPL.hpp"

Map  PutPlayersOnMap(const Map &_map, const std::vector<std::shared_ptr<IPlayerState>> &_playerStateList, int CurrentPlayerIndex)
{
	int xSize = _map.size().first;
	int ySize = _map.size().second;
	Map res(xSize, ySize);
	for (int x = 0; x < xSize; ++x)
		for (int y = 0; y < ySize; ++y)
		{
			int cellValue = _map[x][y];
			if (cellValue == 0)
			{
				for (int p = 0; p < _playerStateList.size(); ++p)
				{
					if (p == CurrentPlayerIndex)
						continue;
					if (_playerStateList[p]->GetX() == x && _playerStateList[p]->GetX() == y)
					{
						cellValue = 1;
						break;
					};
				};
			};
			res[x][y] = cellValue;
		};
	return res;
}

int StrategyFunc(const IMap &_map, const std::vector<std::shared_ptr<IPlayerState>> &_playerStates, int curPlayerPosition) {
	Map map = /*PutPlayersOnMap(*/*(dynamic_cast<const Map*>(&_map))/*, _playerStates, curPlayerPosition)*/;
	const PlayerState currentPlayer = *(std::dynamic_pointer_cast<PlayerState>(_playerStates[curPlayerPosition]));

	static CDynamicProgrammingStrategy strategy(map, currentPlayer);
	auto step = strategy.GetNextPosition();
	EMovementDirection direction;
	int x = currentPlayer.GetX() - step.first;
	int y = currentPlayer.GetY() - step.second;
	if (x == 0 && y == 0) {
		direction = EMovementDirection::NONE;
	}
	else if (x == -1 && y == 0) {
		direction = EMovementDirection::UP;
	}
	else if (x == -1 && y == 1) {
		direction = EMovementDirection::UP_RIGHT;
	}
	else if (x == 0 && y == 1) {
		direction = EMovementDirection::RIGHT;
	}
	else if (x == 1 && y == 1) {
		direction = EMovementDirection::DOWN_RIGHT;
	}
	else if (x == 1 && y == 0) {
		direction = EMovementDirection::DOWN;
	}
	else if (x == 1 && y == -1) {
		direction = EMovementDirection::DOWN_LEFT;
	}
	else if (x == 0 && y == -1) {
		direction = EMovementDirection::LEFT;
	}
	else if (x == -1 && y == -1) {
		direction = EMovementDirection::UP_LEFT;
	}

	return (int)direction;
}

IPlayerState* GetPlayerState(int x, int y, int xVelocity, int yVelocity) {
	return new PlayerState(x, y, xVelocity, yVelocity);
}

IMap* GetMap() {
	return new Map();
}

/*
int AStarStrategyFunc(const IMap &_map, const std::vector<PlayerState> &_playerStateList, int CurrentPlayerIndex)
{
aStarStaticMap = std::shared_ptr<Map>(new Map(PutPlayersOnMap(_map, _playerStateList, CurrentPlayerIndex)));
AStarStrategyOnYAGSBPL aStarStrategyOnYAGSBPL;

PlayerState currentPlayer = _playerStateList[CurrentPlayerIndex];
SNode start(currentPlayer.GetX(), currentPlayer.GetY(), currentPlayer.GetXVelocity(), currentPlayer.GetYVelocity());
SNode finish;
aStarStrategyOnYAGSBPL.searchPath(start, finish);
return 1;
}*/
