#pragma once

#include <vector>
#include "IPlayerState.h"

class IPlayerStateList {
public:
	virtual void AddPlayerState(const IPlayerState &playerState) = 0;
};


