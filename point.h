#ifndef POINT_H
#define POINT_H
#include <vector>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y);
    Point() {x=0; y =0;}

    int getX();
    int getY();
    bool operator==(Point other);
    vector<Point> getAdjacentPoints();
};

#endif // POINT_H
