/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:23:17 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/17 14:18:38 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ~Create a function that displays the number entered as a parameter.
 ~The function has to be able to display all possible values within an int type variable.

			byte 3   byte 2   Byte 1   Byte 0
	max_int 01111111_11111111_11111111_11111111 ->  2'147'483'647
	min_int 10000000_00000000_00000000_00000000 -> -2'147'483'648 

 ~void ft_putnbr(int nb);
 ~ft_putnbr(42) displays "42".
*/



#include <unistd.h>

//3 implementations of putnbr


//Prototypes
void	ft_putchar(char);
void	ft_putnbr(int);
void    ft_putnbr1(int num); 
void    ft_putnbr2(int nb);

//Constants
#define INT_MIN -2147483648

int main()
{
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(9002);
	write(1, "\n", 1);
	ft_putnbr(-9002);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-42);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647); 
	write(1, "\n", 1);
}




void	ft_putchar(char c)
{
	write(1, &c, 1);
}


//RECURSION 
void	ft_putnbr(int nb)
{
	//PRELIMINARY CONTROL STUFF
	//corner case INT_MIN and n is negative block
	if (nb < 0)
	{			  //INT_MIN	
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return; //This return is important
		}
		else  
		{
			//2s complement
			nb = ~nb + 1; //nb *= -1 || nb = -nb;
			write(1, "-", 1);
		}
	}


	//💃🎩 ecursive elegance 💃🎩
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}


//RECURSION 2
void	ft_putnbr1(int nb)
{
	//Top solution 🐇🎩
	//This long avoids the overflow deal
	/*
	 * let's say i have MIN_INT 10000000_00000000_00000000_00000000
	 * this 2147483648 cannot be represented in 4 bytes
	 * because the MAX_INT is   01111111_11111111_11111111_11111111
	 * namely +2147483647
	 * TL;DR
	 * I take a bigger box
	*/ 
	long 	nbLong;

	nbLong = nb;
	if (nbLong < 0)
	{
			nbLong = -nbLong;
			write(1, "-", 1);
	}

	//💃🎩 ecursive elegance 💃🎩
	if (nbLong > 9)
		ft_putnbr(nbLong / 10);
	ft_putchar((nbLong % 10) + 48);
}






//ITERATION
void	ft_putnbr2(int nb) 
{
	int		magnitude;
	int 	copy;

	copy = nb;
	magnitude = 1;
	//PRELIMINARY CONTROL
	//MIN_INT || Negative
	if (nb < 0)
	{			  //INT_MIN	
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return; //This return is important
		}
		else  
		{
			//2s complement
			nb = ~nb + 1; //nb *= -1 || n = -n;
			write(1, "-", 1);
		}
	}

	//Order of magnitude of the number
	//How many 0s are there
	while (nb > 9 && copy / 10)	
	{
		copy /= 10;
		magnitude *= 10;
	}

	//Iteration to print the num
	while (magnitude)
	{
				       //🥩 of the code
		ft_putchar(((nb / magnitude) % 10) + 48);
		magnitude /= 10;
	}
}
