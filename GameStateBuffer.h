#ifndef GAMESTATEBUFFER_H
#define GAMESTATEBUFFER_H

#include <vector>
#include <cassert>

template<typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(size_t size)
        : buffer_(size), head_(0), tail_(0), count_(0) {}

    ~CircularBuffer() {}

    void push(const T& value);

    T pop();

    bool isEmpty() const {
        return count_ == 0;
    }

    bool isFull() const {
        return count_ == buffer_.size();
    }

    size_t size() const {
        return count_;
    }

private:
    std::vector<T> buffer_;
    size_t head_;
    size_t tail_;
    size_t count_;
};

#endif