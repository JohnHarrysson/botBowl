#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player {
    public:
        Player(const std::string& name, int strength, int agility, int armor, int movement, bool isHuman);
        const std::string& getName() const { return name_; }
        int getStrength() const { return strength_; }
        int getAgility() const { return agility_; }
        int getArmor() const { return armor_; }
        int getMovement() const { return movement_; }
        bool isHuman() const { return isHuman_; }
        bool hasMoved() const { return hasMoved_; }

        void setStrength(int strength) { strength_ = strength; }
        void setAgility(int agility) { agility_ = agility; }
        void setArmor(int armor) { armor_ = armor; }
        void setMovement(int movement) { movement_ = movement; }
        void setHuman(bool isHuman) { isHuman_ = isHuman; }
        void setHasMoved(bool hasMoved) { hasMoved_ = hasMoved; }


    private:
        std::string name_;
        int strength_;
        int agility_;
        int armor_;
        int movement_;
        bool isHuman_;
        bool hasMoved_;
};

class PlayerList {
public:
    void addPlayer(const Player& player) { players_.push_back(player); }
    const std::vector<Player>& getPlayers() const { return players_; }

private:
    std::vector<Player> players_;
};

#endif