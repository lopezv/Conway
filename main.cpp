#include "board.h"
#include "point.h"
#include "square.h"
#include <iostream>
#include "parser.h"

int main()
{
    vector<Point> v;
    v.push_back(Point(0,0));
    v.push_back(Point(0,1));
    v.push_back(Point(1,0));
    v.push_back(Point(3,2));
    v.push_back(Point(3,3));
    v.push_back(Point(2,3));

    //Board b = Board(4,4,v);

    Board b = parse("/home/lopezv/workspace/Conway/pulsar.txt");

        cout << b.getStringRep() << endl;
        b.updateState();
        cout << b.getStringRep() << endl;
        b.updateState();
        cout << b.getStringRep() << endl;
        b.updateState();
        cout << b.getStringRep() << endl;
        b.updateState();


    return 0;
}
