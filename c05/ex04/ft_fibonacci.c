/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:43:07 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/19 12:14:58 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//Fibo 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
//Tribo 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81

/*
 * You can have fib_trib_forbonacci...how many u want
 * I made an easy vanilla video 🍦 ->https://youtu.be/4W6CTp1eBe0
 * Once it clicks, it's super easy
 *
 * Overflows must not be handled
 * If the index is less than 0, the function should return -1
*/

int		ft_fibonacci(int index)
{
	if (index < 0)
		return -1;
	//I write 0 == index in this fashion
	//good luck find in big projects
	// ~ (index = 0) 🐞
	//Compiler doesn't catch it, cause it's legal  
	else if (0 == index)
		return 0;
	else if (1 == index)
		return 1;
	else
		return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

int		ft_tribonacci(int i)
{
	if (i < 0)
		return -1;
	else if (!i)
		return 0;
	else if (1 == i || 2 == i)
		return 1;
	else 
		return ft_tribonacci(i - 1) + ft_tribonacci(i - 3)+ ft_tribonacci(i - 2);
}


int		ft_fivbonacci(int i)
{
	if (i < 0)
		return -1;
	else if (0 == i)
		return 0;
	else if (1 == i || 2 == i)
		return 1;
	else if (3 == i)
		return 2;
	else if (4 == i)
		return 4;
	else 
		return ft_fivbonacci(i - 1) + ft_fivbonacci(i - 3)+ ft_fivbonacci(i - 2) + ft_fivbonacci(i - 4) + ft_fivbonacci(i - 5);
}



int main()
{
	printf("\n\n\n");
	printf("FIBONACCI\n");
	puts("");
	for(int i=-5; i<20; ++i)printf("%d ",ft_fibonacci(i));
	printf("\n\n\n");
	printf("TRIBONACCI\n");
	for(int i=-5; i<20; ++i)printf("%d ",ft_tribonacci(i));
	printf("\n\n\n");
	printf("FIVBONACCI\n");
	for(int i=-5; i<20; ++i)printf("%d ",ft_fivbonacci(i));
}
