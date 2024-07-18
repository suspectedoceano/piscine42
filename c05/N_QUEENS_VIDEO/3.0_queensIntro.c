#include "naruto.h"


#define	N	5


void	narutoQueensHelper(char **board, uint8_t row, size_t n)
{

	// 🖨️ BASE CASE 🖨️
	if (row == n)
	{
		printBoard(board, n);
	}
	else
	{
		for (uint8_t col = 0; col < n; ++col)
		{

			// Place queen [👑 ]
			board[row][col] = 'Q';
			printBoardCurrent(board, row, col, n);


			// 🖨️  call BASE 🖨️
			narutoQueensHelper(board, row + 1, n);


			// Remove queen [ X ]
			board[row][col] = 0;
			printBoardCurrent(board, row, col, n);

		}
	}
}



void	narutoQueens(size_t n)
{
	char	**board;

	board = buildBoard(n);

	narutoQueensHelper(board, 0, n);

	freeBoard(board, n);
}



int main(void)
{

	narutoQueens(N);

}
