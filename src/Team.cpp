#include <iostream>
#include "Team.h"


Team::Team(TeamType teamType, std::string name, const PlayerFactory& playerFactory) 
    : teamType_(teamType), teamName_(name), playerFactory_(playerFactory) {}

//TODO: check that no players currently exist
//TODO: also see that this includes bying rerolls/apos/etc.
//TODO: check that treasury does not go under 0
void Team::generateStartingTeam() {
    std::vector<Player> startingTeam = playerFactory_.createStartingTeam(teamType_);
    int newTeamValue = this->getTeamValue();
    int newTreasury = this->getTreasury();

    for (Player player : startingTeam) {
        newTeamValue += player.getPlayerValue();
        newTreasury -= player.getPlayerValue();
    }

    setTeamValue(newTeamValue);
    setTreasury(newTreasury);
    setPlayers(startingTeam);    
}

std::string Team::setPlayerName() {
    std::string name;

    std::cout << "Name the player: ";
    std::cin >> name;

    return name;
}

//TODO: Fix availibility of default name
void Team::buyPlayer(PlayerType playerType) {
    int newTreasury = this->getTreasury();
    std::string name = setPlayerName();
    Player player = playerFactory_.createPlayer(teamType_, playerType, name);

    if (newTreasury - player.getPlayerValue() < 0)
    {
        std::cout << "Not enough in treasury to buy player \n"; 
        return;
    }

    addPlayer(player);
    int newTeamValue = this->getTeamValue();
    newTeamValue += player.getPlayerValue();
    newTreasury -= player.getPlayerValue();
    setTeamValue(newTeamValue);
    setTreasury(newTreasury);
}
