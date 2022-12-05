#include <stdio.h>

// Look first hand the overflow 👀

int main()
{
	int		n = 2147483647;

	printf("%d> ",n);
	for (int i=32;i>0;--i)
	{
		if (!(i%8) && i != 32)printf("_");
		printf("%d", n>>(i-1) & 1);
	}
	printf("\n");
	n += 1;
	printf("\n2147483647 + 1\n\n");
	printf("%d> ",n);
	for (int i=32;i>0;--i)
	{
		if (!(i%8) && i != 32)printf("_");
		printf("%d", n>>(i-1) & 1);
	}
	printf("\n");

	
}

