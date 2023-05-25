#ifndef DRIVER_H
#define DRIVER_H

#include "PlayerFactory.h"
#include "Random.h"
#include "Team.h"

class GameDriver {
    public:
        GameDriver(const PlayerFactory &playerFactory, const Nuffle &nuffle);
        ~GameDriver() {}

        void driveManagement();
        void driveMatch(Team&, Team&, const Nuffle&);

        const PlayerFactory& getPlayerFactory() const { return playerFactory_; }
        const Nuffle& getRandomizer() const { return nuffle_; }

    private:
        const PlayerFactory &playerFactory_;
        const Nuffle &nuffle_;
};

#endif