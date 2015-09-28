//
//  main.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 28/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#include <iostream>
#include "CGame.hpp"
#include "CPlayerState.hpp"
#include "CDynamicProgrammingStrategy.h"

void aStarTest() {
    PlayerState player1(std::make_pair(0, 0));

    Game game;
    game.fillWithTestData();
    game.addPlayer(player1);

    game.printMap();

    SNode finish;
    finish.position = std::make_pair(29, 29);
    game.testMove(std::make_shared<SNode>(finish));
}

void dynamicProgrammingTest() {
    Map map;
    map.fillMapWithTestData();
    PlayerState currentState(0, 0, 0, 0);

    CDynamicProgrammingStrategy strategy(map, currentState);

    std::shared_ptr< std::vector< PlayerState > > vectorPtr(new std::vector< PlayerState >);
    vectorPtr->push_back(currentState);

    while (strategy.HasNextState()) {
        currentState = strategy.GetNextState();
        vectorPtr->at(0) = currentState;

        map.print(vectorPtr);
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    
    dynamicProgrammingTest();

    aStarTest();
    
    //std::cout << finish.parent->position.first << " " << finish.parent->position.second << std::endl;
    
    return 0;
}