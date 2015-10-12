//
//  CGame.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 17/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#include "CGame.hpp"
#include "CAStarStrategyOnYAGSBPL.hpp"
#include <stdexcept>

// I had to do this, sorry :(
std::shared_ptr< Map > aStarStaticMap;

#pragma mark - Constructors

Game::Game() {
    map = std::shared_ptr< Map > (new Map());
    aStarStaticMap = map;
    players = std::shared_ptr< std::vector< PlayerState > > (new std::vector< PlayerState >);
    aStarStrategyOnYAGSBPL = std::shared_ptr< AStarStrategyOnYAGSBPL > ();
}

Game::Game(std::shared_ptr< Map > inputMap, int numberOfPlayers) {
    if (inputMap == nullptr) {
        throw std::invalid_argument("inputMap must NOT be NULL");
    }
    if (numberOfPlayers < 0) {
        throw std::invalid_argument("amount of players with AI must NOT be negative");
    }
    
    map = inputMap;
    aStarStaticMap = map;
    players = std::shared_ptr< std::vector< PlayerState > > (new std::vector< PlayerState >);
    players->resize(numberOfPlayers);
    
    aStarStrategyOnYAGSBPL = std::shared_ptr< AStarStrategyOnYAGSBPL > ();
}

Game::Game(std::shared_ptr< Map > inputMap, int numberOfPlayers, std::pair< int, int > inputStartPoint, std::pair< int, int > inputFinishPoint) {
    if (inputMap == nullptr) {
        throw std::invalid_argument("inputMap must NOT be NULL");
    }
    if (numberOfPlayers < 0) {
        throw std::invalid_argument("amount of players with AI must NOT be negative");
    }
    
    map = inputMap;
    aStarStaticMap = map;
    players = std::shared_ptr< std::vector< PlayerState > > (new std::vector< PlayerState >);
    players->resize(numberOfPlayers);
    
    startPoint = inputStartPoint;
    finishPoint = inputFinishPoint;
    
    aStarStrategyOnYAGSBPL = std::shared_ptr< AStarStrategyOnYAGSBPL > ();
}

#pragma mark - Methods

void Game::addPlayer(PlayerState newPlayer) {
    players->push_back(newPlayer);
}

void Game::setFinish(int x, int y) {
    finishPoint.first = x;
    finishPoint.second = y;
}

EMovementDirection Game::nextMoveForPlayer(int playerID) {
    PlayerState currentPlayer = (*players)[playerID];
    if (currentPlayer.GetX() == finishPoint.first && currentPlayer.GetY() == finishPoint.second) {
        //std::cout << "FINISH" << std::endl;
        return EMovementDirection::FINISH_POSITION;
    } else {
        SNode currentStart(currentPlayer.GetX(), currentPlayer.GetY(), currentPlayer.GetXVelocity(), currentPlayer.GetYVelocity());
        SNode finish(finishPoint.first, finishPoint.second, 0, 0);
        SNode resultNode = aStarStrategyOnYAGSBPL->searchPath(currentStart, finish);
        (*players)[playerID].changePosition(std::make_pair(resultNode.position.first, resultNode.position.second));
        (*players)[playerID].changeVelocityVector(std::make_pair(resultNode.velocityVector.first, resultNode.velocityVector.second));
        return resultNode.direction;
    }
}

#pragma mark - Methods for Testing

void Game::fillWithTestData() {
    map->fillMapWithTestData();
}

void Game::printMap() {
    map->print(players);
}

void Game::testMove(std::shared_ptr< SNode > finish) {
    //aStarStrategy->nextStep((*players)[0], finish);
    SNode start;
    start.position = std::make_pair((*players)[0].GetX(), (*players)[0].GetY());
    // aStarStrategyOnYAGSBPL->searchPath(start, *finish);
}


