#include<stdio.h>



//Convert n in a base




void		magic(int nb, int baseValue ,char *baseSymbols)
{
	if (nb > baseValue)
		magic(nb / baseValue, baseValue, baseSymbols);


	char	mySymbol;
	
	mySymbol = baseSymbols[nb % baseValue];
	while (*baseSymbols != mySymbol)
		baseSymbols++;
	printf("%c", *baseSymbols);
}		


int main()
{	
	int		n = 55269;
	char 	baseSymbols[] = "0123456789abcdef";
	int		baseValue = 16;

	magic(n, baseValue, baseSymbols);
}

