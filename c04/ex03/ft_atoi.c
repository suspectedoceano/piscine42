/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:58:04 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/13 10:06:09 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
 * • Write a function that converts the INITIAL PORTION of the string pointed by str to its int representation
 *
 * • The string can start with an arbitrary amount of spaces isspace() 
		~The isspace() function tests for the white-space characters.  
		 This includes the following standard characters:
		 ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''
 
 * •There can be a random set of + | -, this will discipline the sign
 
 * •Your function should read the string until the rule holds

 * •The string is composed of base 10 numbers	
 
 * •Your function should read the string until the string stop following the rules 

 * •Overflow or Underflow not our businees
*/  


int		ft_atoi(char *str)
{
	short	parity;
	int		number;

	parity = number = 0;

	//String can have x many spaces -> isspace. SKIP THEM
/*	
	while (*str == '\t' ||
		   *str == '\n' ||
		   *str == '\v' ||
		   *str == '\f' ||
		   *str == '\r' ||
		   *str == ' ') 	
	       //Until isspace✅, keep going on
		       ++str;
*/	
	//Cleaner way, maybe more cryptic
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;

	//Unknown amount + and - -> if (even -) number_positive; else (opposite)
	//Move in the string, counting the minus signs
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			parity++;
		++str;
	}	
	//Check all numbers and stock in accumulator number	
	while (*str >= 48 && *str <= 57)	
	{
		//This is a << shift_base10_like operation
		number *= 10;
		//Conversion from char to number
		number += *str - 48;
		++str;
	}
	// !(parity % 2) -> "Is the value even?"
	if ( ! (parity % 2))
		return (number);
	return (-number);
}

int main()
{
	char	*s = "    ---+--+1234ab567";

	printf("%d\n",ft_atoi(s));	
}
