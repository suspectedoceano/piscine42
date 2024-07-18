#include "naruto.h"

#define BASE	16
#define DIGITS	2

void	narutoHelper(uint8_t idx, uint8_t digits, char *v, uint8_t base)
{

	if (idx == digits){
		visual(idx, digits, v);
		p(G"\t\t\t%s\n\n"RST, v);
	}

	/* 🥷🥷🥷  RECURSION 🥷🥷🥷
	 *
	 * Here I speak to the NARUTO before the BASE CASE NARUTO  
	 *
	 * 	❌🥷🥷🥷🥷🥷🥷❌		✅ 🥷 -> 🖨️ ✅
	*/
	else{
		/*
		v[idx] = '0';
		narutoHelper(idx + 1, digits, v, base);
		v[idx] = '1';
		narutoHelper(idx + 1, digits, v, base);
		v[idx] = '3';
		narutoHelper(idx + 1, digits, v, base);
		*/
	//	😓😅 This is SILLY...Let's LOOP! 🔁 🍭

		for (uint8_t i = 0; i < base; ++i){
			v[idx] = SYMBOLS[i];
			visual(idx, digits, v);
			narutoHelper(idx + 1 , digits, v, base);
		}
	}
}

void	narutoBase(uint8_t digits, uint8_t base)
{
	char	*v;

	v = calloc(digits + 1, sizeof *v);
	if (NULL == v){
		perror("Calloc failed");
		return ;
	}
	narutoHelper(0, digits, v, base);
	free(v);
}

int main()
{
	narutoBase(DIGITS, BASE);
}
