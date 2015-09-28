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
#include "CMap.hpp"
#include "CPlayerState.hpp"

class Game {
private:
    Map *map;
    std::vector< PlayerState > *players;
public:
    
    Game();
    Game(Map *inputMap, int numberOfPlayers);
    
    ~Game();
    

    bool makeStep();
};

#endif /* CGame_hpp */
