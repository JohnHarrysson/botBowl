#include <vector>
#include "Board.h"

Board::Board() : board_(boardWidth, std::vector<std::vector<float>>(boardHeight, std::vector<float>(nrLayers, 0.0f))) {}

void Board::storeBoardState(CircularBuffer<BoardTensor>& gameStateBuffer, BoardTensor const currentState) const {
    if (gameStateBuffer.isFull()) {
        gameStateBuffer.pop();
    }
    
    gameStateBuffer.push(currentState);
}

void Board::updateBoardState(BoardTensor& currentState, int x, int y, LayerType layer, float value) {
    currentState[x][y][static_cast<int>(layer)] = value;
}

Board Board::getLayer(LayerType layertype) const {
    switch (static_cast<int>(layertype)) {

    case static_cast<int>(LayerType::OWN_PLAYERS):
       break;
    case static_cast<int>(LayerType::OPPOSING_PLAYERS):
        // Code to handle OPPOSING_PLAYERS layer
        break;
    case static_cast<int>(LayerType::OWN_HALF):
        // Code to handle OWN_HALF layer
        break;
    case static_cast<int>(LayerType::OPPOSING_HALF):
        // Code to handle OPPOSING_HALF layer
        break;
    case static_cast<int>(LayerType::BALL):
        // Code to handle BALL layer
        break;
    case static_cast<int>(LayerType::OWN_SCORING):
        // Code to handle OWN_SCORING layer
        break;
    case static_cast<int>(LayerType::OPPOSING_SCORING):
        // Code to handle OPPOSING_SCORING layer
        break;
    case static_cast<int>(LayerType::OWN_TACKLEZONES):
        // Code to handle OWN_TACKLEZONES layer
        break;
    case static_cast<int>(LayerType::OPPOSING_TACKLEZONES):
        // Code to handle OPPOSING_TACKLEZONES layer
        break;
    case static_cast<int>(LayerType::OWN_PLAYER_TYPES):
        // Code to handle oWN_PLAYER_TYPES layer
        break;
    case static_cast<int>(LayerType::OPPOSING_PLAYER_TYPES):
        // Code to handle OPPOSING PLAYER TYPES layer
        break;
    case static_cast<int>(LayerType::OWN_PLAYER_STATES):
        // Code to handle OWN PLAYER STATES layer
        break;
    case static_cast<int>(LayerType::OPPOSING_PLAYER_STATES):
        // Code to handle OPPOSING PLAYER STATES layer
        break;
    default:
    // Some throw I guess.
        break;
    }
}