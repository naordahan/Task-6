#include "stdafx.h"
#include "Board.h"

Board::Board(int  board_size)
{
	char **ch = (char **)malloc(board_size*sizeof(char));
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			*(*(ch + i) + j) = '.';
		}
	}
	
}





