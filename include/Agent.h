#ifndef AGENT_H
#define AGENT_H

#include "Aliases.h"
#include "Team.h"
#include "Event.h"
#include "Errors.h"

class DecisionMaker {
    public:
        DecisionMaker() {}
        virtual ~DecisionMaker() {}

        virtual bool makeDecision(ActionVector possibleActions);

};

class Agent : public DecisionMaker {
    public:
        Agent(Team team) : team_(team), isCurrentPlayer_(false) {}
        ~Agent() {}

        const Team& getTeam() const { return team_; }

        bool isCurrentPlayer() { return isCurrentPlayer_; }

        static Agent& getCurrentPlayer() {
            if (currentPlayer_ == nullptr) {
                PlayerException("Current player is not set.");
            }
            return *currentPlayer_;
        }

        void setCurrentPlayer (bool makeCurrentPlayer) {
            if (makeCurrentPlayer) {
                if (currentPlayer_ != nullptr) {
                    currentPlayer_ -> isCurrentPlayer_ = false;
                }
                currentPlayer_ = this;
            }
            isCurrentPlayer_ = makeCurrentPlayer;
        }


    private:
        Team team_;

        bool isCurrentPlayer_;
        static Agent* currentPlayer_;
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