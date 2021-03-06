#include "board.h"
#include "square.h"
#include "fstream"
#include <iostream>

Board::Board(int width, int height)
{
    this->width = width;
    this->height = height;

    for(int i = 0; i < width; i ++){
        for(int j = 0; j < height; j++){
            board[i][j] = Square(Point(i,j));
        }
    }
}

Board::Board(int width, int height, vector<Point> livingPoints)
{
    this->width = width;
    this->height = height;

    for(int i = 0; i < width; i ++){
        for(int j = 0; j < height; j++){
            Point loc = Point(i,j);
            vector<Point>::iterator it = find (livingPoints.begin(), livingPoints.end(), loc);

            if (it != livingPoints.end())  {
                board[i][j] = Square(Point(i,j), true);
            } else{
                board[i][j] = Square(Point(i,j));
            }
        }
    }
}

Point Board::getPointInBoard(Point P){
    int x = P.getX(), y = P.getY();

    if (x < 0){
        x = width-1;
    } else if( x >= width){
        x = 0;
    }
    if (y < 0){
        y = height-1;
    } else if( y >= height){
        y = 0;
    }
    return Point(x,y);
}

Square Board::getSquareAtPoint(Point p){
    return board[p.getX()][p.getY()];
}

bool Board::isOnBoard(Point p){
    return  0 <= p.getX() && p.getX() < width && 0 <= p.getY() && p.getY() < height;
}

void Board::toggleLife(int x, int y){
    board[x][y].setLife(!board[x][y].isLiving());
}

int Board::getNumNeighbors(int x, int y){
    Square s = board[x][y];
    vector<Point> surr = s.getLocation().getAdjacentPoints();
    int numNeighbors = 0;

    for(std::vector<Point>::size_type i = 0; i != 8; i++) {
        Point p = surr[i];
        if (isOnBoard(p) && getSquareAtPoint(p).isLiving()){
            numNeighbors++;
        }
    }
    return numNeighbors;
}

void Board::updateState(){

    vector<Point> pointsToToggle;

    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){

            Square s = board[i][j];
            vector<Point> surr = s.getLocation().getAdjacentPoints();
            int numNeighbors = 0;

            for(std::vector<Point>::size_type i = 0; i != 8; i++) {
                Point p = surr[i];
                if(!isOnBoard(p)){
                    p = this->getPointInBoard(p);
                }
                if (getSquareAtPoint(p).isLiving()){
                    numNeighbors++;
                }
            }

            if(!s.isLiving()){
                if(numNeighbors == 3){
                    pointsToToggle.push_back(Point(i,j));
                }
            } else{
                if(numNeighbors < 2 || numNeighbors > 3){
                    pointsToToggle.push_back(Point(i,j));
                }
            }
        }
    }
    for(std::vector<Point>::size_type i = 0; i < pointsToToggle.size(); i++) {
        Point p = pointsToToggle[i];
        this->toggleLife(p.getX(), p.getY());
    }

}

string Board::getStringRep(){
    string str = "";

    for(int j = 0; j < height; j++){
        for(int i = 0; i < width; i ++){

            Square s = board[i][j];
            str += s.getCharRep();
        }
        str += '\n';
    }
    return str;
}

void Board::saveToFile(string fileName){
    ofstream myfile;
    myfile.open (fileName.c_str(),	ios::out);
    if (myfile.is_open()){
        myfile << width << " " << height << endl;
        for(int j = 0; j < height; j++){
            for(int i = 0; i < width; i ++){

                Square s = board[i][j];
             if(s.isLiving()){
                    myfile << i << " " << j << endl;
                }
            }
        }
        myfile.flush();
    }
    myfile.close();
}

