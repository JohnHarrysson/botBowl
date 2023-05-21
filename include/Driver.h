#ifndef DRIVER_H
#define DRIVER_H

#include "PlayerFactory.h"

class GameDriver {
    public:
        GameDriver(PlayerFactory &playerFactory);
        ~GameDriver() {}

        void driveManagement();
        void driveMatch();

        const PlayerFactory getPlayerFactory() const { return playerFactory_; }

    private:
        PlayerFactory &playerFactory_;
};

#endif