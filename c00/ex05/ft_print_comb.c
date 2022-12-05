/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:28 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 17:53:35 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_n(char v[])
{
	if (v[0] == '7' && v[1] == '8' && v[2] == '9')
	{
		write(1, v, 3);
		write(1, ".\n", 2);
	}
	else
		write(1, v, 5);
}

void	ft_print_comb(void)
{
	char	v[5];

	v[0] = '0';
	v[3] = ',';
	v[4] = ' ';
	while (v[0] <= '7')
	{
		v[1] = v[0] + 1;
		while (v[1] <= '8')
		{
			v[2] = v[1] + 1;
			while (v[2] <= '9')
			{
				//the stupid +1 creates the order
				//if (v[1] > v[0] && v[2] > v[1])
				write_n(v);
				v[2]++;
			}
			v[1]++;
		}
		v[0]++;
	}
}

int	main(void)
{
	ft_print_comb();
}
