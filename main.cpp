#include "board.h"
#include "point.h"
#include "square.h"
#include <iostream>

int main()
{

    int width, height;

//    cin >> width >> height;

    vector<Point> v;
    v.push_back(Point(0,0));
    v.push_back(Point(0,1));
    v.push_back(Point(1,0));
    v.push_back(Point(3,2));
    v.push_back(Point(3,3));
    v.push_back(Point(2,3));

    Board b = Board(4,4,v);

        cout << b.getStringRep() << endl;
        b.updateState();
        cout << b.getStringRep() << endl;
        b.updateState();
        cout << b.getStringRep() << endl;
        b.updateState();
        cout << b.getStringRep() << endl;

    return 0;
}
