#include "Square.h"

Square::Square(int x, int y, bool hasItem = false): x_(x), y_(y), hasItem_(hasItem) {}

void Square::setItem() {
    hasItem_ = !hasItem_;
}