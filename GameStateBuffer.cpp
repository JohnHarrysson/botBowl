#include "GameStateBuffer.h"

template<typename T>
void CircularBuffer<T>::push(const T& value) {
    buffer_[head_] = value;
    head_ = (head_ + 1) % buffer_.size();
    if (count_ < buffer_.size()) {
        count_++;
    } else {
        tail_ = (tail_ + 1) % buffer_.size();
    }
}

template<typename T>
T CircularBuffer<T>::pop() {
    assert(!isEmpty());
    T value = buffer_[tail_];
    tail_ = (tail_ + 1) % buffer_.size();
    count_--;
    return value;
}
