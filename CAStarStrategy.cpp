//
//  CAStarStrategy.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 25/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#include "CAStarStrategy.hpp"
#include <algorithm>
#include <stdexcept>

#pragma mark - Constructors

AStarStrategy::AStarStrategy() {
    
}

AStarStrategy::AStarStrategy(std::shared_ptr< Map > inputMap):map(inputMap) {
    
}

#pragma mark - Destructor



#pragma mark - Tools

bool isEqualNodes(const SNode& one, const SNode& two) {
    if (one.position.first == two.position.first && one.position.second == two.position.second)
    { return true; } else { return false; }
}

void printAStarResultPath(SNode& algoFinish, SNode& algoStart) {
    std::cout << "____________________" << std::endl;
    std::cout << algoFinish.position.first << " " << algoFinish.position.second << std::endl;
    SNode temp = algoFinish;
    while (!isEqualNodes(temp, algoStart)) {
        std::cout << temp.parent->position.first << " " << temp.parent->position.second << std::endl;
        temp = *temp.parent;
    }
    std::cout << "____________________" << std::endl;
}

#pragma mark - Methods

float AStarStrategy::calculateEstimateHeuristicCost(SNode& current, SNode& finish) {
    // Chebyshev distance
    return std::max(std::abs(current.position.first - finish.position.first),
                    std::abs(current.position.second - finish.position.second));
}

std::shared_ptr< std::set< SNode, Comparator > > AStarStrategy::reachableNodesFromNode( SNode& current ) {
    
    std::shared_ptr< std::set< SNode, Comparator > > result = std::shared_ptr< std::set< SNode, Comparator > > (new std::set< SNode, Comparator >);
    
    for (int deltaX = -1; deltaX <= 1; ++deltaX) {
        for (int deltaY = -1; deltaY <= 1; ++deltaY) {
            SNode nextNode;
            if (map->canPlayerStayOnCell(current.position.first + current.velocityVector.first + deltaX,
                                         current.position.second + current.velocityVector.second + deltaY)) {
                
                nextNode.position = std::make_pair(current.position.first + current.velocityVector.first + deltaX,
                                                    current.position.second + current.velocityVector.second + deltaY);
                
                nextNode.velocityVector = std::make_pair(current.velocityVector.first + deltaX,
                                                          current.velocityVector.second + deltaY);
                
                result->insert(nextNode);
            } else {
                continue;
            }
        }
    }
    std::cout<< "---- " << result->size() << std::endl;
    return result;
}

bool AStarStrategy::aStar(SNode& start, SNode& finish) {
    
    closed = std::shared_ptr< std::set< SNode, Comparator > > (new std::set< SNode, Comparator >);
    open = std::shared_ptr< PriorityQueueExtension< SNode > > (new PriorityQueueExtension< SNode >);
    
    open->push( start );
    start.f = start.g + start.h;
    start.parent = &start;
    
    while (open->size() != 0) {
        std::cout << "**** " << open->size() << std::endl;
        SNode tempNode;
        std::cout << open->top().parent << std::endl;
        tempNode = open->top();
        open->pop();
        std::cout << "***! " << open->size() << std::endl;
        
        if ( isEqualNodes(tempNode, finish) ) {
            // if equal
            //std::cout << tempNode->parent->position.first << " " << tempNode->parent->position.second << std::endl;
            printAStarResultPath(tempNode, start);
            return 1;
        }
        
        closed->insert( tempNode );
        std::shared_ptr< std::set< SNode, Comparator > > allReachableNodes = this->reachableNodesFromNode(tempNode);
        std::cout << "^^^^ " << allReachableNodes->size() << std::endl;
        for (auto it = allReachableNodes->begin(); it != allReachableNodes->end(); ++it) {
            SNode reachableNode = *it;
            
            if (closed->find(reachableNode) != closed->end()) {
                continue;
            }
            
            int tempPathLength = tempNode.g + 1;
            bool isThisPathBetter = false;
            
            if (open->find(reachableNode) == open->end()) {
                open->push(reachableNode);
                isThisPathBetter = true;
            } else {
                if (tempPathLength < reachableNode.g) {
                    isThisPathBetter = true;
                } else {
                    isThisPathBetter = false;
                }
            }
            
            if (isThisPathBetter) {
                reachableNode.parent = &tempNode;
                reachableNode.h = this->calculateEstimateHeuristicCost(reachableNode, finish);
                reachableNode.g = tempPathLength;
                reachableNode.f = reachableNode.g + reachableNode.h;
            }
        }
    }
    return 0;
}

EMovementDirection AStarStrategy::nextStep(PlayerState &currentPlayer, SNode& checkPointOrFinish) {
    SNode currentStart;
    currentStart.position = currentPlayer.getPosition();
    currentStart.velocityVector = currentPlayer.getVelocityVector();
    this->aStar(currentStart, checkPointOrFinish);
    return EMovementDirection(1);
}