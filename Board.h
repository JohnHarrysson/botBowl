#include <vector>
#include "Square.h"

#ifndef BOARD_H
#define BOARD_H

enum class LayerType {
    OWN_PLAYERS,
    OPPOSING_PLAYERS,
    OWN_HALF,
    OPPOSING_HALF,
    BALL,
    OWN_SCORING,
    OPPOSING_SCORING,
    OWN_TACKLEZONES,
    OPPOSING_TACKLEZONES,
    PLAYER_TYPES
};

class Board {
    public:
        Board::Board(int x, int y);

        int getWidth() const;
        int getHeight() const;

        Square& getSquare(int x, int y);
        const Square& getSquare(int x, int y) const;

        Board getLayer(enum LayerType) const;
    
    private:
        const int x_, y_;
        std::vector<std::vector<Square>> board_;
};

#endif