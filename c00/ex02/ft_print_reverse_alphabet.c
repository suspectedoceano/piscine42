/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:37:38 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 17:48:12 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_reverse_alphabet(void)
{
	short	c;

	c = 122;
	while (c > 96)
	{
		write(1, &c, 1);
		--c;
	}
}

void	ft_print_reverse_alphabet2(void)
{
	short	c;

	c = '{';
	while (--c > '`')
		write(1, &c, 1);
}

int	main(void)
{
	ft_print_reverse_alphabet();
	write(1, "\n", 1);
	ft_print_reverse_alphabet2();
	write(1, "\n", 1);
}
