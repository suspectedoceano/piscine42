/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:16:01 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/18 14:06:39 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<math.h>


/*
 * Why n^0 = 1? 
 * https://www.youtube.com/watch?v=mYtmSx_dN_I
 *
 * An power lower than 0 returns 0.
 * 0 power 0 will return 1.
 * Overflows must not be handled.
*/

int ft_iterative_power(int nb, int power)
{
	//Power lower than 0
	if (power < 0)
		return 0; //Real returns INT_MIN

	int		accumulator; //Why the name 'accumulator'
						 //https://en.wikipedia.org/wiki/Accumulator_(computing)

	//Value 1 is neutral for multiplications
	accumulator = 1;

	// 2^3 -> 2*2*2  
	// Accumulator * (powerTimes of nb)
	// _1_*2*2*2
	// 2^0 is _1_* null🤷. That's why n^0 = 1. 
	// 0^0 is _1_* null🤷. That's why 0^0 = 1.   
	while (power--)
		accumulator *= nb;

	return accumulator;


}

#define nb 10

int main()
{
	puts("\n\n");

	for (int i = -10; i <= 32; ++i)
	{
		printf("My function   %d^%d -> %d\n", nb, i, ft_iterative_power(nb, i));
		printf("Real function %d^%d -> %d\n\n", nb, i, (int)pow(nb, i));

	}

}
