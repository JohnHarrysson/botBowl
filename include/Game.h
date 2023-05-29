#ifndef GAME_H
#define GAME_

#include "Agent.h"
#include "Board.h"

class Game {

public:
    Game(Agent homePlayer, Agent awayPlayer, Board board) : homePlayer_(homePlayer), awayPlayer_(awayPlayer), board_(board) {}
    ~Game() {}

    
private:
    Agent homePlayer_;
    Agent awayPlayer_;
    Board board_;
};


#endif