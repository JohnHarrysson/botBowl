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
        Agent &agent = getHomeAgentReference();
        BoardTensor currentGameState = getBoard().getCurrentGameState();

        Event coinToss(EventType::COIN_TOSS);
        agent.act(coinToss, currentGameState);
        setPreviousStage(GameStage::HOME_INDUCEMENT);

        for (GameStage gameStage : getPreviousStages()) {
            if (GameStage::AWAY_INDUCEMENT == gameStage) {
                return GameStage::COIN_TOSS;
            }
        }
        
        return GameStage::AWAY_INDUCEMENT;
    }
    case GameStage::AWAY_INDUCEMENT: {
        Agent &agent = getHomeAgentReference();
        BoardTensor currentGameState = getBoard().getCurrentGameState();

        Event coinToss(EventType::COIN_TOSS);
        agent.act(coinToss, currentGameState);
        setPreviousStage(GameStage::AWAY_INDUCEMENT);

        for (GameStage gameStage : getPreviousStages()) {
            if (GameStage::AWAY_INDUCEMENT == gameStage) {
                return GameStage::COIN_TOSS;
            }
        }
        
        return GameStage::AWAY_INDUCEMENT;
    }

    case GameStage::COIN_TOSS:
        break;

//TODO::
    case GameStage::HOME_SETUP: {
        Agent &agent = getHomeAgentReference();
        BoardTensor currentGameState = getBoard().getCurrentGameState();

        Event pitchSetup(EventType::PITCH_SETUP);
        Action setupAction = agent.act(pitchSetup, currentGameState);
        BoardTensor newGameState = resolveAction(setupAction);
        getBoard().storeGameState(getGameStateBufferReference(), newGameState);

        break;
    }

    case GameStage::AWAY_SETUP:
        break;

    case GameStage::KICKOFF:
        break;

    case GameStage::KIKCOFF_EVENT:
        break;

    case GameStage::TURN:
        break;

    
    //TODO: Handle error
    default:
        break;
    }
}