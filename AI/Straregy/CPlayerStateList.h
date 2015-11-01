#pragma once

#include <vector>
#include "IPlayerState.h"
#include "CPlayerState.hpp"
#include "IPlayerStateList.h"

class PlayerStateList : public IPlayerStateList {
public:
	PlayerStateList();

	void AddPlayerState(const IPlayerState &playerState);
	const std::vector<PlayerState>& GetPlayerStatesVector() const;

private:
	std::vector<PlayerState> playerStates;
};

