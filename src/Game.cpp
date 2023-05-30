#include "Game.h"

bool Game::step(GameStage currentStage) {
    switch (currentStage)
    {
    case GameStage::CHECK_TEAM_VALUE:
        break;

    case GameStage::PLAYER1_INDUCEMENT:
        break;
    
    case GameStage::PLAYER2_INDUCEMENT:
        break;

    case GameStage::COIN_TOSS:
        break;

    case GameStage::PLAYER1_SETUP:
        break;

    case GameStage::PLAYER2_SETUP:
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