//
//  CMap.cpp
//  AI-ABBYY
//
//  Created by Alexander Danilyak on 17/09/15.
//  Copyright © 2015 Alexander Danilyak. All rights reserved.
//

#define DEFAULT_X_SIZE 50
#define DEFAULT_Y_SIZE 50

#include "CMap.hpp"
#include <stdexcept>

#pragma mark - Constructors

Map::Map(): xSize(DEFAULT_X_SIZE), ySize(DEFAULT_Y_SIZE) {
    cells = new std::vector< std::vector< int > >(DEFAULT_X_SIZE);
    for (int i = 0; i < xSize; ++i) {
        (*cells)[i] = *new std::vector< int >(DEFAULT_Y_SIZE);
    }
}

Map::Map(const size_t xSize, const size_t ySize): xSize(xSize), ySize(ySize) {
    cells = new std::vector< std::vector< int > >(xSize);
    for (int i = 0; i < xSize; ++i) {
        (*cells)[i] = *new std::vector< int >(ySize);
    }
}

Map::Map(std::vector< std::vector < int > > *inputCells) {
    if (inputCells == NULL) {
        throw std::invalid_argument("inputCells must NOT be NULL");
    }
    xSize = inputCells->size();
    ySize = inputCells[0].size();
    cells = inputCells;
}

#pragma mark - Destructor

Map::~Map() {
    delete cells;
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

#pragma mark - Overload

std::vector< int > &Map::operator[](int i) {
    if (i >= xSize) {
        throw std::out_of_range("index is out of range");
    }
    return (*cells)[i];
}
