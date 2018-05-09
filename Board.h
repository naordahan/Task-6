#pragma once
#include <iostream>
#include <exception>
#include <list>
#include "Node.h"
using namespace std;

class Board
{
    public:
    int size;
    Node ** game;
    Node **board;
    Board(int s);
    Board(const Board& o);
    ~Board();
    bool operator==(const Board& o) const;
    Node& operator[](list<int> list);
    Board& operator=(const Board& b);
    Board& operator=(char c);
    friend ostream &operator<<(ostream &o, const Board &b);
};

//exceptions
class IllegalCoordinateException : public exception
{
    int x,y;
    public: 
        void setX(int row){
            this->x=row;
            }
        void setY(int col){
            this->y=col;
            }
        string theCoordinate ()const
        {
            return to_string(x)+","+to_string(y);
        }
};

class IllegalCharException : public exception
{
    char in;
    
    public:
        char theChar()const
        {
            return in;
        }
        void setInput(int n){
            in=n;
        }
};
