#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "Player.h"
#include "Team.h"
#include "Aliases.h"

//TODO: add more types with more teams
enum class PlayerType {
    Lineman,
    Blitzer,
    Ogre,
    Troll,
    Goblin,
    BigUn,
    Thrower,
    Catcher
};

struct PlayerStats {
    int strength;
    int agility;
    int movement;
    int armor;
    int pass;
    std::unordered_set<GeneralSkill> generalSkills;
    std::unordered_set<StrengthSkill> strengthSkills;
    std::unordered_set<AgilitySkill> agilitySkills;
    std::unordered_set<PassingSkill> passingSkills;
    std::unordered_set<MutationSkill> mutationSkills;
};

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