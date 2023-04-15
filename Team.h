#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "Player.h"

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
}


class Team {

private:
const TeamType teamName_;
const std::string name_;
std::vector<Player&> players_;

public:
    Team(TeamType teamName, std::string name);
    Team(TeamType teamName, std::string name, std::vector<Player&> players);
    ~Team() {}

    std::string getName() const { return name_; }
    std::vector<Player&> getPlayers() const { return players_; }

    void setPlayers(std::vector<Player&> players) { players_ = players; }

    void addPlayer(Player& player) { players_.push_back(player); }
    
};

#endif