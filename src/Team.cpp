#include <iostream>
#include "Team.h"


Team::Team(TeamType teamType, std::string name, const PlayerFactory& playerFactory) : teamType_(teamType), teamName_(name), playerFactory_(playerFactory) {}

std::string Team::setPlayerName() {
    std::string name;

    std::cout << "Name the player: ";
    std::cin >> name;

    return name;
}

void Team::buyPlayer(PlayerType playerType) {
    std::string name = setPlayerName();
    Player player = playerFactory_.createPlayer(teamType_, playerType, name);
    this->addPlayer(player);
}
