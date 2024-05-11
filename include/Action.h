#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include "Player.h"
#include "Agent.h"

enum class ActionType {
    DODGE,
    BLOCK,
    MOVE,
    USE_SKILL,
    FOUL,
    SET_POSITION,
    COIN_FLIP
};

class Action
{
private:
    const Agent& agent_;
    ActionType type_;
    double successProbability_;
    virtual double calculateSuccessProbability();
    bool actionSuccessfulResult_;

public:
    Action(ActionType type, const Agent& agent) : type_(type), agent_(agent) {}
    ~Action() {}

    void setResult(bool result) { actionSuccessfulResult_ = result; }
    bool getResult() { return actionSuccessfulResult_; }
};

class BlockAction : public Action
{
private:
    double caclulateSuccessProbability();
    std::vector<Player&> involvedOpposingPlayers_;
    Player &actorPlayer_;
    Player &targetPlayer_;

public:
    BlockAction(Agent &agent, Player &actorPlayer, Player &targetPlayer, std::vector<Player &> involvedOpposingPlayers) : Action(ActionType::BLOCK, agent), actorPlayer_(actorPlayer), targetPlayer_(targetPlayer), involvedOpposingPlayers_(involvedOpposingPlayers) {}
    ~BlockAction() {}
};

class CoinflipDecisionAction : public Action
{
    private:
        double calculateSuccessProbability() { return 1.0; }

    public:
        CoinflipDecisionAction(const Agent& agent) : Action(ActionType::COIN_FLIP, agent) {}
        ~CoinflipDecisionAction() {}

        void makeHomeOrAwaySetup() { 
            setResult(true); 
        }

};

#endif