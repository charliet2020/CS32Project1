#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
	//: m_rows(nRows), m_cols(nCols)
{
	m_rows = nRows;
	m_cols = nCols;
	//Spec says assume parameters are valid 

	for (int i = 0; i < nRows; i++)
		for (int j = 0; j < nCols; j++)
			m_grid[i][j] = 0;

	//assume 0 zombies died at any given position
}

bool History::record(int r, int c)
{
	if (r < 1 || c < 1 || r > m_rows || c > m_cols) //within bounds, but bounds may not necessarily be at max.
		return false;

	//Array starts at 0, but Arena starts at 1, so must subtract index
	m_grid[r-1][c-1]++; //0 to 1 means 1 zombie died at that position

	return true;
}

void History::display() const
{
	// Position (row,col) of the arena coordinate system is represented in
	// the array element grid[row-1][col-1]
	
	int r, c;
	char ch;
	int temp;

	// Draw the grid
	clearScreen();
	for (r = 0; r < m_rows; r++)
	{
		for (c = 0; c < m_cols; c++)
		{
			ch = '.';
			temp = m_grid[r][c];
			if (temp >= 26)
				ch = 'Z';
			else if (temp == 25)
				ch = 'Y';
			else if (temp == 24)
				ch = 'X';
			else if (temp == 23)
				ch = 'W';
			else if (temp == 22)
				ch = 'V';
			else if (temp == 21)
				ch = 'U';
			else if (temp == 20)
				ch = 'T';
			else if (temp == 19)
				ch = 'S';
			else if (temp == 18)
				ch = 'R';
			else if (temp == 17)
				ch = 'Q';
			else if (temp == 16)
				ch = 'P';
			else if (temp == 15)
				ch = 'O';
			else if (temp == 14)
				ch = 'N';
			else if (temp == 13)
				ch = 'M';
			else if (temp == 12)
				ch = 'L';
			else if (temp == 11)
				ch = 'K';
			else if (temp == 10)
				ch = 'J';
			else if (temp == 9)
				ch = 'I';
			else if (temp == 8)
				ch = 'H';
			else if (temp == 7)
				ch = 'G';
			else if (temp == 6)
				ch = 'F';
			else if (temp == 5)
				ch = 'E';
			else if (temp == 4)
				ch = 'D';
			else if (temp == 3)
				ch = 'C';
			else if (temp == 2)
				ch = 'B';
			else if (temp == 1)
				ch = 'A';
			cout << ch;
		}
		cout << endl;
	}
	cout << endl;
}


