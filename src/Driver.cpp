#include "Driver.h"
#include "Team.h"
#include "TeamTypes.h"

Driver::Driver(PlayerFactory playerFactory) : playerFactory_(playerFactory) {}

void Driver::driveManagement() {

    while(true) {
        //TODO: Add possibility to buy players, upgrade players, etc.
        // early stage this will not be an option but the same initial teams will be created before every match

        Team humanTeam(TeamType::Humans, "TheHumanTeam", getPlayerFactory())
        Team orcTeam(TeamType::Orcs, "TheOrcTeam", getPlayerFactory())


    }
    }

void Driver::driveMatch() {

}

