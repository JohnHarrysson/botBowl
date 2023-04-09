#include <vector>
#include "Square.h"
#include "Board.h"

Board::Board(int x, int y) : x_(x), y_(y) {

    std::vector<std::vector<Square>> board_{x, std::vector<Square>{y, Square(0,0)}};
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            board_[i][j] = Square(i,j);
        }
    }
}

int Board::getWidth() const {
    return x_;
}

int Board::getHeight() const {
    return y_;
}

Square& Board::getSquare(int x, int y) {
    return board_[x][y];
} 

const Square& Board::getSquare(int x, int y) const {
    return board_[x][y];
}

Board Board::getLayer(LayerType layertype) const {

    switch (static_cast<int>(layertype)) {

    case static_cast<int>(LayerType::OWN_PLAYERS):
        // code to handle own players layer
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
    default:
        // Code to handle unknown layer type
        break;
    }
}