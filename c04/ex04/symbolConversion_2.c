#include<stdio.h>



//Convert n in a base

char 	baseSymbols[] = "0123456789abcdef";

#define baseValue 16


int main()
{	
	int		n;

	n = 55269;
	while (n)
	{
		printf("\n\n\n"
			   "%d mod %d =\t %c -> %d"	      //👀💡👀
			   "\n", n, baseValue, baseSymbols[n % baseValue], n%baseValue);

		printf("%d div %d = %d\n", n, baseValue, (n / baseValue));

		n /= baseValue;
	}	
	puts("\n\n\n");

}
