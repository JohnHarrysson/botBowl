#include "Aliases.h"
#include <unordered_map>
#include "PlayerFactory.h"

PlayerFactory::PlayerFactory() : teamTypeToPlayerTypeData_(initializePlayerTypeData()) {}
      

std::unordered_map<TeamType, PlayerTypeData> PlayerFactory::initializePlayerTypeData() {
    std::unordered_map<TeamType, PlayerTypeData> playerTypeMap;

    Positionals humanPositionals = {
        {PlayerType::Lineman, {6,3,3,5,8,{},{},{},{},{}}},
        {PlayerType::Blitzer, {7, 3, 3, 5, 8, {GeneralSkill::Block}, {}, {}, {}, {}}},
        {PlayerType::Thrower, {6, 3, 3, 2, 8, {GeneralSkill::Sure_Hands}, {}, {}, {PassingSkill::Pass}, {}}},
        {PlayerType::Catcher, {8, 2, 3, 4, 7, {}, {}, {AgilitySkill::Dodge, AgilitySkill::Catch}, {}, {}}},
        {PlayerType::Ogre, {5,5,4,5,10, {GeneralSkill::Thick_Skull, GeneralSkill::Bone_Head}, {StrengthSkill::Mighty_Blow}, {}, {}, {}}}
    };
    Positionals orcPositionals = {
        {PlayerType::Lineman, {5, 3, 3, 4, 9, {GeneralSkill::Animosity}, {}, {}, {}, {}}},
        {PlayerType::Blitzer, {6, 3, 3, 4, 9, {GeneralSkill::Animosity, GeneralSkill::Block}, {}, {}, {}, {}}},
        {PlayerType::Thrower, {5, 3, 3, 3, 8, {GeneralSkill::Animosity, GeneralSkill::Sure_Hands}, {}, {}, {PassingSkill::Pass}, {}}},
        {PlayerType::Goblin, {6, 2, 3, 4, 7, {}, {}, {AgilitySkill::Dodge}, {}, {}}},
        {PlayerType::BigUn, {5, 4, 4, 0, 9, {GeneralSkill::Animosity}, {}, {}, {}, {}}},
        {PlayerType::Troll, {4,5,5,5,10, {GeneralSkill::Really_Stupid, GeneralSkill::Regeneration}, {StrengthSkill::Mighty_Blow},{},{},{}}}
    };

    PlayerTypeData humanPlayerTypeData(humanPositionals);
    PlayerTypeData orcPlayerTypeData(orcPositionals);
            

    playerTypeMap[TeamType::Humans] = humanPlayerTypeData;
    playerTypeMap[TeamType::Orcs] = orcPlayerTypeData;

    return playerTypeMap;
}

Player PlayerFactory::createPlayer(TeamType teamType, PlayerType playerType, std::string name) {

    const PlayerTypeData& playerTypeData = teamTypeToPlayerTypeData_.at(teamType);
    const PlayerStats& stats = playerTypeData.getPlayerStats(playerType);

    Player player(name, stats.strength, stats.agility, stats.armor, stats.movement, stats.pass, stats.strengthSkills, stats.agilitySkills, stats.generalSkills, stats.passingSkills, stats.mutationSkills);

    return player;
}
