#ifndef AGENT_H
#define AGENT_H

#include "Team.h"

class Agent {
    public:
        Agent(Team team) : team_(team) {}
        ~Agent() {}

        void act();

    private:
        Team team_;
};


#endif