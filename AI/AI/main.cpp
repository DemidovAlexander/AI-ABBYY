//
//  main.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 28/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#include <iostream>
#include "CGame.hpp"
#include "CDynamicProgrammingStrategy.h"

void aStarTest() {
    PlayerState player1(std::make_pair(0, 0));

    //player1.changeVelocityVector(std::make_pair(1, 4));
    
    Game game;
    game.fillWithTestData();
    game.addPlayer(player1);

    game.printMap();
    game.setFinish(29, 29);
    
    
    bool isFinish = false;
    while (!isFinish) {
        EMovementDirection result = game.nextMoveForPlayer(0);
        if (result == EMovementDirection::FINISH_POSITION) {
            isFinish = true;
        }
        printMovementDiection(result);
    }
    
    //game.testMove(std::make_shared< SNode >(finish1));
    //SNode finish2(21,14,0,0);
    //game.testMove(std::make_shared< SNode >(finish2));
}

void dynamicProgrammingTest() {
    Map map;
    map.fillMapWithTestData();
    PlayerState currentState(0, 0, 0, 0);

    std::shared_ptr< std::vector< PlayerState > > vectorPtr(new std::vector< PlayerState >);
    vectorPtr->push_back(currentState);

    CDynamicProgrammingStrategy strategy(map, currentState);
    map.print(vectorPtr);

    while (strategy.HasNextState()) {
        currentState = strategy.GetNextState();
        vectorPtr->at(0) = currentState;

        map.print(vectorPtr);
        std::cout << std::endl;
        std::cout << currentState.GetX() << ' ' << currentState.GetY() << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    
    dynamicProgrammingTest();

    //aStarTest();
    
    return 0;
}