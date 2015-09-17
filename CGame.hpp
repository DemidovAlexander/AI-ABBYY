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

class Game {
private:
    Map *map;
public:
    
    Game();
    Game(Map *inputMap);
    

    ~Game();
    

    bool makeStep();
};

#endif /* CGame_hpp */
