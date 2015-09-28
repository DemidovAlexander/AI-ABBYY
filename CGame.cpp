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
    map = std::shared_ptr< Map > (new Map());
}

Game::Game(std::shared_ptr< Map > inputMap, int numberOfPlayers) {
    if (inputMap == nullptr) {
        throw std::invalid_argument("inputMap must NOT be NULL");
    }
    if (numberOfPlayers < 0) {
        throw std::invalid_argument("amount of players with AI must NOT be negative");
    }
    
    map = inputMap;
    players = std::shared_ptr< std::vector< PlayerState > > (new std::vector< PlayerState >);
    players->resize(numberOfPlayers);
}

#pragma mark - Destructor

Game::~Game() {
    
}

#pragma mark - Methods

bool Game::makeStep() {
    // TO DO
    return true;
}