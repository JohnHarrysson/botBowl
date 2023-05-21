#ifndef TEAM_H
#define TEAM_H

#include <string>
#include "TeamTypes.h"
#include "PlayerTypes.h"
#include "Player.h"
#include "PlayerFactory.h"

class Team {

private:
    const TeamType teamType_;
    const std::string teamName_;
    std::vector<Player> players_;
    PlayerFactory playerFactory_;
    int teamValue_ = 0;

public:
    Team(TeamType teamType, std::string teamName, const PlayerFactory& playerFactory);
    ~Team() {}

    std::string getName() const { return teamName_; }
    std::vector<Player> getPlayers() const { return players_; }

    void setPlayers(std::vector<Player>& players) { players_ = players; }
    std::string setPlayerName();

    int getTeamValue() { return teamValue_; }
    void setTeamValue(int newValue) { teamValue_ = newValue; }

    void addPlayer(Player& player) { players_.push_back(player); }

    void buyPlayer(PlayerType);
    
};

#endif