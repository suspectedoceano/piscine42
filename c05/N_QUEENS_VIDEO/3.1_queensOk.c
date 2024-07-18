#include "naruto.h"


#define	N	4

uint32_t	possible_configurations = 0;


bool	isSafe(char **board, size_t n, uint8_t row, uint8_t col)
{
    // ↕︎ check vertical
    for (uint8_t r = 0; r < row; ++r)
        if (board[r][col] == 'Q'){
			return false;
		}
    
	// ⤡ check left diagonal
	for (int8_t c = (int8_t)col, r = (int8_t)row; c >= 0 && r >= 0; --c, --r){
		if (board[r][c] == 'Q'){
			return false;
		}
	}

    // ⤢ check right diagonal
	for (int8_t c = (int8_t)col, r = (int8_t)row; c <= (int8_t)n && r >= 0; ++c, --r)
		if (board[r][c] == 'Q'){
			return false;
		}

    return true;
}


void	narutoQueensHelper(char **board, uint8_t row, size_t n)
{

	// 🖨️ BASE CASE 🖨️
	if (row == n)
	{
		printBoard(board, n);
		++possible_configurations;
	}
	else
	{
		for (uint8_t col = 0; col < n; ++col)
		{

			if (isSafeVisual(board, n, row, col))
			{
				// Place queen [👑]
				board[row][col] = 'Q';	
				printBoardCurrent(board, row, col, n);

				// 🖨️  call BASE 🖨️
				narutoQueensHelper(board, row + 1, n);

				// Remove queen [X]
				board[row][col] = 0;
				printBoardCurrent(board, row, col, n);

			}	
		}
	}
}



void	narutoQueens(size_t n)
{
	char	**board;

	board = buildBoard(n);

	narutoQueensHelper(board, 0, n);

	p("\nTOTAL solutions for "C"N%"PRIuPTR"=%"PRIu32 RST"\n",
			n, 
			possible_configurations);
	
	// 🧊 Refresh global 🧊
	possible_configurations = 0;

	freeBoard(board, n);
}



int main(void)
{

	narutoQueens(N);

}
