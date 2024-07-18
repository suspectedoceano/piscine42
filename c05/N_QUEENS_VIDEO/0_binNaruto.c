#include "naruto.h"

#define N		32

void	biNarutoHelper(uint8_t idx, uint8_t digits, char *v)
{

  //🥷🖨️ BASE CASE 🖨️🥷
	if (idx == digits)
	{
		p("%s\n", v);
	}

  //🥷 RECURSION 🥷
	else
	{
		v[idx] = '0';
		biNarutoHelper(idx + 1, digits, v);

		v[idx] = '1';
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
