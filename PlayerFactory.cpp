#include <unordered_map>
#include "PlayerFactory.h"

PlayerFactory::PlayerFactory()
    : teamTypeToTeamData_ {
      {TeamType::Humans, TeamData{}}
    } 
{}
/*
m_playerTypeMap{
          {TeamType::Humans,
           {{PlayerType::Lineman, {6, 3, 3, 5, 8, {}, {}, {}, {}, {}}},
            {PlayerType::Blitzer, {7, 3, 3, 5, 8, {GeneralSkill::Block}, {}, {}, {}, {}}},
            {PlayerType::Thrower, {6, 3, 3, 2, 8, {GeneralSkill::Sure_Hands}, {}, {}, {PassingSkill::Pass}, {}}},
            {PlayerType::Catcher, {8, 2, 3, 4, 7, {}, {}, {AgilitySkill::Dodge, AgilitySkill::Catch}, {}, {}}},
            {PlayerType::Ogre,
             {5, 5, 4, 5, 10, {GeneralSkill::Thick_Skull, GeneralSkill::Bone_Head}, {StrengthSkill::Mighty_Blow}, {}, {}, {}}}}},
          {TeamType::Orcs,
           {{PlayerType::Lineman, {5, 3, 3, 4, 9, {GeneralSkill::Animosity}, {}, {}, {}, {}}},
            {PlayerType::Blitzer, {6, 3, 3, 4, 9, {GeneralSkill::Animosity, GeneralSkill::Block}, {}, {}, {}, {}}},
            {PlayerType::Thrower, {5, 3, 3, 3, 8, {GeneralSkill::Animosity, GeneralSkill::Sure_Hands}, {}, {}, {PassingSkill::Pass}, {}}},
            {PlayerType::Goblin, {6, 2, 3, 4, 7, {}, {}, {AgilitySkill::Dodge}, {}, {}}},
            {PlayerType::BigUn, {5, 4, 4, 0, 9, {GeneralSkill::Animosity}, {}, {}, {}, {}}},
            {PlayerType::Troll,
             {4, 5, 5, 5, 9, {GeneralSkill::Really_Stupid, GeneralSkill::Regeneration}, {StrengthSkill::Mighty_Blow}, {}, {}, {}}}}}
      }
      */
Player PlayerFactory::createPlayer(TeamType teamType, PlayerType playerType) {
    auto &playerMap = m_playerTypeMap[teamType];

    const PlayerStats &stats = playerMap[playerType];

    Player player("Unnamed", stats.strength, stats.agility, stats.armor, stats.movement, stats.pass, stats.strengthSkills, stats.agilitySkills, stats.generalSkills, stats.passingSkills, stats.mutationSkills);

    return player;
}
