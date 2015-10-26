#ifdef RACE_AI_EXPORTS
#define RACE_AI_API __declspec(dllexport) 
#else
#define RACE_AI_API __declspec(dllimport) 
#endif

#include "CDynamicProgrammingStrategy.h"
#include "IPlayerState.h"
#include "IMap.h"

extern "C" RACE_AI_API int DynamicProgrammingStrategyFunc(const IMap &map, const IPlayerState &player);

// Factories to export PlayerState and Map classes
extern "C" RACE_AI_API IPlayerState* GetPlayerState();
extern "C" RACE_AI_API IMap* GetMap();