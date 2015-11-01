#include <vector>
#include "IPlayerState.h"
#include "IPlayerStateList.h"
#include "CPlayerState.hpp"
#include "CPlayerStateList.h"


PlayerStateList::PlayerStateList() {
}

void PlayerStateList::AddPlayerState(const IPlayerState &playerState) {
	playerStates.push_back(*(dynamic_cast<const PlayerState*>(&playerState)));
}

const std::vector<PlayerState>& PlayerStateList::GetPlayerStatesVector() const {
	return playerStates;
}
