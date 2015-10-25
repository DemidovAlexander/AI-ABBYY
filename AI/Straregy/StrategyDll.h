#ifdef RACE_AI_EXPORTS
#define RACE_AI_API __declspec(dllexport) 
#else
#define RACE_AI_API __declspec(dllimport) 
#endif

#include "CStrategy.h"
#include "CDynamicProgrammingStrategy.h"
#include "EMoveDirection.h"

extern "C" __declspec(dllexport) EMovementDirection DynamicProgrammingStrategyFunc(const Map &map, const PlayerState &player);