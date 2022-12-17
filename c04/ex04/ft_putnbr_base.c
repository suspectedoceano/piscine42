/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:19:44 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/17 14:21:24 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

• Create a function that displays a number in a base system in the terminal.

• This number is given in the shape of an int, and the radix in the shape of a string of characters.

• The base-system contains all useable symbols to display that number :
	◦ 0123456789 is the commonly used base system to represent decimal numbers 
	◦ 01 is a binary base system ;
	◦ 0123456789ABCDEF an hexadecimal base system ;
	◦ poneyvif is an octal base system 
	 ~The value is positional like normal numbers.
	  p -> 0
	  o -> 1
	  n -> 2
	   ...
								🚨CONSTRAINTS🚨

• The function must handle negative numbers ✅

• If there’s an invalid argument, nothing should be displayed. Examples of invalid arguments :
	◦ base is empty or size of 1;✅
	◦ base contains the same character twice;✅
   	◦ base contains + or -;✅
*/



#include <unistd.h>
#include <stdio.h>





//Prototypes
void 	ft_putnbr_base(int, char *);
int		ft_atoi(const char *);
void	ft_putchar(char c);
void    printNbr(int, int, char *); 
int		doubleChar(char *);







//COMMAND LINE ARGUMENTS argv[1]=n ; argv[2]=symbols

// ~gcc ft_putnbr_base.c && ./a.out 42 "01"

int		main(int argc, char **argv)
{
	int		n;
	char	*baseSymbols;
	
	//I use commandLine args for tests
	//Use simple strings if u dunno yet
	n = ft_atoi(argv[1]);//Ok
	baseSymbols = argv[2];//Ok

	//Exercise function
	ft_putnbr_base(n, baseSymbols);
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

	
	//base contains the same char twice
	if (doubleChar(base)) //Ok!
		return;

	//✅ CHECKS PASSED ✅
	//Recursively print number
	printNbr(nbr, baseValue, base);
}







void	printNbr(int n, int baseValue, char *symbols)
{
	//🚨 PRELIMINARY WORK 🚨
	//CASE WHEN N is Negative
	//long type, to trick the Overflow
	long 	nLong;

	nLong = n;
	if (nLong < 0)
	{
		//I'm sure here, no Overflow 
		nLong = -nLong;
		ft_putchar('-');
	}


	//🥩 REAL MEAT 🥩  
	//Elegance of recursion 💃
	if (nLong >= baseValue)
		printNbr(nLong / baseValue, baseValue, symbols);
	ft_putchar(symbols[nLong % baseValue]);
}






int 	doubleChar(char *symbols)
{
	int		i;
	int		j;

	i = 0;
	//Iteratively search for a double char
	//Same idea print_comb-> ~https://youtu.be/qshq8KnmWx8
	while (*(symbols + i))
	{
		j = i + 1;	
		while (*(symbols + j))
		{
			if (*(symbols + i) == *(symbols + j))
				return 1;
			++j;
		}
		++i;
	}
	return 0;
}







//atoi is just for the main TESTi, not the exercise itself
int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;

	while (str[i] == ' '  ||
		   str[i] == '\t' ||
		   str[i] == '\n' ||
		   str[i] == '\v' ||
		   str[i] == '\f' ||
		   str[i] == '\r')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
