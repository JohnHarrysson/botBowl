#ifndef ALIASES_H
#define ALIASES_H

#include <vector>
#include <unordered_map>
#include "PlayerFactory.h"

using BoardTensor = std::vector<std::vector<std::vector<float>>>;
using Positionals = std::unordered_map<PlayerType, PlayerStats>;

#endif