#include<stdio.h>

typedef int bytes_4;

//Program to see all the bin repsentation 💡💡💡💡

int main()
{
	bytes_4				b = 0;
	long				offset = 4294967297;

	for(int i=0;i<2147483647;++i)
	{
		printf("%10d> ", b);	
		for(int i=31;i>=0;--i)
			printf("%d", b>>i & 1);

		b+=--offset;
		printf("%10d> ", b);
		
		for(int i=31;i>=0;--i)
			printf("%d", b>>i & 1);
		b-=--offset;
		printf("\n");
	}
}
