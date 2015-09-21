//
//  CGame.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 17/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#include "CGame.hpp"
#include <stdexcept>

#pragma mark - Constructors

Game::Game() {
    map = new Map();
}

Game::Game(Map *inputMap, int numberOfPlayers) {
    if (inputMap == NULL) {
        throw std::invalid_argument("inputMap must NOT be NULL");
    }
    if (numberOfPlayers < 0) {
        throw std::invalid_argument("amount of players with AI must NOT be negative");
    }
    
    map = inputMap;
    players = new std::vector< PlayerState >;
    players->resize(numberOfPlayers);
}

#pragma mark - Destructor

Game::~Game() {
    delete map;
}

#pragma mark - Methods

bool Game::makeStep() {
    // TO DO
    return true;
}