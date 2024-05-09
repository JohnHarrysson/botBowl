#include "Board.h"

Board::Board() : boardTensor_(boardWidth, std::vector<std::vector<float>>(boardHeight, std::vector<float>(nrLayers, 0.0f))) {}

void Board::storeGameState(CircularBuffer<BoardTensor> &gameStateBuffer, BoardTensor const currentBoardState) const {
    if (gameStateBuffer.isFull()) {
        gameStateBuffer.pop();
    }
    
    gameStateBuffer.push(currentBoardState);
}

void Board::updateBoardState(BoardTensor& currentState, Coordinates coordinates, LayerType layer, float value) {
    currentState[coordinates.x][coordinates.y][static_cast<int>(layer)] = value;
}

const std::set<Coordinates> Board::coordinateSet_ = [] {
    std::set<Coordinates> coords;
    for (int x = 0; x < boardWidth; ++x) {
        for (int y = 0; y < boardHeight; ++y) {
            coords.insert({x, y});
        }
    }
    return coords;
}();
