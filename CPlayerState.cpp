//
//  CPlayerState.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 21/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#include "CPlayerState.hpp"
#include <stdexcept>

#pragma mark - Constructors

PlayerState::PlayerState() {
    position = std::make_pair(0, 0);
    velocityVector = std::make_pair(0, 0);
}

PlayerState::PlayerState(std::pair< int, int > startPosition) {
    if (startPosition.first < 0 || startPosition.second < 0) {
        throw std::invalid_argument("start position coordinates must be >= 0");
    }
    position = startPosition;
    velocityVector = std::make_pair(0, 0);
}

#pragma mark - Destructor

PlayerState::~PlayerState() {
    
}

#pragma mark - Methods

void PlayerState::changePosition(std::pair< int, int > inputPosition) {
    if (inputPosition.first < 0 || inputPosition.second < 0) {
        throw std::invalid_argument("inputPosition coordinates must be >= 0");
    }
    position = inputPosition;
}

void PlayerState::changeVelocityVector(std::pair< int, int > inputVelocityVector) {
    velocityVector = inputVelocityVector;
}

void PlayerState::changePositionUsingVelocityVector() {
    position.first += velocityVector.first;
    position.second += velocityVector.second;
}

void PlayerState::dropVelocityVector() {
    velocityVector.first = 0;
    velocityVector.second = 0;
}