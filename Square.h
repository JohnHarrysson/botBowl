#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
    Square::Square(int x, int y, bool hasOwnPlayer = false);
    int getX() const { return x_; }
    int getY() const { return y_; }

    const bool getHasOwnPlayer() const {return hasOwnPlayer_;}
    void setHasOwnPlayer();


private:
    int x_, y_;
    bool hasOwnPlayer_;
};

#endif

