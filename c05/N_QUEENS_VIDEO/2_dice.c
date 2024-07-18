#include "naruto.h"


#define DICES	2

void	diceHelper(uint32_t idx, uint8_t dices, uint8_t *v)
{
  static uint32_t n_combination = 0;

	//BASE CASE
	if (idx == dices){
		for (uint8_t i = 0; i < dices; ++i)
			p("[🎲 %c]", v[i]);
		p(G"->%u\n"RST, ++n_combination);
		puts("\n");
	}
	//RECURSION + LOOP
	else{
		for (uint8_t i = 1; i <= 6; ++i){
			v[idx] = '0' + i;
			diceHelper(idx + 1, dices, v);
		}	
	}
}

void	dice(uint8_t dices)
{
	uint8_t	*v;

	v = calloc(dices + 1, sizeof *v); 
	if (NULL == v){
		perror("Calloc failed");
		return ;
	}

	diceHelper(0, dices, v);
	free(v);
}



int main(void)
{
	dice(DICES);
}

