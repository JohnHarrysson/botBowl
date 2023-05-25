#include "Driver.h"
#include "Team.h"
#include "TeamTypes.h"

GameDriver::GameDriver(const PlayerFactory &playerFactory, const Nuffle &nuffle) : playerFactory_(playerFactory), nuffle_(nuffle) {}

void GameDriver::driveManagement() {

    //Generate default teams
    Team humanTeam(TeamType::Humans, "The Humans", this->getPlayerFactory());
    humanTeam.generateStartingTeam();

    Team orcTeam(TeamType::Orcs, "The Orcs", this->getPlayerFactory());
    orcTeam.generateStartingTeam();

    while(true) {
        //TODO: Add possibility to buy players, upgrade players, etc.
        // early stage this will not be an option but the same initial teams will be created before every match

        //TODO: Handle selection of own team vs opposing team, to start only humans are own team.
        this->driveMatch(humanTeam, orcTeam, this->getRandomizer());
    }
}

void GameDriver::driveMatch(Team &ownTeam, Team &opposingTeam, const Nuffle &nuffle) {

}

