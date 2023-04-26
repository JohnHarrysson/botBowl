#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include <unordered_map>
#include "Player.h"
#include "Stats.h"
#include "PlayerTypes.h"
#include "TeamTypes.h"

using Positionals = std::unordered_map<PlayerType, PlayerStats>;

//TODO: add more types with more teams


class PlayerTypeData {
public:
    PlayerTypeData(const Positionals& playerTypeToStats, std::unordered_map<PlayerType, int> maximumAllowedPlayertype) 
        : playerTypeToStats_(playerTypeToStats), maximumAllowedPlayerType_(maximumAllowedPlayertype) {}

    const PlayerStats& getPlayerStats(PlayerType playerType) const {
        return playerTypeToStats_.at(playerType);
    }

    const int getMaximumAllowedPlayerType(PlayerType playerType) const {
        return maximumAllowedPlayerType_.at(playerType);
    }

private:
    Positionals playerTypeToStats_;
    std::unordered_map<PlayerType, int> maximumAllowedPlayerType_;
};

class PlayerFactory {
    public:
        explicit PlayerFactory();
        ~PlayerFactory() {}

        const int getMaximumAllowedPlayerType(TeamType teamType, PlayerType playerType) const;
        Player createPlayer(TeamType teamType, PlayerType playerType, std::string name);
        
    private:
        static std::unordered_map<TeamType, PlayerTypeData> initializePlayerTypeData();
        std::unordered_map<TeamType, PlayerTypeData> teamTypeToPlayerTypeData_;
};

#endif