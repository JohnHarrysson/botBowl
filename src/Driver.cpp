#include "Driver.h"
#include "Team.h"
#include "TeamTypes.h"

GameDriver::GameDriver(PlayerFactory &playerFactory) : playerFactory_(playerFactory) {}

void GameDriver::driveManagement() {

    while(true) {
        //TODO: Add possibility to buy players, upgrade players, etc.
        // early stage this will not be an option but the same initial teams will be created before every match

        //Generate default teams
        Team humanTeam(TeamType::Humans, "The Humans", this->getPlayerFactory());
        humanTeam.generateStartingTeam();

        Team orcTeam(TeamType::Orcs, "The Orcs", this->getPlayerFactory());
        orcTeam.generateStartingTeam();




    }
    }

void GameDriver::driveMatch() {

}

