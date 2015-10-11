//
//  CAStarStrategyOnYAGSBPL.hpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 11/10/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#ifndef CAStarStrategyOnYAGSBPL_hpp
#define CAStarStrategyOnYAGSBPL_hpp

#include <iostream>
#include <memory>
#include "SNode.hpp"
#include "CMap.hpp"
#include <functional>

class AStarStrategyOnYAGSBPL {
private:
    static std::shared_ptr< Map > map;
    
public:
    //friend int getHashBin(SNode& node);
    //friend bool isAccessible(SNode& node);
    
    AStarStrategyOnYAGSBPL();
    AStarStrategyOnYAGSBPL(std::shared_ptr< Map > inputMap);
    
    void searchPath(SNode& start, SNode& finish);
    
};

#endif /* CAStarStrategyOnYAGSBPL_hpp */
