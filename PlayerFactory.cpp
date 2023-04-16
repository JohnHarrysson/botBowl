#include "PlayerFactory.h"

PlayerFactory::PlayerFactory() {
     m_playerTypeMap = {
        { 
            TeamType::Humans, 
            { 
                {
                PlayerType::Lineman, 
                    {
                        6, 3, 3, 5, 8,
                        {},
                        {},
                        {},
                        {},
                        {}
                    } 
                },
                {
                    PlayerType::Blitzer, 
                    {
                        7, 3, 3, 5, 8,
                        { GeneralSkill::Block },
                        {},
                        {},
                        {},
                        {}
                    }
                },
                {
                    PlayerType::Thrower, 
                    {
                        6, 3, 3, 2, 8,
                        { GeneralSkill::Sure_Hands},
                        {},
                        {},
                        { PassingSkill::Pass },
                        {}
                    }
                },
                {
                    PlayerType::Catcher, 
                    {
                        8, 2, 3, 4, 7,
                        {},
                        {},
                        {AgilitySkill::Dodge, AgilitySkill::Catch},
                        {},
                        {}
                    }
                },
                {
                    PlayerType::Ogre, 
                    {
                        5, 5, 4, 5, 10,
                        { GeneralSkill::Thick_Head },
                        { StrengthSkill::Mighty_Blow },
                        {},
                        {},
                        {}
                    }
                }
            } 
        },
        { 
            TeamType::Orcs, 
            { 
            PlayerType::Lineman, 
            PlayerType::Blitzer, 
            PlayerType::Thrower, 
            PlayerType::Goblin, 
            PlayerType::BigUn, 
            PlayerType::Troll 
            } 
        },
        { 
            TeamType::Elven_Union, 
            { 
                PlayerType::Lineman, 
                PlayerType::Blitzer, 
                PlayerType::Thrower, 
                PlayerType::Catcher 
            } 
        }
        //TODO: Add entries for other teams 
    }
}

Player PlayerFactory::createPlayer(TeamType teamType, PlayerType playerType) {
    m_playerTypeMap[teamType][playerType][]
}