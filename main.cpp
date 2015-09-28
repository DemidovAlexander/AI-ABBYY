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

int main(int argc, const char * argv[]) {
    
    PlayerState player1(std::make_pair(0, 0));
    
    Game game;
    game.fillWithTestData();
    game.addPlayer(player1);
    
    game.printMap();
    
    SNode finish;
    finish.position = std::make_pair(29, 29);
    game.testMove(std::make_shared<SNode>(finish));
    
    return 0;
}