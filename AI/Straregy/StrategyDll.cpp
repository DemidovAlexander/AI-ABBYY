#include "StrategyDll.h"

extern "C" __declspec(dllexport) EMovementDirection DynamicProgrammingStrategyFunc(const Map &map, const PlayerState &player)
{
	static CDynamicProgrammingStrategy strategy(map, player);
	auto step = strategy.GetNextPosition();
	EMovementDirection direction;
	int x = player.GetX() - step.first;
	int y = player.GetY() - step.second;
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
	return direction;
}