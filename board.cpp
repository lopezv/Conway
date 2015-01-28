#include "board.h"
#include "square.h"
#include <iostream>

Board::Board(int width, int height)
{
    this->width = width;
    this->height = height;

    Square* b[width];
    board = b;
    for(int i = 0; i < width; i ++){
        Square row[height];
        for(int j = 0; j < height; j++){
            row[j] = Square(Point(i,j));
        }
        b[i] = row;
    }
}

Board::Board(int width, int height, vector<Point> livingPoints)
{
    this->width = width;
    this->height = height;


    Square* b[width];
    board = b;
    for(int i = 0; i < width; i ++){
        Square row[height];
        for(int j = 0; j < height; j++){
            Point loc = Point(i,j);
            vector<Point>::iterator it = find (livingPoints.begin(), livingPoints.end(), loc);
            if (it != livingPoints.end())  {
                row[j] = Square(Point(i,j), true);
            } else{
                row[j] = Square(Point(i,j));
            }
        }
        b[i] = row;
    }
}

Square Board::getSquareAtPoint(Point p){
    return board[p.getX()][p.getY()];
}

void Board::updateState(){
    for(int i = 0; i < width; i ++){
        for(int j = 0; j < height; j++){
            Point here = Point(i,j);
            Square s = this->getSquareAtPoint(here);
            vector<Point> surr = s.getLocation().getAdjacentPoints();
            int numNeighbors = 0;
            for(std::vector<Point>::size_type i = 0; i != surr.size(); i++) {
                Point p = surr[i];
                if (getSquareAtPoint(p).isLiving()){
                    numNeighbors++;
                }
            }
            if(!s.isLiving()){
                if(numNeighbors == 3){
                    s.setLife(true);
                }
            } else{
                if(numNeighbors < 2 || numNeighbors > 3){
                    s.setLife(false);
                }
            }
        }
    }

}

string Board::getStringRep(){
    string str = "";

    for(int j = 0; j < height; j++){
        for(int i = 0; i < width; i ++){

            cout << "printing " << str << width << height << endl;

            str += board[i][j].getCharRep();
        }
        str += '\n';
    }
    return str;
}
