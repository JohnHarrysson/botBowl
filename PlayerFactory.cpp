#include "PlayerFactory.h"

PlayerFactory::PlayerFactory() {
     m_playerTypeMap = {
        { 
            TeamType::Humans, 
            { 
                PlayerType::Lineman, {
                    
                }, 
                PlayerType::Blitzer, 
                PlayerType::Thrower, 
                PlayerType::Catcher, 
                PlayerType::Ogre 
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

}