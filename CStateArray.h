// Author: Evgeny Chernigovsky
// Description: CPlayerState to int map

#ifndef AI_ABBYY_CSTATEARRAY_H
#define AI_ABBYY_CSTATEARRAY_H

#include <vector>
#include <cmath>
#include "CPlayerState.hpp"


class CStateArray {
private:
    std::vector< std::vector< std::vector< std::vector <int> > > > stateArray;

    int minXVelocity;
    int minYVelocity;
    int maxXVelocity;
    int maxYVelocity;

    int getMaxVelocityChange(int size);

public:
    CStateArray(int xSize, int ySize, int xVelocity, int yVelocity, int value);

    int &operator[](const PlayerState &state);
    const int &operator[](const PlayerState &state) const;
};


#endif //AI_ABBYY_CSTATEARRAY_H
