
    #include "Player.h"

    const std::unordered_set<StrengthSkill>& Player::getStrengthSkills() const { return playerStats_.strengthSkills; }
    void Player::setStrengthSkills(const std::unordered_set<StrengthSkill> &skills) { playerStats_.strengthSkills = skills; }

    const std::unordered_set<AgilitySkill>& Player::getAgilitySkills() const { return playerStats_.agilitySkills; }
    void Player::setAgilitySkills(const std::unordered_set<AgilitySkill> &skills) { playerStats_.agilitySkills = skills; }

    const std::unordered_set<GeneralSkill>& Player::getGeneralSkills() const { return playerStats_.generalSkills; }
    void setGeneralSkills(const std::unordered_set<GeneralSkill> &skills) { playerStats_.generalSkills = skills; }

    const std::unordered_set<PassingSkill>& Player::getPassingSkills() const { return playerStats_.passingSkills; }
    void setPassingSkills(const std::unordered_set<PassingSkill> &skills) { playerStats_.passingSkills = skills; }

    const std::unordered_set<MutationSkill>& Player::getMutationSkills() const { return playerStats_.mutationSkills; }
    void setMutationSkills(const std::unordered_set<MutationSkill> &skills) { playerStats_.mutationSkills = skills; }

    const std::vector<Wounds> Player::getCurrentWounds() { return currentWounds_; }
    void Player::setCurrentWounds(Wounds newWound) { currentWounds_.push_back(newWound); }

    const std::vector<Wounds> Player::getLastingWounds() { return lastingWounds_; }
    void Player::setLastingWounds(const Wounds& newLastingWound) { lastingWounds_.push_back(newLastingWound); }
 