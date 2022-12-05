/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:05:52 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 18:15:07 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//RECURSIVE WAY

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	n;

	if (nb < 0)
	{
		//Special case for min int
		//I cannot put it in int->Overflow
		//Max positive for int is 2147483647. 1 less.
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		else
		{
			write(1, "-", 1);
			//2 complement way of inverting i.e. ~1100 = 0011
			nb = ~(nb) + 1;
			ft_putnbr(nb);
			return ;
		}
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	n = (nb % 10) + 48;
	write(1, &n, 1);
}

int	main(void)
{
	ft_putnbr(-42);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
}
