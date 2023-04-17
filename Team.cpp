#include "Team.h"


Team::Team(TeamType teamType, std::string name) : teamType_(teamType), name_(name) {}
Team::Team(TeamType teamType, std::string name, std::vector<Player&> players) : teamType_(teamType), name_(name), players_(players) {}
