/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:05:44 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/23 12:43:43 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>




void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int		i;
	//Trick -Wall -Wextra -Werror
	(void)argc;

	i = 0;
	while (argv[0][i] != '\0')
	{	
		ft_putchar(argv[0][i]);
		++i;
	}

}


/*
int main(int argc, char **argv)
{
	//Trick -Wall -Wextra -Werror
	(void)argc;
	
	//Pro, 2 lines.
	while (**argv)
				 //👀 (necessary)	
		write(1, (*argv)++, 1);
}
*/
