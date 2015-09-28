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
#include "CPlayerState.hpp"

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
    
    std::shared_ptr< SNode > parent;
};

class AStarStrategy {
private:
    std::shared_ptr< Map > map;
    
    std::shared_ptr< std::set< std::shared_ptr< SNode > > > closed;
    std::shared_ptr< PriorityQueueExtension< std::shared_ptr< SNode > > > open;
    
    float calculateEstimateHeuristicCost(std::shared_ptr< SNode > current, std::shared_ptr< SNode > finish);
    
public:
    
    AStarStrategy();
    AStarStrategy(std::shared_ptr< Map > inputMap);
    std::shared_ptr< std::set< std::shared_ptr< SNode > > > reachableNodesFromNode( std::shared_ptr< SNode > current );
    bool aStar(std::shared_ptr< SNode > start, std::shared_ptr< SNode > finish);
    
    EMovementDirection nextStep(PlayerState &currentPlayer, std::shared_ptr< SNode > checkPointOrFinish);
};

#endif /* CAStarStrategy_hpp */
