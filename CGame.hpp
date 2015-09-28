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
#include "CMap.hpp"
#include "CPlayerState.hpp"

class Game {
private:
    std::shared_ptr< Map > map;
    std::shared_ptr< std::vector< PlayerState > > players;
public:
    
    Game();
    Game(std::shared_ptr< Map > inputMap, int numberOfPlayers);
    
    ~Game();
    

    bool makeStep();
};

#endif /* CGame_hpp */
