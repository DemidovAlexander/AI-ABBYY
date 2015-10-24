#include "StrategyDll.h"



extern "C" __declspec(dllexport) EMovementDirection DynamicProgrammingStrategyFunc(const Map &map, const PlayerState& player)
{
	static CDynamicProgrammingStrategy strategy(map, player);
	return EMovementDirection();
}