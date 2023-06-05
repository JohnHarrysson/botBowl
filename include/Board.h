#include <vector>
#include "Aliases.h"
#include "GameStateBuffer.h"

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
    OWN_PLAYER_TYPES,
    OPPOSING_PLAYER_TYPES,
    OWN_PLAYER_STATES,
    OPPOSING_PLAYER_STATES,
    GAME_INFO
};

class Board {
    public:
        Board();
        ~Board() {}

        constexpr static int boardHeight{26};
        constexpr static int boardWidth{15};
        constexpr static int nrLayers{14};

        void storeGameState(CircularBuffer<BoardTensor>& gameStateBuffer, BoardTensor const currentGameState) const;
        const BoardTensor getCurrentGameState() const { return boardTensor_; }

        Board getLayer(LayerType) const;

        void updateBoardState(BoardTensor& currentState, int x, int y, LayerType layer, float value);
    
    private:
        BoardTensor boardTensor_;
};

#endif