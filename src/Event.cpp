#include "Event.h"
#include <iostream>

std::vector<Action> CoinTossEvent::pollForActions(BoardTensor currentGameState) {
    std::cout << "The polling works\n";

    return std::vector<Action> {Action(ActionType::BLOCK), Action(ActionType::DODGE)};
}