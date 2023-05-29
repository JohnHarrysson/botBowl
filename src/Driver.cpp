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

