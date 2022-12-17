/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:03:12 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/17 14:13:47 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


// Create a function that counts and returns the number of characters in a string
// int ft_strlen(char *str);

int 	ft_strlen(char *str)
{
/*	//easy iterative solution
	int		len;

	len = 0;
	while (*(str + len))
		++len;
	return (len);
*/
	

	//For every iterative solution, there's one recursive.
	if ( ! (*str) )		
		return (0);
	return ft_strlen(str+1) + 1;

}


//Feed the strings in the command line
//~ gcc ft_strlen.c && ./a.out hello    

int main(int argc, char **argv)
{
	for(int i=1; i<argc; i++)
		printf("%s-> %d Chars\n",argv[i], ft_strlen(argv[i]));
}
