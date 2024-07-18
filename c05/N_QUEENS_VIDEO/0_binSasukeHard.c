#include "naruto.h"

#define N		32

void	binSasukeBad(char *v)
{
	while (v[0] <= '1')
	{
		while (v[1] <= '1')
		{
			while (v[2] <= '1')
      		{
				while (v[3] <= '1')
        		{
					p("%s\n", v);
          			v[3]++;
				}
				v[3] = '0', v[2]++;
			}
			v[2] = '0', v[1]++;
		}
		v[1] = '0', v[0]++;
	}
}

/*
 * CALLOC
 * + 1 for the '\0' sentinel value
 * e.g.->  [__________\0];
*/
void	binSasuke(uint8_t digits)
{
	char	*v;
	
	v = calloc(digits + 1, sizeof *v);
	if (NULL == v){
		perror("Calloc failed");
		return ;
	}

    for (uint8_t i = 0; i < digits; ++i){
        v[i] = '0';
	}

	binSasukeBad(v);
	free(v);
}

int main()
{
	binSasuke(N);
}
