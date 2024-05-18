#include "Game.h"
#include "Event.h"

GameStage Game::handleStageAndReturnNextStage(GameStage currentStage) {
    switch (currentStage)
    {
    case GameStage::CHECK_TEAM_VALUE: {
        int homeTeamValue = getHomeAgent().getTeam().getTeamValue();
        int awayTeamValue = getAwayAgent().getTeam().getTeamValue();
        
        setPreviousStage(GameStage::CHECK_TEAM_VALUE);
        return homeTeamValue <= awayTeamValue ? GameStage::HOME_INDUCEMENT : GameStage::AWAY_INDUCEMENT;
    }
    case GameStage::HOME_INDUCEMENT: {
        setPreviousStage(GameStage::HOME_INDUCEMENT);

        for (GameStage gameStage : getPreviousStages()) {
            if (GameStage::AWAY_INDUCEMENT == gameStage) {
                return GameStage::COIN_TOSS;
            }
        }
        
        return GameStage::AWAY_INDUCEMENT;
    }
    case GameStage::AWAY_INDUCEMENT: {
        setPreviousStage(GameStage::AWAY_INDUCEMENT);

        for (GameStage gameStage : getPreviousStages()) {
            if (GameStage::HOME_INDUCEMENT == gameStage) {
                return GameStage::COIN_TOSS;
            }
        }
        
        return GameStage::AWAY_INDUCEMENT;
    }

    case GameStage::COIN_TOSS: {
        CoinTossEvent coinToss(getHomeAgentReference(), getAwayAgentReference());

        BoardTensor currentGameState = getBoard().getCurrentGameState();

        ActionVector actionVector = coinToss.pollForActions();

    }

//TODO::
    case GameStage::HOME_SETUP: {
        BoardTensor currentGameState = getBoard().getCurrentGameState();

        Event pitchSetup(EventType::PITCH_SETUP);
        BoardTensor newGameState = resolveAction(setupAction);
        getBoard().storeGameState(getGameStateBufferReference(), newGameState);

         }
   

    case GameStage::AWAY_SETUP:
        return GameStage::AWAY_SETUP;

    case GameStage::KICKOFF:
        return GameStage::KICKOFF;

    case GameStage::KIKCOFF_EVENT:
        return GameStage::KIKCOFF_EVENT;

    case GameStage::TURN:
        return GameStage::TURN;

    
    //TODO: Handle error
    default:
        break;
    }
}

BoardTensor Game::resolveAction(Action action) {
    BoardTensor currentState = getBoard().getCurrentGameState();
    board_.updateBoardState(currentState, action);
}