#ifndef GAMESTATEBUFFER_H
#define GAMESTATEBUFFER_H

#include <vector>
#include <cassert>
#include <cstddef>

template<typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(std::size_t size)
        : buffer_(size), head_(0), tail_(0), count_(0) {}

    ~CircularBuffer() {}

    void push(const T& value) {
        buffer_[head_] = value;
        head_ = (head_ + 1) % buffer_.size();
        if (count_ < buffer_.size()) {
            count_++;
        } else {
            tail_ = (tail_ + 1) % buffer_.size();
        }
    }

    T pop() {
        assert(!isEmpty());
        T value = buffer_[tail_];
        tail_ = (tail_ + 1) % buffer_.size();
        count_--;
        return value;
    }

    bool isEmpty() const {
        return count_ == 0;
    }

    bool isFull() const {
        return count_ == buffer_.size();
    }

    std::size_t size() const {
        return count_;
    }

private:
    std::vector<T> buffer_;
    std::size_t head_;
    std::size_t tail_;
    std::size_t count_;
};

#endif