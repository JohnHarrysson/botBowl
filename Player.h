#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <cassert>
#include "Skills.h"
#include "Stats.h"
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

    const std::unordered_set<StrengthSkill>& getStrengthSkills();
    void setStrengthSkills(const std::unordered_set<StrengthSkill> &skills);

    const std::unordered_set<AgilitySkill> &getAgilitySkills();
    void setAgilitySkills(const std::unordered_set<AgilitySkill> &skills);

    const std::unordered_set<GeneralSkill> &getGeneralSkills() const;
    void setGeneralSkills(const std::unordered_set<GeneralSkill> &skills);

    const std::unordered_set<PassingSkill> &getPassingSkills() const;
    void setPassingSkills(const std::unordered_set<PassingSkill> &skills);

    const std::unordered_set<MutationSkill> &getMutationSkills() const;
    void setMutationSkills(const std::unordered_set<MutationSkill> &skills);

    const std::vector<Wounds> getCurrentWounds();
    void setCurrentWounds(Wounds newWound);

    const std::vector<Wounds> getLastingWounds();
    void setLastingWounds(const Wounds& newLastingWound);
    ~Player() {}

private:
    std::string name_;
    PlayerStats playerStats_;
    
    std::vector<Wounds> currentWounds_;
    std::vector<Wounds> lastingWounds_;
};

#endif