#include "Player.h"
#include <vector>

Player::Player(const std::string& name, int strength, int agility, int armor, int movement, bool isHuman) :
    name_(name), strength_(strength), agility_(agility), armor_(armor), movement_(movement), isHuman_(isHuman),
hasMoved_(false) {}