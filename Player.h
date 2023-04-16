#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <unordered_set>
#include "Skills.h"

class Player {
    public:
        Player(const std::string& name, int strength, int agility, int armor, int movement, int pass);
        const std::string& getName() const { return name_; }
        const int getStrength() const { return strength_; }
        const int getAgility() const { return agility_; }
        const int getArmor() const { return armor_; }
        const int getMovement() const { return movement_; }
        bool hasMoved() const { return hasMoved_; }

        void setStrength(int strength) { strength_ = strength; }
        void setAgility(int agility) { agility_ = agility; }
        void setArmor(int armor) { armor_ = armor; }
        void setMovement(int movement) { movement_ = movement; }
        void setHasMoved(bool hasMoved) { hasMoved_ = hasMoved; }

        const std::unordered_set<StrengthSkill>& getStrengthSkills() const { return strengthSkills_; }
        void setStrengthSkills(const std::unordered_set<StrengthSkill>& skills) { strengthSkills_ = skills; }
    
        const std::unordered_set<AgilitySkill>& getAgilitySkills() const { return agilitySkills_; }
        void setAgilitySkills(const std::unordered_set<AgilitySkill>& skills) { agilitySkills_ = skills; }
    
        const std::unordered_set<GeneralSkill>& getGeneralSkills() const { return generalSkills_; }
        void setGeneralSkills(const std::unordered_set<GeneralSkill>& skills) { generalSkills_ = skills; }
        
        const std::unordered_set<PassingSkill>& getPassingSkills() const { return passingSkills_; }
        void setPassingSkills(const std::unordered_set<PassingSkill>& skills) { passingSkills_ = skills; }
        
        const std::unordered_set<MutationSkill>& getMutationSkills() const { return mutationSkills_; }
        void setMutationSkills(const std::unordered_set<MutationSkill>& skills) { mutationSkills_ = skills; }

        ~Player() {}

    private:
        std::string name_;
        int strength_;
        int agility_;
        int armor_;
        int movement_;
        bool hasMoved_;
        std::unordered_set<GeneralSkill> generalSkills_;
        std::unordered_set<StrengthSkill> strengthSkills_;
        std::unordered_set<AgilitySkill> agilitySkills_;
        std::unordered_set<PassingSkill> passingSkills_;
        std::unordered_set<MutationSkill> mutationSkills_;
};


#endif