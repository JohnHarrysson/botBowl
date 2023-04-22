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

class PlayerFactory {
    public:
        explicit PlayerFactory();
        ~PlayerFactory() {}
        Player createPlayer(TeamType teamType, PlayerType playerType);
        
        
        
    private:
        std::unordered_map<TeamType, TeamData> teamTypeToTeamData_;
    };

#endif