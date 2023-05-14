#ifndef STATS_H
#define STATS_H

#include <unordered_set>
#include "Skills.h"

struct PlayerStats {
    int strength;
    int agility;
    int movement;
    int armor;
    int pass;
    std::unordered_set<GeneralSkill> generalSkills;
    std::unordered_set<StrengthSkill> strengthSkills;
    std::unordered_set<AgilitySkill> agilitySkills;
    std::unordered_set<PassingSkill> passingSkills;
    std::unordered_set<MutationSkill> mutationSkills;
    bool missNextGame = false;
    bool isDead = false;
};

#endif