#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <algorithm>
#include "point.h"
#include "square.h"
#include <string>

class Board
{
private:
    int width;
    int height;
    Square** board; // board[x][y] = square at (x,y)

public:
    Board(int width, int height);
    Board(int width, int height, vector<Point> livingPoints);

    Square getSquareAtPoint(Point p);
    void updateState();
    string getStringRep();

};

#endif // BOARD_H
