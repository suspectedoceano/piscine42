/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:09:12 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/23 12:57:56 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	//man 3 puts
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}


int main(int argc, char **argv)
{
	/*
	 * argv--   [0]-->[./a.out\0]
	 * 		|	[1]-->[hello\0]
	 * 		|	[2]-->[world\0]
*(argv+argc) -->[3]-->[damn\0]
	 *
	 * argc = 4;
	*/

    //Start from 3, skip the 0 cause false.
	while (--argc)
		ft_putstr(argv[argc]);
}
