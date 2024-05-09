#ifndef ACTION_H
#define ACTION_H

enum class ActionType {
    DODGE,
    BLOCK,
    MOVE,
    USE_SKILL,
    FOUL,
    SET_POSITION
};

class Action
{
private:
    ActionType type_;
    double successProbability_;
    virtual double calculateSuccessProbability();
    bool actionSuccessfulResult_;

public:
    Action(ActionType type) : type_(type) {}
    ~Action() {}

    void setResult(bool result) { actionSuccessfulResult_ = result; }
    bool getResult() { return actionSuccessfulResult_; }
};

class BlockAction : public Action
{
private:
    double caclulateSuccessProbability();
    std::vector<Player &> involvedOpposingPlayers_;
    Player &actorPlayer_;
    Player &targetPlayer_;
    int agentPosX_;
    int agentPosY_;
    int targetPosX_;
    int targetPosY;

public:
    BlockAction(Player &actorPlayer, Player &targetPlayer, std::vector<Player &> involvedOpposingPlayers) : Action(ActionType::BLOCK), actorPlayer_(actorPlayer), targetPlayer_(targetPlayer), involvedOpposingPlayers_(involvedOpposingPlayers) {}
    ~BlockAction() {}
};

#endif