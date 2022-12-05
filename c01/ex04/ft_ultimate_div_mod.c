/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:30:43 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/07 16:20:50 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> //For the random numbers 

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		tmp;

	if (*b)
	{
		tmp = *a;
		*a = *a / *b;
		*b = tmp % *b;
	}
}

int	main()
{
	int		a, b;

	for (int i=0; i<10; i++)
	{
		a = rand()%101;
		b = rand()%10;
		printf("a=%d b=%d\n", a, b);
		printf("quotient=%d module=%d\n", a/b, a%b);
		ft_ultimate_div_mod(&a, &b);
		printf("-----From my func-------\n");
		printf("quotient=%d module=%d\n\n", a, b);
	}

}
