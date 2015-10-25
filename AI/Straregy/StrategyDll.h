#pragma once
#include "../AI/CStrategy.h"
#include "../AI/CDynamicProgrammingStrategy.h"
#include "../AI/EMoveDirection.h"

extern "C" __declspec(dllexport) EMovementDirection DynamicProgrammingStrategyFunc(const Map &map, const PlayerState& player);