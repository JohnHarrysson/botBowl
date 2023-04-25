#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <unordered_set>
#include <cassert>
#include "Skills.h"
#include "Wounds.h"

class Player
{
public:
    Player(const std::string name, PlayerStats stats) : name_(name), playerStats_(stats) {}

    const std::string &getName() const { return name_; }
    const int getStrength() const { return playerStats_.strength; }
    const int getAgility() const { return playerStats_.agility; }
    const int getArmor() const { return playerStats_.armor; }
    const int getMovement() const { return playerStats_.movement; }

    void setStrength(int strength) { playerStats_.strength = strength; }
    void setAgility(int agility) { playerStats_.agility = agility; }
    void setArmor(int armor) { playerStats_.armor = armor; }
    void setMovement(int movement) { playerStats_.movement = movement; }

    const std::unordered_set<StrengthSkill> &getStrengthSkills() const { return playerStats_.strengthSkills; }
    void setStrengthSkills(const std::unordered_set<StrengthSkill> &skills) { playerStats_.strengthSkills = skills; }

    const std::unordered_set<AgilitySkill> &getAgilitySkills() const { return playerStats_.agilitySkills; }
    void setAgilitySkills(const std::unordered_set<AgilitySkill> &skills) { playerStats_.agilitySkills = skills; }

    const std::unordered_set<GeneralSkill> &getGeneralSkills() const { return playerStats_.generalSkills; }
    void setGeneralSkills(const std::unordered_set<GeneralSkill> &skills) { playerStats_.generalSkills = skills; }

    const std::unordered_set<PassingSkill> &getPassingSkills() const { return playerStats_.passingSkills; }
    void setPassingSkills(const std::unordered_set<PassingSkill> &skills) { playerStats_.passingSkills = skills; }

    const std::unordered_set<MutationSkill> &getMutationSkills() const { return playerStats_.mutationSkills; }
    void setMutationSkills(const std::unordered_set<MutationSkill> &skills) { playerStats_.mutationSkills = skills; }

    const std::vector<Wounds> getCurrentWounds() { return currentWounds_; }
    void setCurrentWounds(Wounds newWound) { currentWounds_.push_back(newWound); }

    const std::vector<Wounds> getLastingWounds() { return lastingWounds_; }
    void setLastingWounds(const Wounds& newLastingWound) { lastingWounds_.push_back(newLastingWound); }
    ~Player() {}

private:
    std::string name_;
    PlayerStats playerStats_;
    
    std::vector<Wounds> currentWounds_;
    std::vector<Wounds> lastingWounds_;
};

#endif