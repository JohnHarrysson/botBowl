#ifndef GAMESTATEBUFFER_H
#define GAMESTATEBUFFER_H

#include <vector>
#include <cassert>

template<typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(size_t size)
        : buffer(size), head(0), tail(0), count(0) {}

    void push(const T& value);

    T pop();

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == buffer.size();
    }

    size_t size() const {
        return count;
    }

private:
    std::vector<T> buffer;
    size_t head;
    size_t tail;
    size_t count;
};

#endif