#include "PlayerFactory.h"
#include "DefaultPlayerNames.h"


PlayerFactory::PlayerFactory() : teamTypeToPlayerTypeData_(initializePlayerTypeData()), teamTypeToStartingTeams_(initializeStartingTeams()) {}
      

std::unordered_map<TeamType, PlayerTypeData> PlayerFactory::initializePlayerTypeData() {
    std::unordered_map<TeamType, PlayerTypeData> teamTypeToPlayerTypeData;

    Positionals humanPositionals = {
        {PlayerType::Lineman, {6,3,3,5,8,{},{},{},{},{}, 50000}},
        {PlayerType::Blitzer, {7, 3, 3, 5, 8, {GeneralSkill::Block}, {}, {}, {}, {}, 85000}},
        {PlayerType::Thrower, {6, 3, 3, 2, 8, {GeneralSkill::Sure_Hands}, {}, {}, {PassingSkill::Pass}, {}, 80000}},
        {PlayerType::Catcher, {8, 2, 3, 4, 7, {}, {}, {AgilitySkill::Dodge, AgilitySkill::Catch}, {}, {}, 65000}},
        {PlayerType::Ogre, {5,5,4,5,10, {GeneralSkill::Thick_Skull, GeneralSkill::Bone_Head}, {StrengthSkill::Mighty_Blow}, {}, {}, {}, 140000}}
    };
    std::unordered_map<PlayerType, int> humanMaximumAllowedPlayerTypes {
        {PlayerType::Lineman, 14},
        {PlayerType::Blitzer, 4},
        {PlayerType::Thrower, 2},
        {PlayerType::Catcher, 2},
        {PlayerType::Ogre, 1}
    };

    Positionals orcPositionals = {
        {PlayerType::Lineman, {5, 3, 3, 4, 9, {GeneralSkill::Animosity}, {}, {}, {}, {}, 50000}},
        {PlayerType::Blitzer, {6, 3, 3, 4, 9, {GeneralSkill::Animosity, GeneralSkill::Block}, {}, {}, {}, {}, 80000}},
        {PlayerType::Thrower, {5, 3, 3, 3, 8, {GeneralSkill::Animosity, GeneralSkill::Sure_Hands}, {}, {}, {PassingSkill::Pass}, {}, 65000}},
        {PlayerType::Goblin, {6, 2, 3, 4, 7, {}, {}, {AgilitySkill::Dodge}, {}, {}, 40000}},
        {PlayerType::BigUn, {5, 4, 4, 0, 9, {GeneralSkill::Animosity}, {}, {}, {}, {}, 90000}},
        {PlayerType::Troll, {4,5,5,5,10, {GeneralSkill::Really_Stupid, GeneralSkill::Regeneration}, {StrengthSkill::Mighty_Blow},{},{},{}, 115000}}
    };
    std::unordered_map<PlayerType, int> orcMaximumAllowedPlayerTypes {
        {PlayerType::Lineman, 14},
        {PlayerType::Blitzer, 4},
        {PlayerType::Thrower, 1},
        {PlayerType::Goblin, 14},
        {PlayerType::BigUn, 4},
        {PlayerType::Troll, 1}
    };

    PlayerTypeData humanPlayerTypeData(humanPositionals, humanMaximumAllowedPlayerTypes);
    PlayerTypeData orcPlayerTypeData(orcPositionals, orcMaximumAllowedPlayerTypes);
            

    teamTypeToPlayerTypeData.insert({TeamType::Humans, humanPlayerTypeData});
    teamTypeToPlayerTypeData.insert({TeamType::Orcs, orcPlayerTypeData});

    return teamTypeToPlayerTypeData;
}

std::unordered_map<TeamType, std::vector<PlayerType>> PlayerFactory::initializeStartingTeams() {
    std::unordered_map<TeamType, std::vector<PlayerType>> teamTypeToStartingTeams;
    
    std::vector humanStartingteam {
        PlayerType::Lineman,
        PlayerType::Lineman,
        PlayerType::Lineman,
        PlayerType::Lineman,
        PlayerType::Blitzer,
        PlayerType::Blitzer,
        PlayerType::Blitzer,
        PlayerType::Blitzer,
        PlayerType::Thrower,
        PlayerType::Catcher,
        PlayerType::Ogre
    };

    std::vector orcStartingTeam {
        PlayerType::Lineman,
        PlayerType::Lineman,
        PlayerType::Blitzer,
        PlayerType::Blitzer,
        PlayerType::Blitzer,
        PlayerType::Blitzer,
        PlayerType::BigUn,
        PlayerType::BigUn,
        PlayerType::BigUn,
        PlayerType::BigUn,
        PlayerType::Thrower
    };

    teamTypeToStartingTeams.insert({TeamType::Humans, humanStartingteam});
    teamTypeToStartingTeams.insert({TeamType::Orcs, orcStartingTeam});

    return teamTypeToStartingTeams;
}

const int PlayerFactory::getMaximumAllowedPlayerType(TeamType teamType, PlayerType playerType) const {
    const PlayerTypeData& playerTypeData = teamTypeToPlayerTypeData_.at(teamType);
    int maximumAllowedPlayerType = playerTypeData.getMaximumAllowedPlayerType(playerType);

    return maximumAllowedPlayerType;
}

//TODO: Fix default naming
Player PlayerFactory::createPlayer(TeamType teamType, PlayerType playerType, std::string name) {

    const PlayerTypeData& playerTypeData = teamTypeToPlayerTypeData_.at(teamType);
    const PlayerStats& stats = playerTypeData.getPlayerStats(playerType);

    Player player(name, stats);

    return player;
}

std::vector<Player> PlayerFactory::createStartingTeam(TeamType teamType) {
    std::vector<Player> teamVector;
    DefaultNameGenerator defaultNameGenerator;
    std::vector<PlayerType> startingPlayerTypes;

    switch (teamType)
    {
    case TeamType::Humans:
        startingPlayerTypes = teamTypeToStartingTeams_.at(teamType);
        for (const PlayerType playerType : startingPlayerTypes) {
            teamVector.push_back(createPlayer(teamType, playerType, defaultNameGenerator.getDefaultName(teamType)));
        }
        break;

    case TeamType::Orcs:
        startingPlayerTypes = teamTypeToStartingTeams_.at(teamType);
        for (const PlayerType playerType : startingPlayerTypes) {
            teamVector.push_back(createPlayer(teamType, playerType, defaultNameGenerator.getDefaultName(teamType)));
        }
        break; 
//TODO: Handle error    
    default:
        break;
    }

    return teamVector;
}

