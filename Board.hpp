#pragma once
#include <iostream>
#include <string>
#include "Coordinate.hpp"


using namespace std;

class Board {
	int size;
	char  **board;
public:
	Board();
	Board(int board_size);
	Board& operator=(char c);
	Board(const Board &Board);
	Board& operator[](Coordinate cor);
	Board& operator= (Board &Board1);
	friend ostream& operator<< ( ostream& os, Board &Board);

};



