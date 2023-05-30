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

    Game game(player1, player2, board);

    return game;
}

void GameDriver::runGame() {
    while (true){
        //TODO: handle based on true/false returned
        getGame().step(currentStage_);

        //TODO: handle so stage can be set on demand (play forward o backward)
        GameStage nextStage = static_cast<GameStage>(static_cast<int>(currentStage_) + 1); 

        setCurrentStage(nextStage);

        if (currentStage_ == GameStage::GAME_OVER) {
                break;
        }
    }

    handleGameOver();
}