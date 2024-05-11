#ifndef AGENT_H
#define AGENT_H

#include "Aliases.h"
#include "Team.h"
#include "Event.h"

class DecisionMaker {
    public:
        DecisionMaker() {}
        virtual ~DecisionMaker() {}

        virtual bool makeDecision(ActionVector possibleActions);

};

class Agent : public DecisionMaker {
    public:
        Agent(Team team) : team_(team) {}
        ~Agent() {}

        const Team& getTeam() const { return team_; }

    private:
        Team team_;
};

class HumanAgent : public Agent {
    public:
        HumanAgent(Team team) : Agent(team) {}
        ~HumanAgent() {}

        bool makeDecision(ActionVector possibleActions) override;

};

class AI : public Agent {
    public:
        AI(Team team) : Agent(team) {}
        ~AI() {}

        bool makeDecision(ActionVector possibleActions) override;
};


#endif