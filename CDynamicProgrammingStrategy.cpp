// Author: Evgeny Chernigovsky
// Description:

#include <stdexcept>
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
    minPath.SetStepCount(initialState, 0);
    stateQueue.push(initialState);

    calculatePaths();
    findOptimalPath();
}

void CDynamicProgrammingStrategy::calculatePaths() {
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

                if (newState.GetX() < 0 || newState.GetX() >= map.sizeOnXaxis()
                        || newState.GetY() < 0 || newState.GetY() >= map.sizeOnYaxis()
                        || !map.canPlayerStayOnCell(newState.GetX(), newState.GetY())
                        || map.hasBarrierOnPath(currentState.GetX(), currentState.GetY(),
                                newState.GetX(), newState.GetY())) {
                    continue;
                }

                if (minPath.GetStepCount(newState) == -1 ||
                        minPath.GetStepCount(newState) > minPath.GetStepCount(currentState) + 1) {
                    minPath.SetStepCount(newState, minPath.GetStepCount(currentState) + 1);
                    minPath.SetPreviousState(newState, currentState);
                    stateQueue.push(newState);
                }
            }
        }

        stateQueue.pop();
    }
}

int CDynamicProgrammingStrategy::findMinStepCount(PlayerState *optimalFinish) const {
    int minStepCount = -1;
    int x, y;

    for (int i = 0; i < map.GetFinishPoints()->size(); ++i) {
        x = map.GetFinishPoints()->at(i).first;
        y = map.GetFinishPoints()->at(i).second;
        int currentStepCount = minPath.FindMinStepCountToPoint(x, y, optimalFinish);

        if (currentStepCount != -1 && (minStepCount == -1 || currentStepCount < minStepCount)) {
            minStepCount = currentStepCount;
            optimalFinish->SetX(x);
            optimalFinish->SetY(y);
        }
    }

    return minStepCount;
}

void CDynamicProgrammingStrategy::findOptimalPath() {
    PlayerState optimalFinish;
    int minStepCount = findMinStepCount(&optimalFinish);

    if (minStepCount == -1) {
        throw std::runtime_error("Can't find path to finish");
    }

    PlayerState currentState = optimalFinish;
    while (currentState != initialState) {
        optimalPath.push(currentState);
        currentState = minPath.GetPreviousState(currentState);
    }
}

std::pair<int, int> CDynamicProgrammingStrategy::GetNextPosition() {
    PlayerState nextState = optimalPath.top();
    optimalPath.pop();
    return std::make_pair(nextState.GetY(), nextState.GetY());
}

PlayerState CDynamicProgrammingStrategy::GetNextState() {
    PlayerState nextState = optimalPath.top();
    optimalPath.pop();
    return nextState;
}

bool CDynamicProgrammingStrategy::HasNextState() {
    return !optimalPath.empty();
}
