#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <memory>

#include "Action.h"
#include "Aliases.h"
#include "Random.h"

enum class EventType {
    COIN_TOSS,
    PITCH_SETUP
};

class Event {
private:
    EventType eventType_;

public:
    Event(EventType eventType) : eventType_(eventType) {}
    virtual ~Event() {}

    virtual ActionVector pollForActions(BoardTensor currentGameState);
    virtual ActionVector pollForActions();
    EventType getEventType() { return eventType_; }


};


class CoinTossEvent : public Event {
    public:
        CoinTossEvent() : Event(EventType::COIN_TOSS) {
            Nuffle randomGenerator;
            randomGenerator.getRandomBool() ? isHomeTeamWin_ = true : isHomeTeamWin_ = false;
        }
        ~CoinTossEvent() {}

        const bool getIsHomeTeamWin() const { return isHomeTeamWin_; }

        ActionVector pollForActions(BoardTensor boardStage) override { return pollForActions(); }
        ActionVector pollForActions() override {
            return getIsHomeTeamWin() ? ActionVector { SelfSetupAction(getHomeAgent()), OpponentSetupAction(getHomeAgent()) } : ActionVector { SelfSetupAction(getAwayAgent()), OpponentSetupAction(getAwayAgent()) };
        }

    private:
        bool isHomeTeamWin_;

};

#endif