#ifndef GAME_H
#define GAME_H

#include "Agent.h"
#include "Board.h"
#include "GameStage.h"
#include "GameStateBuffer.h"

class Game {

public:
    Game(Agent homeAgent, Agent awayAgent, Board board, CircularBuffer<BoardTensor> gameStateBuffer) : homeAgent_(homeAgent), awayAgent_(awayAgent), board_(board), gameStateBuffer_(gameStateBuffer), {}
    ~Game() {}

    Agent &getHomeAgentReference() { return homeAgent_; }
    Agent &getAwayAgentReference() { return awayAgent_; }

    Agent getHomeAgent() { return homeAgent_; }
    Agent getAwayAgent() { return awayAgent_; }
    Agent& getCurrentPlayingAgent() { 
        return getHomeAgentReference().getCurrentPlayer()
    }

    const Board getBoard() const { return board_; }
    CircularBuffer<BoardTensor> &getGameStateBufferReference() { return gameStateBuffer_; }

    const std::vector<GameStage> getPreviousStages() const { return previousStages_; }
    void setPreviousStage(GameStage currentStage) { previousStages_.push_back(currentStage); }

    GameStage handleStageAndReturnNextStage(GameStage currentStage);
   
private:
    Agent homeAgent_;
    Agent awayAgent_;
    const Agent* currentAgent_;
    Board board_;
    CircularBuffer<BoardTensor> gameStateBuffer_;
    std::vector<GameStage> previousStages_;

    void handleInducement(Agent &agent);
    BoardTensor resolveAction(Action action);
};


#endif