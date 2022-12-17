/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:15:26 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/17 14:15:39 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
//Create a function that displays a string of characters on the standard output
// ~ void ft_putstr(char *str);

#include <unistd.h>


void	ft_putstr(char *str)
{
/*	//Iterative
	while (*str)
		write(1, str++, 1);
*/

	//recursive
	write(1, str, 1);
	if (*str)
		ft_putstr(str + 1);
	//write(1, str, 1); -> Get a reversed string 
	//with write under recursive call

}	

//Command line inputs
// ~ /a.out hello world
int main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
		ft_putstr(argv[i]), write(1, "\n", 1);
}
