#include "Square.h"

Square::Square(int x, int y, bool hasOwnPlayer): x_(x), y_(y), hasOwnPlayer_(hasOwnPlayer) {}

void Square::setHasOwnPlayer() {
    hasOwnPlayer_ = !hasOwnPlayer_;
}