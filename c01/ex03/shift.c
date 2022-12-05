#include<stdio.h>
#include <stdlib.h>

//THE SHIFT << operator is cool

int main()
{
	short 	n;
	short	*p;

	
	p = &n;	
	n = 100;
	printf("----\n%d\n", n);
	printf("0b");
	for (int i=7; i>=0; --i)printf("%d", *p >> i & 1); printf("\n----\n\n");
	
	for (int i=0; i<8; ++i)
	{
		n >>= i;
		printf("%3d >> %d = %5d ->",100, i, n);
		for (int i=7; i>=0; --i)printf("%d", *p >> i & 1);
		printf("\n\n");
		n = 100;	
	}

	printf("\n----------------\nThe OPPOSITE also true\n----------------\n");

	for (int i=0; i<8; ++i)
	{	
		n <<= i;
		printf("%3d << %d = %5d ->",100, i, n);
		for (int i=15; i>=0; --i)
			printf("%d", *p >> i & 1);

		printf("\n\n");
		n = 100;
	}
}	
