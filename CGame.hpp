//
//  CGame.hpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 17/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#ifndef CGame_hpp
#define CGame_hpp

#include <iostream>
#include <memory>
#include "CPlayerState.hpp"
#include "CAStarStrategyOnYAGSBPL.hpp"

class Game {
private:
    std::shared_ptr< Map > map;
    std::shared_ptr< std::vector< PlayerState > > players;
    std::shared_ptr< AStarStrategyOnYAGSBPL > aStarStrategyOnYAGSBPL;
public:
    Game();
    Game(std::shared_ptr< Map > inputMap, int numberOfPlayers);
    
    void addPlayer(PlayerState newPlayer);
    
    EMovementDirection nextMoveForPlayer(int playerID);
    
    //methods for testing
    
    void fillWithTestData();
    void printMap();
    void testMove(std::shared_ptr< SNode > finish);
};

#endif /* CGame_hpp */
