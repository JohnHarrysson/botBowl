#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <ctime>

int getRandomIndex(int min, int max) {
    static std::mt19937 rng(std::time(nullptr));
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

#endif