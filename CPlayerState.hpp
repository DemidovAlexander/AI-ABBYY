//
//  CPlayerState.hpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 21/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#ifndef CPlayerState_hpp
#define CPlayerState_hpp

#include <iostream>

class PlayerState {
private:
    std::pair< int, int > position;
    std::pair< int, int > velocityVector;
public:
    
    PlayerState();
    PlayerState(std::pair< int, int > startPosition);
    
    ~PlayerState();
    
    void changePosition(std::pair< int, int > inputPosition);
    void changeVelocityVector(std::pair< int, int > inputVelocityVector);
    void changePositionUsingVelocityVector();
    void dropVelocityVector();
    
};

#endif /* CPlayerState_hpp */
