#include<stdio.h>



//Convert n in a base

#define base 16

int main()
{	
	int		n;

	n = 55269;
	while (n)
	{
		printf("\n\n\n%d mod %d =\t %d \n", n, base, n % base);
		printf("%d div %d = %d\n", n, base, (n / base));

		//👀
		n /= base;
	}	
	puts("\n\n\n");

}
