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
    std::unique_ptr<Event> createEvent(EventType);

public:
    Event(EventType eventType) : eventType_(eventType) { createEvent(eventType_); }
    ~Event();

    std::vector<Action> pollForActions(BoardTensor currentGameState);
    EventType getEventType() { return eventType_; }


};


class CoinTossEvent : public Event {

};

#endif