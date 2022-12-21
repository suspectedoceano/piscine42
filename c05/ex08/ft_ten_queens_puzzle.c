#include <stdio.h>

/*
 * Not a perfect code, bad BIG O
 * till 8x8 kinda fast
 * need to improve
 * 🚨Not a copy paste code, format is different🚨
 * this i for me to get WTF i'm doin
 *
 *        		 ↖︎ ↑ ↗︎
 *			   ←   👑  →
 *				 ↙︎ ↓ ↘︎
*/


#define ROW 8
#define COl 8

int possibleCombinations = 0;


int 	oblique(char board[][COl], int queen_row, int queen_col)
{
	
/*	  				0 1 2 3 4 5 6 7
		 * row 0-> |↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|
		 * row 1-> |↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|
		 * row 2-> |↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|
		 * row 3-> |↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|
		 * row 4-> |↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|
		 * row 5-> |↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|
		 * row 6-> |↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|
		 * row 7-> |↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|↖︎|
		 * row 8-> 
		// ↖︎ Diagonal lines rows + (cols - 1)
		
		// ALL THE DIAGONALS IN THE 8x8 GRID
		// row 7 col 0 ↖︎
		// row 7 col 1, row 6 col 0
		// row 7 col 2, row 6 col 1, row 5 col 0
		// row 7 col 3, row 6 col 2, row 5 col 1, row 4 col 0
		// row 7 col 4, row 6 col 3, row 5 col 2, row 4 col 1, row 3 col 0
		// row 7 col 5, row 6 col 4, row 5 col 3, row 4 col 2, row 3 col 1, row 2 col 0
		// row 7 col 6, row 6 col 5, row 5 col 4, row 4 col 3, row 3 col 2, row 2 col 1, row 1 col 0
		// row 7 col 7, row 6 col 6, row 5 col 5, row 4 col 4, row 3 col 3, row 2 col 2, row 1 col 1, row 0 col 0
		//				Starting at col 6
		// row 6 col 7, row 5 col 6, row 4 col 5, row 3 col 4, row 2 col 3, row 1 col 2, row 0 col 1
		// row 5 col 7, row 4 col 6, row 3 col 5, row 2 col 4, row 1 col 3, row 0 col 2
		// row 4 col 7, row 3 col 6, row 2 col 5, row 1 col 4, row 0 col 3
		// row 3 col 7, row 2 col 6, row 1 col 5, row 0 col 4
		// row 2 col 7, row 1 col 6, row 0 col 5
		// row 1 col 7, row 0 col 6
		// row 0 col 7
		//
*/
		//delta_row = the difference in rows between the two queens, and delta_col = the difference in columns. 
		//The two queens will be on the same diagonal if:
		// -> delta_row == delta_col or delta_row == -delta_col.
		// "For every row you move, you go 1 column rigth or left (+1 col or -1 col)"
		// 
		// 	  Col
		// _0_1_2_3_
		// |_|_|_|_| < 0 row
		// |_|&|_|_| < 1 row
		// |_|_|_|_| < 2 row
		// |_|_|_|_| < 3 row
		//	  out 	< 4 row
		

		int 	delta_row, delta_col;

		for (int i = 0; i < ROW; i++)
		{
			if (i == queen_row)
					continue;
			delta_row = delta_col = 0;

			for (int j = 0; j < COl; j++)
			{
				if (board[i][j] == '&')
				{
					//Diagonal queen 
					delta_row = queen_row - i;
					delta_col = queen_col - j;
					if (delta_row == delta_col || delta_row == -delta_col)
						return 1;
				}

			}

		}

		return 0;	
}







int 	queenLegit(char board[][COl])
{

	/*				. . .col →
   	 *				. . . ↓ 
	 * 				0 1 2 3 4 5 6 7
		 * row 0-> | | | |↑| | | | |..
		 * row 1-> | | | |↑| | | | |..
		 * row 2-> | | | |↑| | | | |..
		 * row 3-> | | | |↑| | | | |..
		 * row 4-> | | | |&| | | | |.←row
		 * row 5-> | | | |↓| | | | |  ↓
		 * row 6-> | | | |↓| | | | |
		 * row 7-> | | | |↓| | | | |
	*/

	//CHECK ~1
	//Are 👑 in the same colon?
	int queens;
	
	for (int col = 0; col < COl; ++col)
	{
		//Refresh at every cycle
		queens = 0;
		for (int row = 0; row < ROW; ++row)
		{
			if (board[row][col] == '&')
			   ++queens;
			if (queens > 1)	
				return 0;
		}
	}
	
	/*
	 * 				0 1 2 3 4 5 6 7
		 * row 0-> | | | | | | | | |
		 * row 1-> | | | | | | | | |
		 * row 2-> | | | | | | | | |
		 * row 3-> | | | | | | | | |
		 * row 4-> |←|←|←|&|→|→|→|→|
		 * row 5-> | | | | | | | | |
		 * row 6-> | | | | | | | | |
		 * row 7-> | | | | | | | | |
	*/

	//CHECK ~2
	//Are 👑 in the same row?
	for(int row = 0; row < ROW; ++row)
	{
		queens = 0;
		for (int col = 0; col < COl; ++col)
		{
			if (board[row][col] == '$')
				++queens;
			if (queens > 1)
				return 0;
		}
	}

	/*
	 * 				0 1 2 3 4 5 6 7
		 * row 0-> | | | | | | | |↗︎|
		 * row 1-> |↖︎| | | | | |↗︎| |
		 * row 2-> | |↖︎| | | |↗︎| | |
		 * row 3-> | | |↖︎| |↗︎| | | |
		 * row 4-> | | | |&| | | | |
		 * row 5-> | | |↙︎| |↘︎| | | |
		 * row 6-> | |↙︎| | | |↘︎| | |
		 * row 7-> |↙︎| | | | | |↘︎| |
	*/


	//In every row i have a queen
	
	int 	queen_row, queen_col;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COl; j++)
		{
			if (board[i][j] == '&')
			{
				queen_row = i;
				queen_col = j;
				if (oblique(board, queen_row, queen_col))//TODO
					return 0;
			}
	
		}


	}


	//ALL CHECKS PASSED
	return 1;


}

								//   0        0
void	helper(char board[][COl], int row, int col)
{


	// BASE CASE when we filled the board.
	//BASE CASE PRINTS THE BOARD
		// out the board
		// e.g 4x4 board
		//  ______
		// |      | < 0 row
		// |	  | < 1 row
		// |	  | < 2 row
		// |______| < 3 row
		//	 out 	< 4 row
	if (row == ROW)
	{
	       //queens cannot reach one each other
		if (queenLegit(board))
		{
			row = 0;
			while (row < ROW)
			{
				while (col < COl)
				{
					if (board[row][col] == '&')
						printf("| $ ");
					else
						printf("|   ");
					++col;
				}
				//Close the row
				printf("|\n");
				//Start next iteration from cell 0
				col = 0;
				//Next row
				++row;
			}
			//Pad to read better
			printf("\n\n\n\n\n");
			possibleCombinations++;
		}
	}

	//RECURSIVE CASE IS THE BOARD_FILLER
	else
	{
					   // col
		/*			0 1 2 3 4 5 6 7
		 * row 0-> | | | | | | | | |
		 * row 1-> | | | | | | | | |
		 * row 2-> | | | | | | | | |
		 * row 3-> | | | | | | | | |
		 * row 4-> | | | | | | | | |
		 * row 5-> | | | | | | | | |
		 * row 6-> | | | | | | | | |
		 * row 7-> | | | | | | | | |
		 *
		 * Every recursive call get a different row
		 * BASE CASE is when row is out the board
		 * in this case row 8.
		*/

		for (int i = 0; i < COl; ++i)
		{
			//Put a 👑 in the first cell
			//of the row of pertinence
			//CHOOSE step.

			board[row][col + i] = '&';			

			/*			0  1 2 3 4 5 6 7
			 * row 7-> |👑| | | | | | | |
			 * row 7-> | |👑| | | | | | |
			 *				. . . .
			 * row 7-> | | | | | | | |👑|
			 * 
			 * This recursion tries to put
			 * the 👑 in all col of its
			 * pertinence row (i.e. row 7)
			*/
		
			//Print the board
			helper(board, row + 1, col);
			

			//Remove the queen
			//UN-CHOOSE, BACKTRACKING
			board[row][col + i] = 0;
		}

	}
	
}


int 	ft_ten_queens_puzzle(void)
{
	char	board[ROW][COl];

	int		row, col;

	row = col = 0;
	//Start at row col 0 in board.
	helper(board, row, col);
	
	return possibleCombinations;


}


int main()
{
	
	printf("\t\tThis are the possible combinations->%d\n", ft_ten_queens_puzzle());
}
