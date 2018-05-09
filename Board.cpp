#include "Board.h"

Board::Board(int s)
{
    this->size=s;
   game = new Node*[size];
    for (int i = 0; i < size; i++) {
		this->board[i] = new Node [size];
	}
	
	//initializing the empty board
    for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			board[i][j]= Node{'.'};
		}
	}
}

//copy constructor
Board::Board(const Board& o)
{
    this->size=o.size;
    this->board = new Node*[size];
    for (int i = 0; i < size; i++) {
		this->board[i] = new Node [size];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            board[i][j]=o.board[i][j];
        }
    }
}

Board::~Board()
{
    for(int i=0;i<size;i++){
        delete[] board[i];
    }
    delete[] board;
}

//operator[]
Node& Board::operator[](list<int> list)
{
    int x = list.front();
    int y= list.back();
    if(x<0 || x>=size|| x<0 || x>=size)
    {
        IllegalCoordinateException e;
        e.setX(x); e.setY(y);
        throw e;
    }   
    return board[x][y];
}

//operator =
Board& Board::operator=(const Board &b)
{
     if (this==&b)
        return *this;
    if (b.size!=this->size) {
        for (int i = 0; i < size; i++){
	    delete[] board[i];
        }
        delete [] board;

        size = b.size;
        board = new Node*[b.board]; 
        for (int i = 0; i < size; i++) {
		board[i] = new Node [size];
	    }
    }
            
    for (int i=0; i<size; ++i){
        for(int j=0;j<size;j++){
            board[i][j]=Node{b.board[i][j].getNode()};
        }
    }
    return *this;
}

//operator =
Board& Board::operator=(char c)
{
    if (c=='.') {
        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < size; ++i) {
                board[i][j] = '.';
            }
        }
    }
    else
    {
       IllegalCharException e;
        e.setInput(c);
        throw e; 
    }
    return *this;
}


//operator ==
bool Board::operator==(const Board &o) const
{
    if (rows != o.size)
        return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] != o.board[i][j])
                return false;
        }
    }
    return true;
}

ostream &operator<<(ostream& o, const Board& b)
{
    for (int i = 0; i < b.size; i++)
    {
        for (int j = 0; j < b.size; j++){
            out << b.board[i][j].getNode();
        }
        o << endl;
    }
    return o;
}
