/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:45:21 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 17:49:20 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	short	n;

	n = 47;
	while (++n < 58)
		write(1, &n, 1);
}

void	ft_print_numbers2(void)
{
	char	n;

	n = '/';
	while (++n < ':')
		write(1, &n, 1);
}

int	main(void)
{
	ft_print_numbers();
	write(1, "\n", 1);
	ft_print_numbers2();
	write(1, "\n", 1);
}
