#ifndef ERRORS_H
#define ERRORS_H

#include <stdexcept>
#include <string>

class PlayerException : std::runtime_error {
    public:
         PlayerException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif