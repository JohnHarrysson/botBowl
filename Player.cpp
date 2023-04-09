#include <string>
#include <vector>
#include "Square.h"

class Player {
public:
    Player(const std::string& name, int strength, int agility, int armor, int movement, bool isHuman)
        : name_(name), strength_(strength), agility_(agility), armor_(armor), movement_(movement), isHuman_(isHuman),
          position_(nullptr), hasMoved_(false) {}

    const std::string& getName() const { return name_; }
    int getStrength() const { return strength_; }
    int getAgility() const { return agility_; }
    int getArmor() const { return armor_; }
    int getMovement() const { return movement_; }
    bool isHuman() const { return isHuman_; }
    bool hasMoved() const { return hasMoved_; }
    const Square* getPosition() const { return position_; }

    void setStrength(int strength) { strength_ = strength; }
    void setAgility(int agility) { agility_ = agility; }
    void setArmor(int armor) { armor_ = armor; }
    void setMovement(int movement) { movement_ = movement; }
    void setHuman(bool isHuman) { isHuman_ = isHuman; }
    void setHasMoved(bool hasMoved) { hasMoved_ = hasMoved; }
    void setPosition(Square* position) { position_ = position; }

private:
    std::string name_;
    int strength_;
    int agility_;
    int armor_;
    int movement_;
    bool isHuman_;
    const Square* position_;
    bool hasMoved_;
};

class PlayerList {
public:
    void addPlayer(const Player& player) { players_.push_back(player); }
    const std::vector<Player>& getPlayers() const { return players_; }

private:
    std::vector<Player> players_;
};