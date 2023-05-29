#ifndef DRIVER_H
#define DRIVER_H

#include "GameFlow.h"
#include "Game.h"
#include "PlayerFactory.h"

class GameDriver {
    public:
        explicit GameDriver(const PlayerFactory &playerFactory) 
        : game_(createGame(playerFactory)),
          currentFlow_(GameFlow::PLAYER1_INDUCEMENT) { }
        ~GameDriver() {}



    private:
        Game game_;
        GameFlow currentFlow_;

        static Game createGame(const PlayerFactory &playerFactory);

};

#endif