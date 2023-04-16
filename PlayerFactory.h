#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "Player.h"
#include "Team.h"
#include "Aliases.h"

enum class PlayerType {
    Lineman,
    Blitzer,
    Ogre,
    Troll,
    Goblin,
    BigUn,
    Thrower,
    Catcher
}

class PlayerFactory {
    public:
        explicit PlayerFactory();
        ~PlayerFactory() {}
        Player createPlayer(TeamType teamType, PlayerType playerType);
        
        
        
    private:
        PlayerTypeMap m_playerTypeMap;
        struct PlayerStats
        {
           std::string name;
           int strength;
           int agility;
           int movement;
           int armor;
           int pass;
        };
        
}

#endif