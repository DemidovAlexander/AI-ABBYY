// Author: Evgeny Chernigovsky
// Description: 

#include "CStateArray.h"

// returns minimal x, that belongs to {x(x-1) / 2 > size}
int CStateArray::getMaxVelocityChange(int size) {
    return static_cast<int>(ceil((sqrt(8 * size + 1) + 1) / 2));
}

CStateArray::CStateArray(int xSize, int ySize, int xVelocity, int yVelocity, int value) {
    maxXVelocity = xVelocity + getMaxVelocityChange(xSize);
    maxYVelocity = yVelocity + getMaxVelocityChange(ySize);
    minXVelocity = std::max(0, xVelocity - getMaxVelocityChange(xSize));
    minYVelocity = std::max(0, yVelocity - getMaxVelocityChange(ySize));

    std::vector< std::vector<int> > velocityInitialize(maxXVelocity - minXVelocity + 1,
            std::vector<int>(maxYVelocity - minYVelocity + 1, value));
    std::vector< std::vector< std::vector<int> > > yAxisInitialize(ySize, velocityInitialize);
    stateArray.assign(xSize, yAxisInitialize);
}

int &CStateArray::operator[](const PlayerState &state) {
    return stateArray[state.GetX()][state.GetY()]
            [state.GetXVelocity() - minXVelocity][state.GetYVelocity() - minYVelocity];
}

const int &CStateArray::operator[](const PlayerState &state) const {
    return stateArray[state.GetX()][state.GetY()]
            [state.GetXVelocity() - minXVelocity][state.GetYVelocity() - minYVelocity];
}
