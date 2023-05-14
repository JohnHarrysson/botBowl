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
