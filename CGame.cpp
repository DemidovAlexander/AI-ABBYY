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
    players = std::shared_ptr< std::vector< PlayerState > > (new std::vector< PlayerState >);
    aStarStrategy = std::shared_ptr< AStarStrategy > (new AStarStrategy(map));
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
    
    aStarStrategy = std::shared_ptr< AStarStrategy > (new AStarStrategy(map));
}

#pragma mark - Destructor

Game::~Game() {
    
}

#pragma mark - Methods

void Game::addPlayer(PlayerState newPlayer) {
    players->push_back(newPlayer);
}

bool Game::makeStep() {
    // TO DO
    return true;
}

#pragma mark - Methods for Testing

void Game::fillWithTestData() {
    map->fillMapWithTestData();
}

void Game::printMap() {
    map->print(players);
}

void Game::testMove(std::shared_ptr< SNode > finish) {
    aStarStrategy->nextStep((*players)[0], finish);
}