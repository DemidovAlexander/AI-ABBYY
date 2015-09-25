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
#include "CPriorityQueueExtension.hpp"
#include <set>
#include "CMap.hpp"

enum class EMovementDirection : int {
    UP = 1,
    UP_RIGHT = 2,
    RIGHT = 3,
    DOWN_RIGHT = 4,
    DOWN = 5,
    DOWN_LEFT = 6,
    LEFT = 7,
    UP_LEFT = 8,
    NOT_CHANGED = 9
};

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
    
    SNode *parent;
};

class AStarStrategy {
public:
    Map *map;
    
    std::set< SNode * > *closed;
    PriorityQueueExtension< SNode* > *open;
    
    float calculateEstimateHeuristicCost(SNode *current, SNode *finish);
    
private:
    
    AStarStrategy();
    std::set< SNode * > reachableNodesFromNode( SNode *current );
    bool AStar(SNode *start, SNode *finish);
    
    EMovementDirection nextStep();
    
};

#endif /* CAStarStrategy_hpp */
