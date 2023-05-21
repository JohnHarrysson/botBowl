#ifndef DEFAULT_PLAYER_NAMES_H
#define DEFAULT_PLAYER_NAMES_H

#include <string>
#include <vector>
#include "TeamTypes.h"
#include "Random.h"

struct DefaultPlayerNames
{
    std::vector<std::string> humanDefaultNames {
        "Destin",
        "Robby",
        "Seabert",
        "Floyd",
        "Rene",
        "Nick",
        "Jervis",
        "Hugbert",
        "Florentin",
        "Hildebrand",
        "Samy",
        "Ludovic",
        "Fairley",
        "Hans-carl",
        "Isai",
        "Reade"
    };

    std::vector<std::string> orcDefaultNames {
        "Grub",
        "Oglog",
        "Marzug",
        "Hugblob",
        "Orcas",
        "Wuzzuk",
        "Grimlob",
        "Gorgnot",
        "Tonk",
        "Ghazrak",
        "Rogding",
        "Kurz",
        "Marzug",
        "Zugzug",
        "Gorbag"
    };

    std::string getDefaultName(TeamType teamType) {
        int randomIndex;
        switch (teamType)
        {
        case TeamType::Humans:
            randomIndex = getRandomIndex(0, humanDefaultNames.size() - 1);
            return humanDefaultNames[randomIndex];
        
        case TeamType::Orcs:
            randomIndex = getRandomIndex(0, orcDefaultNames.size() - 1);
            return orcDefaultNames[randomIndex];

        default:
            return "";
        }
    }
};



#endif