#include <stdio.h>

typedef unsigned char byte;

int main()
{
	char	c;
	char	*pc;

	c = 'd';
	pc = &c;
	byte *b0 = &pc;
	printf("This is the address of the c %p\n", &c);
	
	for (int i=7; i>=0; --i)
	{
		for (int k=7; k>=0; --k)
			printf("%d", (*(b0+i) >> k) & 1);
		printf("\n");	
	}


}

