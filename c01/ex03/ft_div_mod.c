/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:18:22 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 18:41:05 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b)
	{
		*div = a / b;
		*mod = a % b;
	}
}

int		main(void)
{
	int		div, mod, n, n1;

	n = 42;
	n1 = 21;
	ft_div_mod(n, n1, &div, &mod);
	printf("\n%d/%d = %d with remainder %d\n\n", n, n1, div, mod);
}
