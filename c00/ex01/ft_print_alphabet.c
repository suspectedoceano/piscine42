/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:31:39 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 17:46:52 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c < 123)
	{
		write(1, &c, 1);
		++c;
	}
}

//Chars are just 1 byte int  
//Totally equal functions
void	ft_print_alphabet2(void)
{
	char	c;

	c = 0b01100000;
	//c = 96;
	//c = '`';
	//c = 0x60;
	while (++c <= 'z')
		write(1, &c, 1);
}

int	main(void)
{
	ft_print_alphabet();
	write(1, "\n", 1);
	ft_print_alphabet2();
	write(1, "\n", 1);
}
