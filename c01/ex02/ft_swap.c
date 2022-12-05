/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:19:44 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 18:37:25 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//Wrong naive implementaion of swap, check:
// -STACK
// -FUNCTION CALLS
/*
void	ft_swap_naive(int a, int b)
{
	int		tmp;

	tmp = a;
	a = b;
	b = tmp;	
}

int main()
{
	int		n, n1;

	n = 42;
	n1 = 21;
	printf("before\n %d %d\n", n, n1);
	ft_swap_naive(n, n1);
	printf("after\n %d %d\n", n, n1);
}
*/

void	ft_swap(int *a, int *b)
{
	int		tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;	

//  Comma operator more compact!  
//	tmp = *a, *a = *b, *b = tmp;
}

int main()
{
	int		n, n1;

	n = 42;
	n1 = 21;
	printf("before\n %d %d\n", n, n1);
	ft_swap(&n, &n1);
	printf("after\n %d %d\n", n, n1);
}

/*
void 	ft_swap2(int *a, int *b)
{
	//Pro solution, XOR swap
	
	//Encripted 🔒🔐 ->a+b information
 
// 🔒🔐   🔓     🔓 
	*a =  *a  ^  *b;

	//I want a back-> *a(🔒🔐) ^ *b(🔑)
//  a🔒  🔒🔐    🔒
	*b =  *a  ^  *b;

	//I want b back-> *a(🔒🔐) ^ *a(🔑, which is '*b' now)
//	b🔒  🔒🔐    🔒
	*a =  *a  ^  *b;
}

int main()
{
	int		n, n1;

	n = 42;
	n1 = 21;
	printf("before\n %d %d\n", n, n1);
	ft_swap2(&n, &n1);
	printf("after\n %d %d\n", n, n1);
}
*/
