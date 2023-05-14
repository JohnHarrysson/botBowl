
    #include "Player.h"

    const std::unordered_set<StrengthSkill>& Player::getStrengthSkills() const { return playerStats_.strengthSkills; }
    void Player::setStrengthSkills(const std::unordered_set<StrengthSkill> &skills) { playerStats_.strengthSkills = skills; }

    const std::unordered_set<AgilitySkill>& Player::getAgilitySkills() const { return playerStats_.agilitySkills; }
    void Player::setAgilitySkills(const std::unordered_set<AgilitySkill> &skills) { playerStats_.agilitySkills = skills; }

    const std::unordered_set<GeneralSkill>& Player::getGeneralSkills() const { return playerStats_.generalSkills; }
    void Player::setGeneralSkills(const std::unordered_set<GeneralSkill> &skills) { playerStats_.generalSkills = skills; }

    const std::unordered_set<PassingSkill>& Player::getPassingSkills() const { return playerStats_.passingSkills; }
    void Player::setPassingSkills(const std::unordered_set<PassingSkill> &skills) { playerStats_.passingSkills = skills; }

    const std::unordered_set<MutationSkill>& Player::getMutationSkills() const { return playerStats_.mutationSkills; }
    void Player::setMutationSkills(const std::unordered_set<MutationSkill> &skills) { playerStats_.mutationSkills = skills; }

    const std::vector<Wound> Player::getCurrentWounds() { return currentWounds_; }
    void Player::setCurrentWounds(Wound newWound) { currentWounds_.push_back(newWound); }

    const std::vector<Wound> Player::getLastingWounds() { return lastingWounds_; }
    void Player::setLastingWounds(const Wound newLastingWound) { lastingWounds_.push_back(newLastingWound); }
 
    void Player::applyWoundEffect(Wound wound) {
        WoundType woundType = wound.getWoundType();
        switch (woundType) {  
            case WoundType::BADLY_HURT:
                this->setCurrentWounds(woundType);
                break;
            case WoundType::DAMAGED_BACK:
                this->setCurrentWounds(woundType);
                this->setMissNextGame(true);
                this->setLastingWounds(WoundType::NIGGLING_INJURY);
                break;
            case WoundType::SMASHED_KNEE:
                this->setCurrentWounds(woundType);
                this->setMissNextGame(true);
                this->setLastingWounds(WoundType::NIGGLING_INJURY);
                break;
            case WoundType::SMASHED_ANKLE:
                this->setCurrentWounds(wound);
                this->setLastingWounds(wound);
                this->setMissNextGame(true);
                this->setMovement(this->getMovement() - 1);
                break;
            case WoundType::BROKEN_NECK:
                this->setCurrentWounds(wound);
                this->setLastingWounds(wound);
                this->setMissNextGame(true);
                this->setAgility(this->getAgility() - 1);
                break;
            case WoundType::SMASHED_HIP:
                this->setCurrentWounds(wound);
                this->setLastingWounds(wound);
                this->setMissNextGame(true);
                this->setMovement(this->getMovement() - 1);
                break;
            case WoundType::FRACTURED_SKULL:
                this->setCurrentWounds(wound);
                this->setLastingWounds(wound);
                this->setMissNextGame(true);
                this->setArmor(this->getArmor() - 1);
            case WoundType::SERIOUS_CONCUSSION:
                this->setCurrentWounds(wound);
                this->setLastingWounds(wound);
                this->setMissNextGame(true);
                this->setArmor(this->getArmor() - 1);
            case WoundType::SMASHED_COLLARBONE:
                this->setCurrentWounds(wound);
                this->setLastingWounds(wound);
                this->setMissNextGame(true); 
                this->setStrength(this->getStrength() - 1);
            case WoundType::DEATH:
                this->setCurrentWounds(wound);
                this->setIsDead(true);
                break;
            default:
                this->setCurrentWounds(wound);
                this->setMissNextGame(true);
                break;
        }
}