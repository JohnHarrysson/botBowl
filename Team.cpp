#include <iostream>
#include "Team.h"
#include "PlayerFactory.h"


Team::Team(TeamType teamType, std::string name, PlayerFactory& playerFactory) : teamType_(teamType), name_(name), playerFactory_(playerFactory) {}

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
