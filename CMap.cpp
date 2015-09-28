//
//  CMap.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 17/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#define DEFAULT_X_SIZE 30
#define DEFAULT_Y_SIZE 30

#include "CMap.hpp"
#include <stdexcept>

#pragma mark - Constructors

Map::Map(): xSize(DEFAULT_X_SIZE), ySize(DEFAULT_Y_SIZE) {
    cells = std::shared_ptr < std::vector< std::shared_ptr< std::vector< int > > > > (new std::vector< std::shared_ptr< std::vector< int > > >(DEFAULT_X_SIZE));
    for (int i = 0; i < xSize; ++i) {
        (*cells)[i] = std::shared_ptr< std::vector< int > > (new std::vector< int >(DEFAULT_Y_SIZE));
    }
}

Map::Map(const size_t xSize, const size_t ySize): xSize(xSize), ySize(ySize) {
    cells = std::shared_ptr < std::vector< std::shared_ptr< std::vector< int > > > > (new std::vector< std::shared_ptr< std::vector< int > > >(xSize));
    for (int i = 0; i < xSize; ++i) {
        (*cells)[i] = std::shared_ptr< std::vector< int > > (new std::vector< int >(ySize));
    }
}

Map::Map(std::shared_ptr< std::vector< std::shared_ptr< std::vector < int > > > > inputCells, std::shared_ptr< std::vector< std::pair< int, int > > > inputFinishPoints) {
    if (inputCells == NULL) {
        throw std::invalid_argument("inputCells must NOT be NULL");
    }
    if (inputFinishPoints == NULL) {
        throw std::invalid_argument("inputFinishPoints must NOT be NULL");
    }
    
    xSize = inputCells->size();
    ySize = (*inputCells)[0]->size();
    cells = inputCells;
    
    finishPoints = inputFinishPoints;
}

#pragma mark - Destructor

Map::~Map() {
    
}


#pragma mark - Methods

const std::pair<size_t, size_t> Map::size() const {
    return std::make_pair(this->xSize, this->ySize);
}

const size_t Map::sizeOnXaxis() const {
    return xSize;
}

const size_t Map::sizeOnYaxis() const {
    return ySize;
}

bool Map::canPlayerStayOnCell(int x, int y) const {
    if (x < 0 || y < 0 || x >= xSize || y >= ySize) { return false; }
    if ((*(*cells)[x])[y] == 0) { return true; } else { return false; }
}

#pragma mark - Methods for Testing

void Map::fillMapWithTestData() {
    for (int i = 0; i < DEFAULT_X_SIZE; ++i) {
        for (int j = 0; j < DEFAULT_Y_SIZE; ++j) {
            if (i >= 10 && j >= 10 && i < 20 && j < 20) {
                (*(*cells)[i])[j] = 1;
            } else {
                (*(*cells)[i])[j] = 0;
            }
        }
    }
}

void Map::print(std::shared_ptr< std::vector< PlayerState > > players) {
    for (int i = 0; i < xSize; ++i) {
        for (int j = 0; j < ySize; ++j) {
            for (int p = 0; p < players->size(); ++p) {
                if ((*players)[p].getPosition() == std::make_pair(i, j)) {
                    std::cout << "*";
                } else {
                    std::cout << (*(*cells)[i])[j];
                }
            }
        }
        std::cout << std::endl;
    }
}

#pragma mark - Overload

std::vector< int > &Map::operator[](int i) {
    if (i >= xSize) {
        throw std::out_of_range("index is out of range");
    }
    return (*(*cells)[i]);
}
