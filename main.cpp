#include "board.h"
#include "point.h"
#include <iostream>

int main()
{
    vector<Point> v;
    v.push_back(Point(0,0));
    v.push_back(Point(0,1));
    v.push_back(Point(1,0));
    v.push_back(Point(3,1));
    v.push_back(Point(3,2));
    v.push_back(Point(2,2));



    Board b = Board(4,4, v);

    cout << "HI" << endl;
    cout << b.getStringRep() << endl;


    return 0;
}
