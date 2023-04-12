#include "GameStateBuffer.h"

template<typename T>
void CircularBuffer<T>::push(const T& value) {
    buffer[head] = value;
    head = (head + 1) % buffer.size();
    if (count < buffer.size()) {
        count++;
    } else {
        tail = (tail + 1) % buffer.size();
    }
}

template<typename T>
T CircularBuffer<T>::pop() {
    assert(!isEmpty());
    T value = buffer[tail];
    tail = (tail + 1) % buffer.size();
    count--;
    return value;
}
