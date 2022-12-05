#include<stdio.h>

typedef char byte;

//Program to see the binary of 8 bits values 

int main()
{
	byte	b = 0;
	int		offset = 257;

	for(int i=0;i<128;++i)
	{
		printf("%10d> ", b);	
		for(int i=7;i>=0;--i)
			printf("%d", b>>i & 0b00000001);

		b+=--offset;
		printf(" %10d> ", b);
		for(int i=7;i>=0;--i)
			printf("%d", b>>i & 0b00000001);
		b-=--offset;
		printf("\n");
	}
	printf("\n\n                -128> 10000000\n\n");
}
