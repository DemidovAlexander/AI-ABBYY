//
//  CAStarStrategy.hpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 25/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#ifndef CAStarStrategy_hpp
#define CAStarStrategy_hpp

#include <iostream>
#include <memory>
#include "CPriorityQueueExtension.hpp"
#include <set>
#include "CMap.hpp"
//#include "CPlayerState.hpp"
#include "EMoveDirection.h"

struct SNode {
    std::pair< int, int > position;
    std::pair< int, int > velocityVector;
    
    // from start node to this
    int pathLength;
    
    // f = g + h
    // Estimate heuristic cost
    float h;
    
    // A rating value assigned to this node
    float f;
    
    // Least cost of arrival to this node
    float g;
    
    SNode* parent;
    
    inline bool operator== (const SNode& node) const {
        if (this->position.first == node.position.first && this->position.second == node.position.second)
        { return true; } else { return false; }
    }
    
    inline bool operator< (const SNode& node) {
        if (this->position.first < node.position.first) {
            return true;
        } else if (this->position.first > node.position.first) {
            return false;
        } else {
            if (this->position.first < node.position.second) {
                return true;
            } else {
                return false;
            }
        }
    }
    
    SNode() {
        position = std::make_pair(0, 0);
        velocityVector = std::make_pair(0, 0);
        pathLength = 0;
        h = 0.0;
        f = 0.0;
        g = 0.0;
        parent = nullptr;
    }
    
    SNode(int x, int y, int velocityX, int velocityY):
    position(std::make_pair(x, y)),
    velocityVector(std::make_pair(velocityX, velocityY)) {
        pathLength = 0;
        h = 0.0;
        f = 0.0;
        g = 0.0;
        parent = nullptr;
    }
};

class Comparator {
public:
    bool operator() (const SNode& one, const SNode& two) const {
        //if (one.position.first == two.position.first && one.position.second == two.position.second)
        //{ return true; } else { return false; }
        if (one.position.first < two.position.first) {
            return true;
        } else if (one.position.first > two.position.first) {
            return false;
        } else {
            if (one.position.first < two.position.second) {
                return true;
            } else {
                return false;
            }
        }
    }
};

class AStarStrategy {
private:
    std::shared_ptr< Map > map;
    
    std::shared_ptr< std::set< SNode, Comparator > > closed;
    std::shared_ptr< PriorityQueueExtension< SNode > > open;
    
    float calculateEstimateHeuristicCost(SNode& current, SNode& finish);
    
public:
    
    AStarStrategy();
    AStarStrategy(std::shared_ptr< Map > inputMap);
    std::shared_ptr< std::set< SNode, Comparator > > reachableNodesFromNode( SNode& current );
    bool aStar(SNode& start, SNode&  finish);
    
    EMovementDirection nextStep(PlayerState &currentPlayer, SNode& checkPointOrFinish);
};

#endif /* CAStarStrategy_hpp */
