#include "square.h"
#include "point.h"
#include <vector>

Square::Square(Point p)
{
    myLoc = p;
    isAlive = false;
}

Square::Square(Point p, bool life)
{
    myLoc = p;
    isAlive = life;
}


char Square::getCharRep(){
    if(isAlive){
        return liveChar;
    } else{
        return deadChar;
    }
}

void Square::setLife(bool life){
    isAlive = life;
}

bool Square::isLiving(){
    return isAlive;
}

Point Square::getLocation(){
    return myLoc;
}


