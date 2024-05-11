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

    virtual std::vector<Action> pollForActions(BoardTensor currentGameState);
    virtual std::vector<Action> pollForActions();
    EventType getEventType() { return eventType_; }


};


class CoinTossEvent : public Event {
    public:
        CoinTossEvent(Agent& homeAgent, Agent& awayAgent) : Event(EventType::COIN_TOSS), homeAgent_(homeAgent), awayAgent_(awayAgent) {
            Nuffle randomGenerator;
            randomGenerator.getRandomBool() ? isHomeTeamWin_ = true : isHomeTeamWin_ = false;
        }
        ~CoinTossEvent() {}

        const bool getIsHomeTeamWin() const { return isHomeTeamWin_; }
        const Agent& getHomeAgent() const { return homeAgent_; }
        const Agent& getAwayAgent() const { return awayAgent_; }

        std::vector<Action> pollForActions(BoardTensor boardStage) override { return pollForActions(); }
        std::vector<Action> pollForActions() override {
            return getIsHomeTeamWin() ? std::vector<Action> { CoinflipDecisionAction(getHomeAgent()) } : std::vector<Action> { CoinflipDecisionAction(getAwayAgent()) };
        }

    private:
        bool isHomeTeamWin_;
        const Agent& homeAgent_;
        const Agent& awayAgent_;

};

#endif