//
//  CMap.hpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 17/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#ifndef CMap_hpp
#define CMap_hpp

#include <iostream>
#include <memory>
#include <vector>
#include "CPlayerState.hpp"

class Map {
private:
    std::shared_ptr< std::vector< std::shared_ptr< std::vector < int > > > > cells;
    size_t xSize;
    size_t ySize;
    
    std::shared_ptr< std::vector< std::pair< int, int > > > finishPoints;
    
public:
    const int EMPTY_CELL = 0;
    const int FILLED_CELL = 1;
    const double epsilon = 1e-8;
    
    Map();
    Map(const size_t xSize, const size_t ySize);
    Map(std::shared_ptr< std::vector< std::shared_ptr< std::vector < int > > > > inputCells,
        std::shared_ptr< std::vector< std::pair< int, int > > > inputFinishPoints);
    
    ~Map();
    
    const std::pair<size_t, size_t> size() const; // returs xSize, ySize pair
    const size_t sizeOnXaxis() const;             // returs xSize
    const size_t sizeOnYaxis() const;             // returs ySize
    
    std::vector< int > &operator[](int i);
    
    bool canPlayerStayOnCell(int x, int y) const;
    bool hasBarrierOnPath(int xFirst, int yFirst, int xSecond, int ySecond) const;
    bool canPlayerStayOnCellLookOnOtherPlayers(int x, int y, int playerID, std::shared_ptr< std::vector< PlayerState > > players) const;

    const std::shared_ptr< std::vector< std::pair< int, int > > > GetFinishPoints() const;
    
    // methods for testing
    
    // only for default size map!
    void fillMapWithTestData();
    void fillMapWithTestData2();
    
    void print(std::shared_ptr< std::vector< PlayerState > > players);
};

#endif /* CMap_hpp */
