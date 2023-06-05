#include "Board.h"

Board::Board() : boardTensor_(boardWidth, std::vector<std::vector<float>>(boardHeight, std::vector<float>(nrLayers, 0.0f))) {}

void Board::storeGameState(CircularBuffer<BoardTensor> &gameStateBuffer, BoardTensor const currentBoardState) const {
    if (gameStateBuffer.isFull()) {
        gameStateBuffer.pop();
    }
    
    gameStateBuffer.push(currentBoardState);
}

void Board::updateBoardState(BoardTensor& currentState, int x, int y, LayerType layer, float value) {
    currentState[x][y][static_cast<int>(layer)] = value;
}
