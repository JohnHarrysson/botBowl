#include "Game.h"

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
        Agent agent = getHomeAgentReference();
        handleInducement(agent);
        setPreviousStage(GameStage::HOME_INDUCEMENT);
        break;
    }
    case GameStage::AWAY_INDUCEMENT:
        break;

    case GameStage::COIN_TOSS:
        break;

    case GameStage::HOME_SETUP:
        break;

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