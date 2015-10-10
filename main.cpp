//
//  main.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 28/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#include <iostream>
#include "CGame.hpp"
//#include "CPlayerState.hpp"
//#include "CDynamicProgrammingStrategy.h"

void aStarTest() {
    PlayerState player1(std::make_pair(0, 0));

    //player1.changeVelocityVector(std::make_pair(1, 4));
    
    Game game;
    game.fillWithTestData();
    game.addPlayer(player1);

    game.printMap();
    /*
    SNode checkPoint1(7, 18, 0, 0);
    game.testMove(std::make_shared< SNode >(checkPoint1));
    std::cout << checkPoint1.parent->position.first << " " << checkPoint1.parent->position.second << std::endl;
    
    SNode checkPoint2(22, 15, 0, 0);
    game.testMove(std::make_shared< SNode >(checkPoint2));
    std::cout << checkPoint2.parent->position.first << " " << checkPoint2.parent->position.second << std::endl;
    
    SNode finish(5, 15, 0, 0);
    game.testMove(std::make_shared< SNode >(finish));
    std::cout << finish.parent->position.first << " " << finish.parent->position.second << std::endl;
     */
    SNode finish1(29,0,0,0);
    game.testMove(finish1);
    //SNode finish2(21,14,0,0);
    //game.testMove(std::make_shared< SNode >(finish2));
}
/*
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
*/
int main(int argc, const char * argv[]) {
    
    //dynamicProgrammingTest();

    aStarTest();
    
    return 0;
}