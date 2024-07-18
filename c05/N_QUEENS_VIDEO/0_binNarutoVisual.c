#include "naruto.h"

#define N		4

void	biNarutoHelper(uint8_t idx, uint8_t digits, char *v)
{

	// 🖨️  BASE CASE NARUTO 🖨️
	if (idx == digits){
		visual(idx, digits, v);	
		p(G"\t\t\t%s\n\n\n"RST, v);
	}


	/* 🥷🥷🥷  RECURSION 🥷🥷🥷
	 *
	 * Here I speak to the NARUTO before the BASE CASE NARUTO  
	 *
	 * 	❌🥷🥷🥷🥷🥷🥷❌		✅ 🥷 ->  🖨️ ✅
	*/
	else{
		v[idx] = '0';	
		visual(idx, digits, v);	
		biNarutoHelper(idx + 1, digits, v);

		v[idx] = '1';	
		visual(idx, digits, v);	
		biNarutoHelper(idx + 1, digits, v);
	}
}

/*
 * CALLOC
 * + 1 for the '\0' sentinel value
 * e.g.->  [__________\0];
*/
void	biNaruto(uint8_t digits)
{
	char	*v;
	
	v = calloc(digits + 1, sizeof *v);
	if (NULL == v){
		perror("Calloc failed");
		return ;
	}
	biNarutoHelper(0, digits, v);
	free(v);
}

int main()
{
	biNaruto(N);
}
