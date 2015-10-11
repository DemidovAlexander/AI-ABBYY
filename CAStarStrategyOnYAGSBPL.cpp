//
//  CAStarStrategyOnYAGSBPL.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 11/10/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#include "CAStarStrategyOnYAGSBPL.hpp"
#include "yagsbpl_base.h"
#include "A_star.h"

#pragma mark - Methods Needed For YAGSBPL

int getHashBin(SNode& node) {
    int nodeSum = node.position.first;
    //std::hash<int> nodeHash;
    return nodeSum % 30;//(AStarStrategyOnYAGSBPL::map->sizeOnXaxis() * AStarStrategyOnYAGSBPL::map->sizeOnYaxis());
}

bool isAccessible(SNode& node) {
    //return AStarStrategyOnYAGSBPL::map->canPlayerStayOnCell(node.position.first, node.position.second);
    int i = node.position.first;
    int j = node.position.second;
            if (i >= 10 && j >= 10 && i < 20 && j < 20) {
                return false;
            } else if (i == 15 && j < 20) {
                return false;
            } else {
                return true;
            }
}

void getSuccessors(SNode& node, std::vector<SNode>* s, std::vector<double>* c) {
    SNode reachableNode;
    for (int deltaX = -1; deltaX <= 1; ++deltaX) {
        for (int deltaY = -1; deltaY <= 1; ++deltaY) {
            if (deltaX == 0 && deltaY == 0 && node.velocityVector.first == 0 && node.velocityVector.second == 0) {
                continue;
            }
            
            reachableNode.position = std::make_pair(node.position.first + node.velocityVector.first + deltaX,
                                                    node.position.second + node.velocityVector.second + deltaY);
            
            reachableNode.velocityVector = std::make_pair(node.velocityVector.first + deltaX,
                                                          node.velocityVector.second + deltaY);
            
            reachableNode.setDirection(deltaX, deltaY);
            
            if (reachableNode.position.first > 0 && reachableNode.position.second > 0 && reachableNode.position.first < 30 && reachableNode.position.second < 30) {
                s->push_back(reachableNode);
                c->push_back(1);
            }
        }
    }
}

double getHeuristics(SNode& node1, SNode& node2) {
    return abs(node1.position.first - node2.position.first) + abs(node1.position.second - node2.position.second);
}

#pragma mark - Constructors

AStarStrategyOnYAGSBPL::AStarStrategyOnYAGSBPL() {
    // TODO:
}

AStarStrategyOnYAGSBPL::AStarStrategyOnYAGSBPL(std::shared_ptr< Map > inputMap) {
    //map = inputMap;
}

void AStarStrategyOnYAGSBPL::searchPath(SNode& start, SNode& finish) {
    GenericSearchGraphDescriptor<SNode, double> graph;
    
    graph.getHashBin_fp = &getHashBin;
    graph.getHeuristics_fp = &getHeuristics;
    graph.getSuccessors_fp = &getSuccessors;
    graph.isAccessible_fp = &isAccessible;
    
    graph.hashTableSize = 31;//(int)(map->sizeOnXaxis() * map->sizeOnYaxis()) + 1;
 
    graph.SeedNode = start;
    graph.TargetNode = finish;
    
    A_star_planner<SNode, double> planner;
    planner.init(graph);
    planner.plan();
    
    std::vector< std::vector< SNode > > paths = planner.getPlannedPaths();
    printf("Number of paths: %lu\nPath coordinates: \n[ ", paths.size());
    for (int a=0; a<paths[0].size(); a++) {
        printf("[%d, %d]{%d}; ", paths[0][a].position.first, paths[0][a].position.second, paths[0][a].direction);
    }
    printf(" ]\n\n");
    
}
