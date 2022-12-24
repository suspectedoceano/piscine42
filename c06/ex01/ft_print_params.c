/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:41:57 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/23 12:54:44 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>



 //PRO SOLUTION

void	ft_puts(char *str)
{
	//man 3 puts
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

// ~gcc ft_print_params.c && ./a.out hello damn you
int 	main(int argc, char **argv)
{
	//Trick -Wall -Wextra -Werror 
	(void)argc;

	while (*(++argv))
		ft_puts(*argv);
}





// LESS PRO WAY
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char *argv[])
{
	//Trick -Wall -Wextra -Werror
	(void)argc;

	int 	j;
	int 	k;

	j = 1;
	while (argv[j] != NULL)	
	{
		//Refreshing at every iteration
		k = 0;	
		while (argv[j][k] != '\0')
		{
			ft_putchar(argv[j][k]);
			++k;
		}
		++j;
		ft_putchar('\n');
	}
}

*/



