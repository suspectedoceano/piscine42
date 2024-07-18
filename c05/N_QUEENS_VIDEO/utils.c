#include "naruto.h"

void	visual(uint8_t idx, uint8_t digits, char *v)
{
	p("\t");
	if (idx == digits){
		for (uint8_t i = 0; i < (digits / 2); ++i)
			p("\t");
		p("   [🥷"C"BASE_CASE"RST"🖨️]\n");
		return ;
	}
	for (uint8_t i = 0; i < digits; ++i){
		p("[%s%s%c%s] ", i == idx? "🥷" : "", 
						 i == idx? Y : "",
						 v[i],
						 i == idx? RST : "");
	}
	puts("");
}

char	**buildBoard(size_t n)
{
	char	**board;

	board = calloc(n, sizeof *board);
	assert(board);	
	for (uint8_t i = 0; i < n; ++i){
		board[i] = calloc(n, sizeof(**board));	
		assert(board[i]);
	}
	return board;
}


void	printBoard(char **board, size_t n)
{
	static uint32_t	possible_configurations = 0;

	++possible_configurations;
	p(C"\n🥷🖨️ BASE CASE 🖨️🥷\n"RST);
	p(G"Configuration->%"PRIu32 RST"\n", possible_configurations);
	for (uint8_t row = 0; row < n; ++row){
		for (uint8_t col = 0; col < n; ++col){
			p("%s", board[row][col] == 'Q'? Y"[👑]"RST  : "[  ]");
		}
		p("\n");
	}
	p("\n\n");
}

void	printBoardCurrent(char **board, uint8_t row, uint8_t col, size_t n)
{

	for (uint8_t r = 0; r < n; ++r){
		for (uint8_t c = 0; c <= n; ++c){
			if (c == n)
				p(C" Row->%"PRIu8"\n"RST, r);
			else if (row == r && col == c && board[r][c] != 'Q')
				p(R"[🥷❌]"RST);
			else if (row == r && col == c && board[r][c] == 'Q')
				p(G"[🥷👑]"RST);
			else
				p("%s", board[r][c] == 'Q'? Y"[ 👑 ]"RST  : "[    ]");

		}
	}
	p("\n\n");
}


bool	isSafeVisual(char **board, size_t n, uint8_t row, uint8_t col)
{
    // ↕︎ check vertical
    for (uint8_t r = 0; r < row; ++r)
        if (board[r][col] == 'Q'){
            p(Y"👑[%"PRIu32"][%"PRIu32"] "RST, row, col);
            p(R"💥↑[%"PRIu32"][%"PRIu32"]\n"RST, r, col);
			return false;
		}

    // ⤡ check left diagonal
	for (int8_t c = (int8_t)col, r = (int8_t)row; c >= 0 && r >= 0; --c, --r)
		if (board[r][c] == 'Q'){
            p(Y"👑[%"PRIu32"][%"PRIu32"] "RST, row, col);
            p(R"💥↖︎[%"PRIu32"][%"PRIu32"]\n"RST, r, c);
			return false;
		}

    // ⤢ check right diagonal
	for (int8_t c = (int8_t)col, r = (int8_t)row; c <= (int8_t)n && r >= 0; ++c, --r)
		if (board[r][c] == 'Q'){
            p(Y"👑[%"PRIu32"][%"PRIu32"] "RST, row, col);
            p(R"💥↗︎[%"PRIu32"][%"PRIu32"]\n"RST, r, c);
			return false;
		}

    p(G"👑 ✅ [%"PRIu32"][%"PRIu32"]\n"RST, row, col);
    return true;
}




void	printBoardClone(char **board, size_t n, uint8_t row, uint8_t col)
{

	p("\n🥷 "C"[%"PRIu32"][%"PRIu32"]\n"RST, row, col);
	for (uint8_t r = 0; r < n; ++r){
		for (uint8_t c = 0; c < n; ++c){
			p("%s", board[r][c] == 'Q'? Y"[👑]"RST  : "[  ]");
		}
		p("\n");
	}
	p("\n\n");
}



void	freeBoard(char **board, size_t n)
{
	for (uint8_t i = 0; i < n; ++i)
		free(board[i]);
	free(board);
}
