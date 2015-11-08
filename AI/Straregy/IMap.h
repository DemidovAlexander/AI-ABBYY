#pragma once

#include <utility>
#include <vector>
#include <memory>
#include "IPlayerState.h"

class IMap {
public:
	virtual const std::pair<size_t, size_t> size() const = 0;
	virtual const size_t sizeOnXaxis() const = 0;
	virtual const size_t sizeOnYaxis() const = 0;

	virtual std::vector< int > &operator[](int i) = 0;
	virtual const std::vector< int > &operator[](int i) const = 0;

	virtual bool canPlayerStayOnCell(int x, int y) const = 0;
	virtual bool hasBarrierOnPath(int xFirst, int yFirst, int xSecond, int ySecond) const = 0;
	virtual bool canPlayerStayOnCellLookOnOtherPlayers(int x, int y, int playerID, std::vector< IPlayerState > players) const = 0;
	virtual bool intersectFinishLine(int xFirst, int yFirst, int xSecond, int ySecond) const = 0;

	virtual const std::pair< int, int >& GetLeftFinishPoint() const = 0;
	virtual const std::pair< int, int >& GetRightFinishPoint() const = 0;

	virtual void print(std::vector< IPlayerState > players) const = 0;
};
