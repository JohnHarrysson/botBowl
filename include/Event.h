#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <memory>

#include "EventType.h"
#include "Action.h"
#include "Aliases.h"

class Event {
private:
    EventType eventType_;

public:
    Event(EventType eventType) : eventType_(eventType) {}
    virtual ~Event() {}

    virtual std::vector<Action> pollForActions(BoardTensor currentGameState);
    EventType getEventType() { return eventType_; }


};


class CoinTossEvent : public Event {
    public:
        CoinTossEvent() : Event(EventType::COIN_TOSS) {}
        ~CoinTossEvent() {}

        std::vector<Action> pollForActions(BoardTensor currentGameState);

};

#endif