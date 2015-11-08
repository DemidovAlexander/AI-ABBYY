#ifndef CMap_hpp
#define CMap_hpp

#include <iostream>
#include <memory>
#include <vector>
#include "IPlayerState.h"
#include "IMap.h"

class Map : public IMap {
private:
    std::vector< std::vector < int > > cells;
    size_t xSize;
    size_t ySize;
    
	std::pair< int, int > leftFinishPoint;
	std::pair< int, int > rightFinishPoint;

	void fillMapWithDefaultData();

	bool intersect(int a, int b, int c, int d) const;
	int orientedArea(int ax, int ay, int bx, int by, int cx, int cy) const;
	bool wrongFinishLineIntersection(int xFirst, int yFirst, int xSecond, int ySecond) const;

public:
    const int EMPTY_CELL = 0;
    const int FILLED_CELL = 1;
    const double epsilon = 1e-8;
    
    Map();
    Map(const size_t xSize, const size_t ySize);

	Map::Map(const std::vector< std::vector < int > > &inputCells,
		const std::pair< int, int > &_leftFinishPoint,
		const std::pair< int, int > &_rightFinishPoint);
    
    ~Map();
    
    const std::pair<size_t, size_t> size() const;
    const size_t sizeOnXaxis() const;
    const size_t sizeOnYaxis() const;
    
    std::vector< int > &operator[](int i);
	const std::vector< int > &operator[](int i) const;
    
    bool canPlayerStayOnCell(int x, int y) const;
    bool hasBarrierOnPath(int xFirst, int yFirst, int xSecond, int ySecond) const;
    bool canPlayerStayOnCellLookOnOtherPlayers(int x, int y, int playerID, std::vector< IPlayerState > players) const;
	bool intersectFinishLine(int xFirst, int yFirst, int xSecond, int ySecond) const;

	const std::pair< int, int >& GetLeftFinishPoint() const;
	const std::pair< int, int >& GetRightFinishPoint() const;

    void print(std::vector< IPlayerState > players) const;
};

#endif /* CMap_hpp */
