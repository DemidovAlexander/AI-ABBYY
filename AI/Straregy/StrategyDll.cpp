#include "StrategyDll.h"
#include "IPlayerState.h"
#include "IPlayerStateList.h"
#include "IMap.h"
#include "CPlayerState.hpp"
#include "CPlayerStateList.h"
#include "CMap.hpp"
#include "EMoveDirection.h"

int DynamicProgrammingStrategyFunc(const IMap &_map, const IPlayerStateList &_playerStateList, const IPlayerState &_currentPlayer) {
	const Map map = *(dynamic_cast<const Map*>(&_map));
	const PlayerStateList playerStateList = *(dynamic_cast<const PlayerStateList*>(&_playerStateList));
	const PlayerState currentPlayer = *(dynamic_cast<const PlayerState*>(&_currentPlayer));

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

IPlayerStateList* GetPlayerStateList() {
	return new PlayerStateList();
}

IMap* GetMap() {
	return new Map();
}