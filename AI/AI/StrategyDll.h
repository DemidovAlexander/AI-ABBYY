#include "CStrategy.h"
#include "CDynamicProgrammingStrategy.h"
#include "EMoveDirection.h"

extern "C" __declspec(dllimport) EMovementDirection DynamicProgrammingStrategyFunc(const Map &map, const PlayerState& player);