#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include "point.h"

class Square
{
private:
    Point myLoc;
    static const char liveChar = '*';
    static const char deadChar = ' ';
    bool isAlive;
public:
    Square() {}
    Square(Point p);
    Square(Point p, bool life);

    char getCharRep();
    void setLife(bool life);
    bool isLiving();
    Point getLocation();
};

#endif // SQUARE_H
