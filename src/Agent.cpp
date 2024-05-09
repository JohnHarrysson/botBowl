#include "Agent.h"

Action Agent::act(Event event, BoardTensor gameState) {
    std::vector<Action> possibleActions = event.pollForActions(gameState);
    return possibleActions[0];
}
