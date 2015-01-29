#include "point.h"
#include <vector>

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::getX(){
    return this->x;
}

int Point::getY(){
    return this->y;
}

bool Point::operator ==(Point other){
    return this->getX() == other.getX() && this->getY() == other.getY();
}

vector<Point> Point::getAdjacentPoints(){
    vector<Point> v;

    for(int i = -1; i <2; i++){
        for(int j = -1; j <2; j++){
            if(i != 0 || j != 0){
                v.push_back(Point(x+i,y+j));
            }
        }
    }
    return v;
}
