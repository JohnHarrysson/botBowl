#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "Player.h"
#include "Team.h"

class PlayerFactory {
    public:
    Player createPlayer(TeamType teamType);
}

#endif