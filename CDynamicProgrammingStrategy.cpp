// Author: Evgeny Chernigovsky
// Description:

#include "CDynamicProgrammingStrategy.h"


CDynamicProgrammingStrategy::CDynamicProgrammingStrategy(const Map &_map,
                                                         const PlayerState &_initialState)
    : map(_map)
    , initialState(_initialState)
    , minPath(
            _map.sizeOnXaxis(),
            _map.sizeOnYaxis(),
            _initialState.GetXVelocity(),
            _initialState.GetYVelocity(),
            UNREACHABLE
    )
{
    minPath[initialState] = 0;
    stateQueue.push(initialState);
}

void CDynamicProgrammingStrategy::CalculatePath() {
    while (!stateQueue.empty()) {
        PlayerState currentState = stateQueue.front();

        for (int xDeviation = -1; xDeviation <= 1; ++xDeviation) {
            for (int yDeviation = -1; yDeviation <= 1; ++yDeviation) {
                PlayerState newState(
                        currentState.GetX() + currentState.GetXVelocity() + xDeviation,
                        currentState.GetY() + currentState.GetYVelocity() + yDeviation,
                        currentState.GetXVelocity() + xDeviation,
                        currentState.GetYVelocity() + yDeviation
                );

                if (newState.GetX() < 0 || newState.GetX() > map.sizeOnXaxis() ||
                        newState.GetY() < 0 || newState.GetY() > map.sizeOnYaxis()) {
                    continue;
                }

                if (minPath[newState] == -1 || minPath[newState] > minPath[currentState] + 1) {
                    minPath[newState] = minPath[currentState] + 1;
                    stateQueue.push(newState);
                }
            }
        }
    }
}
