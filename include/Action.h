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
    COIN_FLIP_CHOOSE_SELF,
    COIN_FLIP_CHOOSE_OPPONENT
};

class Action
{
private:
    Agent& agent_;
    ActionType type_;
    double successProbability_;
    bool actionSuccessfulResult_;

protected:
    Action(ActionType type, Agent& agent) : type_(type), agent_(agent) {}
    ~Action() {}

    virtual double calculateSuccessProbability();
    double getSuccessProbability() { return successProbability_; }
    void setSuccessProbability(double probability) { successProbability_ = probability; }

    void setResult(bool result) { actionSuccessfulResult_ = result; }
    bool getResult() { return actionSuccessfulResult_; }

    Agent& getAgent() { return agent_; }
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

class SelfSetupAction : public Action
{
    private:
        double calculateSuccessProbability() { return 1.0; }

    public:
        SelfSetupAction(const Agent& agent) : Action(ActionType::COIN_FLIP_CHOOSE_SELF, agent) {
            generateActionResultEvent();
        }
        ~SelfSetupAction() {}

        Event generateActionResultEvent() { 
            Event 
        }

};

#endif