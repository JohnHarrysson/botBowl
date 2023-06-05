#include "Event.h"


std::unique_ptr<Event> Event::createEvent(EventType eventType) {
    switch (eventType)
    {
    case EventType::COINT_TOSS:
        /* code */
        break;

    case EventType::PITCH_SETUP:
        break;
    
    default:
        break;
    }
}