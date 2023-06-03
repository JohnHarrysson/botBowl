#ifndef GAME_H
#define GAME_H

#include "Agent.h"
#include "Board.h"
#include "GameStage.h"

class Game {

public:
    Game(Agent homeAgent, Agent awayAgent, Board board) : homeAgent_(homeAgent), awayAgent_(awayAgent), board_(board) {}
    ~Game() {}

    Agent getHomeAgent() { return homeAgent_; }
    Agent getAwayAgent() { return awayAgent_; }
    Agent &getHomeAgentReference() { return homeAgent_; }
    Agent &getAwayAgentReference() { return awayAgent_; }
    Board getBoard() { return board_; }
    const std::vector<GameStage> getPreviousStages() const { return previousStages_; }

    void setPreviousStage(GameStage currentState) { previousStages_.push_back(currentState); }

    GameStage handleStageAndReturnNextStage(GameStage currentStage);

    
private:
    Agent homeAgent_;
    Agent awayAgent_;
    Board board_;
    std::vector<GameStage> previousStages_;

    void handleInducement(Agent &agent);
};


#endif