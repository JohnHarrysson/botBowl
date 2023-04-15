#include "Team.h"


Team::Team(TeamType teamName, std::string name) : teamName_(teamName), name_(name) {}
Team::Team(TeamType teamName, std::string name, std::vector<Player&> players) : teamName_(teamName), name_(name), players_(players) {}