#include "Driver.h"
#include "Team.h"
#include "TeamTypes.h"
#include "Agent.h"
#include "Board.h"

Game GameDriver::createGame(const PlayerFactory &playerFactory) {
    Team humanTeam(TeamType::Humans, "The humans", playerFactory);
    humanTeam.generateStartingTeam();
    Team orcTeam(TeamType::Orcs, "The orcs", playerFactory);
    orcTeam.generateStartingTeam();

    Agent player1(humanTeam);
    Agent player2(orcTeam);
    Board board;
    // TODO: Fix hard coding
    int numStates{400};
    CircularBuffer<BoardTensor> gameStateBuffer(numStates);

    Game game(player1, player2, board, gameStateBuffer);

    return game;
}

void GameDriver::runGame() {
    while (true){
        GameStage nextStage = getGame().handleStageAndReturnNextStage(currentStage_);

        setCurrentStage(nextStage);

        if (currentStage_ == GameStage::GAME_OVER) {
                break;
        }
    }

    handleGameOver();
}

void GameDriver::handleGameOver() {
    // Roll for money etc
}