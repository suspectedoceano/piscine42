/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:59:59 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/18 13:34:01 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>


/*
 *	Good article -> https://www.mathsisfun.com/numbers/factorial.html
 *
 *	Why factorial? For COMBINATIONS.
 *
 * 	52! = 52*51*50...*1
 *
 *	♠️  ♥️  ♣️  ♦️  There are 52! ways to shuffle a deck of cards.
 *	There are about 60! atoms in the observable Universe.
 *	Just shuffle a deck of cards,
 *	it is likely that you are the first person ever with that particular order.
 *
 *	Why 0! = 1 -> https://www.youtube.com/watch?v=X32dce7_D48
 *
 *  -1! = 0! / 0 ->division by zero is undefined [-Wdivision-by-zero]
*/

int		ft_recursive_factorial(int nb)
{
	//Negative input error
//	if (nb < 0)
//		return -1;

	//🕺 Elegance of recursion 🕺
	if (0 == nb)
		return 1;
	return ft_recursive_factorial(nb - 1) * nb;
}

int main()
{
	puts("\n\n");
	for(int i = 0; i < 10; ++i)
	{
		if (0 == i){printf("Factorial %d !%d-> %d\t\t\n\n",i , i, ft_recursive_factorial(i)); continue;}
		printf("Factorial %d !%d-> %d\t\t",i , i, ft_recursive_factorial(i));
		printf("%d / %d -> %d\n\n",ft_recursive_factorial(i), i, ft_recursive_factorial(i) / i);
	}


}

