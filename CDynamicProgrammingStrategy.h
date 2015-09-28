// Author: Evgeny Chernigovsky
// Description: Dynamic programming O(n^3) solution, where n is a linear size of map.

#ifndef AI_ABBYY_CDYNAMICPROGRAMMINGSTRATEGY_H
#define AI_ABBYY_CDYNAMICPROGRAMMINGSTRATEGY_H

#include "CPlayerState.hpp"
#include "CMap.hpp"
#include "CStateArray.h"
#include <vector>
#include <queue>

class CDynamicProgrammingStrategy {
private:
    Map map;
    PlayerState initialState;

    int minXVelocity;
    int minYVelocity;
    int maxXVelocity;
    int maxYVelocity;

    const int UNREACHABLE = -1;

    // minimal path from initial state
    CStateArray minPath;

    std::queue<PlayerState> stateQueue;

public:
    CDynamicProgrammingStrategy(const Map &map, const PlayerState &initialState);

    void CalculatePath();
};


#endif //AI_ABBYY_CDYNAMICPROGRAMMINGSTRATEGY_H
