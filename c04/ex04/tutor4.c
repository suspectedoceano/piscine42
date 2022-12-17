#include <unistd.h>
#include <stdio.h>





//Prototypes
void 	ft_putnbr_base(int, char *);
void	ft_putchar(char c);
void    printNbr(int, int, char *); 







int		main()
{
	int		n;
	char	*baseSymbols;
	
	//Exercise function
	ft_putnbr_base(42, "01");
	puts("\n");
	ft_putnbr_base(42, "0123456789abcdef");
}







void 	ft_putnbr_base(int nbr, char *base)
{
	int		baseValue;

	baseValue = 0;

	//🚨PRELIMINARY CONTROLS🚨
	
	
	//Get the value of my base
	//With a nested constrain control
	while (base[baseValue])
	{
		//I do i constrain check in beetween💡
		//base contains + or - ;
		if (base[baseValue] == '+' || base[baseValue] == '-')
			return;
		//Actual base value
		++baseValue;
	}


	//base is empty or size of 1;
	if (baseValue < 2)
		return;

	
	//✅ CHECKS PASSED ✅
	//Recursively print number
	printNbr(nbr, baseValue, base);
}



void	printNbr(int n, int baseValue, char *symbols)
{
	//🚨 PRELIMINARY WORK 🚨
	//CASE WHEN N is Negative
	//long to trick the Overflow
	long 	nLong;

	nLong = n;
	if (nLong < 0)
	{
		//I'm sure here, no Overflow 
		nLong = -nLong;
		ft_putchar('-');
	}


	//🥩 Of the exercise
	//Elegance of recursion 💃
	if (!nLong)
		return;
	else
	{
		printNbr(nLong / baseValue, baseValue, symbols);
		ft_putchar(symbols[nLong % baseValue]);
	}
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}
