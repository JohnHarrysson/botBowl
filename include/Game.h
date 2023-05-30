#ifndef GAME_H
#define GAME_H

#include "Agent.h"
#include "Board.h"
#include "GameStage.h"

class Game {

public:
    Game(Agent homePlayer, Agent awayPlayer, Board board) : homePlayer_(homePlayer), awayPlayer_(awayPlayer), board_(board) {}
    ~Game() {}

    bool step(GameStage currentStage);

    
private:
    Agent homePlayer_;
    Agent awayPlayer_;
    Board board_;
};


#endif