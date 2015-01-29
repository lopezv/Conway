#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "board.h"
#include "point.h"
using namespace std;

Board parse(string filename){

    string line;

    ifstream myfile (filename.c_str(),ifstream::in);
    int width, height;
    vector<Point> v;

    if (myfile.is_open())
    {

        string token;
        size_t pos;

        getline (myfile,line);
        pos = line.find(' ');
        token = line.substr(0, pos);

        width = atoi(token.c_str());
        line.erase(0, pos + 1);
        pos = line.find(' ');
        token = line.substr(0, pos);

        height = atoi(token.c_str());


      while ( getline (myfile,line) )
      {
          int x,y;
          pos = line.find(' ');
          token = line.substr(0, pos);
          x = atoi(token.c_str());

          line.erase(0, pos + 1);
          pos = line.find(' ');
          token = line.substr(0, pos);
          y = atoi(token.c_str());
          v.push_back(Point(x,y));
      }
      myfile.close();
    }
    cout << width<< " "<< height << endl;
    return Board(width,height,v);
}

#endif // PARSER_H
