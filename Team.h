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

class TeamData {
public:
    TeamData(const std::unordered_map<PlayerType, PlayerStats>& playerTypeToStats) 
        : playerTypeToStats_(playerTypeToStats) {}

    const PlayerStats& getPlayerStats(PlayerType playerType) const {
        return playerTypeToStats_.at(playerType);
    }

private:
    std::unordered_map<PlayerType, PlayerStats> playerTypeToStats_;
};

class Team {

private:
const TeamType teamType_;
const std::string name_;
std::vector<Player&> players_;

public:
    Team(TeamType teamType, std::string name);
    Team(TeamType teamType, std::string name, std::vector<Player&> players);
    ~Team() {}

    std::string getName() const { return name_; }
    std::vector<Player&> getPlayers() const { return players_; }

    void setPlayers(std::vector<Player&> players) { players_ = players; }

    void addPlayer(Player& player) { players_.push_back(player); }

    void buyPlayer(PlayerType);
    
};

#endif