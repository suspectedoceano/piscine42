/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:27:58 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/28 11:51:51 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*
 * 💡 The idea is that there are 32 chars between {A->a , B->b, C->c .. Z->z}💡.
 *  A char is just 1 byte integer
 *  I can toggle from up to lower just adding or subtracting 32
*/

char	*ft_strlowcaseArray(char str[])
{
	//Array notation, easies to read. Syntactic 🍭 sugar.
	int		i;

	i = 0;
	while (str[i])
	{
		//If char UPPER, to lower
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		++i;
	}
	return (str);
}	


char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		//If char is ALPHA-UPPER, change to lower
		if (*(str + i) >= 65 && *(str + i) <= 90)
			*(str + i) += 32;
		//Otherwise, just keep going
		++i;
	}
	return (str);
}	

int main()
{
	char	v[200];
	int		j;
	char	c;

	for (int i=0; i<100; ++i)
	{
		//Refresh j for next iteration
		j = 0;

		//Create random string with upper and lower chars
		while ((c = rand()%27+65) != 91)
		{
			//I use parity as a trick to toggle Upper_Lower chars
			if (c % 2)
				v[j++] = c;
			else 
				v[j++] = c + 32;
		}
		v[j] = '\0';

		//See what happened 
		printf("\n%s\n", v);
		printf("%s\n\n", ft_strlowcaseArray(v));
		
	}
}	

