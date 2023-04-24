#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "Player.h"
#include "PlayerFactory.h"

enum class TeamType {
    Humans,
    Orcs,
    Elven_Union,
    Dark_Elves,
    Black_Orcs,
    OWA,
    Chaos_Warriors,
    Chaos_Renegades,
    Dwarfs,
    Imperial_Nobility,
    Skaven,
    Nurgle
};



class Team {

private:
const TeamType teamType_;
const std::string name_;
std::vector<Player&> players_;
PlayerFactory& playerFactory_;

public:
    Team(TeamType teamType, std::string name, PlayerFactory& playerFactory);
    ~Team() {}

    std::string getName() const { return name_; }
    std::vector<Player&> getPlayers() const { return players_; }

    void setPlayers(std::vector<Player&> players) { players_ = players; }
    std::string setPlayerName();

    void addPlayer(Player& player) { players_.push_back(player); }

    void buyPlayer(PlayerType);
    
};

#endif