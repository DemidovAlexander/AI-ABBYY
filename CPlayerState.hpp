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
    PlayerState(int x, int y, int xVelocity, int yVelocity);
    
    ~PlayerState();
    
    void changePosition(std::pair< int, int > inputPosition);
    void changeVelocityVector(std::pair< int, int > inputVelocityVector);
    void changePositionUsingVelocityVector();
    void dropVelocityVector();

    int GetXVelocity() const;
    int GetYVelocity() const;
    int GetX() const;
    int GetY() const;
    
    std::pair< int, int > getPosition() const;
    std::pair< int, int > getVelocityVector() const;
};

#endif /* CPlayerState_hpp */
