#ifndef DRIVER_H
#define DRIVER_H

#include "GameStage.h"
#include "Game.h"
#include "PlayerFactory.h"

class GameDriver {
    public:
        explicit GameDriver(const PlayerFactory &playerFactory) 
        : game_(createGame(playerFactory)),
          currentStage_(GameStage::CHECK_TEAM_VALUE) { }
        ~GameDriver() {}

        Game getGame() { return game_; }
        GameStage getCurrentStage() { return currentStage_; }
        
        void setCurrentStage(GameStage nextStage) { currentStage_ = nextStage; }

        void runGame();

        void handleGameOver();


    private:
        Game game_;
        GameStage currentStage_;

        static Game createGame(const PlayerFactory &playerFactory);

};

#endif