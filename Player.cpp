#include "Player.h"
#include <vector>

Player::Player(const std::string name, int strength, int agility, int armor, int movement, int pass,
               const std::unordered_set<StrengthSkill>& strengthSkills,
               const std::unordered_set<AgilitySkill>& agilitySkills,
               const std::unordered_set<GeneralSkill>& generalSkills,
               const std::unordered_set<PassingSkill>& passingSkills,
               const std::unordered_set<MutationSkill>& mutationSkills)
    : name_(name), strength_(strength), agility_(agility), armor_(armor), movement_(movement), pass_(pass),
      strengthSkills_(strengthSkills), agilitySkills_(agilitySkills), generalSkills_(generalSkills),
      passingSkills_(passingSkills), mutationSkills_(mutationSkills) {}