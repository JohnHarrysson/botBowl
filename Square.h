#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
    Square::Square(int x, int y, bool hasItem = false);
    int getX() const { return x_; }
    int getY() const { return y_; }

    bool hasItem() const {return hasItem_;}
    void setItem();


private:
    int x_, y_;
    bool hasItem_;
};

#endif

