#ifndef NARUTO_H
# define NARUTO_H

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

//Useful for BASE 16 
#define SYMBOLS	"0123456789abcdef"

#define p(...)	printf(__VA_ARGS__)

// Define ANSI color codes with bold formatting
#define RST		"\033[0m"
#define Y		"\033[1;33m"
#define C		"\033[1;36m"
#define G		"\033[1;32m"
#define R       "\033[1;31m"


void	visual(uint8_t idx, uint8_t digits, char *v);
char    **buildBoard(size_t n);
void    printBoard(char **board, size_t n);
void    printBoardCurrent(char **board, uint8_t row, uint8_t col, size_t n); 
void    freeBoard(char **board, size_t n);
bool    isSafeVisual(char **board, size_t n, uint8_t row, uint8_t col);

#endif
