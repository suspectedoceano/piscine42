#include <stdio.h>

typedef unsigned char byte;

int main()
{
	char	c;
	char	*pc;

	c = 'd';
	pc = &c;
	byte *b0 = &pc;
	printf("\nThis is the address of the variable c %p\n", &c);
	
	printf("\nLITTLE ENDIAN\n\n");
	for (int i=0; i<8; ++i)
	{
		printf("Byte %d-> ",i);
		for (int k=7; k>=0; --k)
			printf("%d", (*(b0+i) >> k) & 1);
		printf("\n");	
	}
	printf("\nBIG ENDIAN\n\n");
	for (int i=7; i>=0; --i)
	{
		printf("Byte %d-> ",i);
		for (int k=7; k>=0; --k)
			printf("%d", (*(b0+i) >> k) & 1);
		printf("\n");	
	}



}

