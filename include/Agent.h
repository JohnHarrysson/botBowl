#ifndef AGENT_H
#define AGENT_H

#include "Aliases.h"
#include "Team.h"
#include "Action.h"
#include "Event.h"

class Agent {
    public:
        Agent(Team team) : team_(team) {}
        ~Agent() {}

        const Team& getTeam() const { return team_; }

        Action act(Event event, BoardTensor gameState);

    private:
        Team team_;
};


#endif