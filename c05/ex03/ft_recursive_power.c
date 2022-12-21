/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:24:45 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/18 14:06:12 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<math.h>


/*
 * Why n^0 = 1?
 * https://www.youtube.com/watch?v=mYtmSx_dN_I
 *
 * Overflows must not be handled.
 * 0 power 0 will returns 1.
*/

int ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return 0; //Real returns INT_MIN
	else if (0 == power)
		return 1;
	return ft_recursive_power(nb, power - 1) * nb;

}

#define n 2

int main()
{
	puts("\n\n");

	for (int i = -10; i <= 20; ++i)
	{
		printf("My function   %d^%d -> %d\n", n, i, ft_recursive_power(n, i));
		printf("Real function %d^%d -> %d\n\n", n, i, (int)pow(n, i));

	}

}

