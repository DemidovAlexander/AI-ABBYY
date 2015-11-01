#ifdef RACE_AI_EXPORTS
#define RACE_AI_API __declspec(dllexport) 
#else
#define RACE_AI_API __declspec(dllimport) 
#endif

#include "CDynamicProgrammingStrategy.h"
#include "IPlayerState.h"
#include "IPlayerStateList.h"
#include "IMap.h"

extern "C" RACE_AI_API int DynamicProgrammingStrategyFunc(const IMap &map, const IPlayerStateList &playerStateList, const IPlayerState &player);
extern "C" RACE_AI_API int AStarStrategyFunc(const IMap &_map, const std::vector<PlayerState> &_playerStateList, int CurrentPlayerIndex);
// Factories to export PlayerState and Map classes
extern "C" RACE_AI_API IPlayerState* GetPlayerState(int x, int y, int xVelocity, int yVelocity);
extern "C" RACE_AI_API IPlayerStateList* GetPlayerStateList();
extern "C" RACE_AI_API IMap* GetMap();