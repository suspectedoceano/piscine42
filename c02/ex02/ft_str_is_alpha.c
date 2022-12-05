/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:29:56 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/05 10:04:48 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int		ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;

	//Assume String not empty, Until  don't reach \0, keep going
	while (str[i] != '\0')
	{
		//[ ] notation, syntactic sugar 🍭
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			++i; 
		}
		else
		{
			//Stumbled upon a non alpha
			return (0);
		}
	}
		
	//Or the string is empty, or only alpha chars
	return (1);
}

///*
int		ft_str_is_alphaPro(char *str)
{
	//Use * notation 
	//Use directly the char pointed as a bool 💡
	while (*str)
	{	//This ! inverts the logic. Letters in binary, the real deal 😂
		if ( ! ((*str >= 0b01100001 && *str <= 0b01111010) || (*str >= 0b01000001 && *str <= 0b01011010)))
			return (0);
		++str;
	}
	return (1);
}
//*/

int		main()
{
	char	str[2000];
	int 	j;
	char	c;
	
	while (1)
	{
		//refresh every time j
		j = 0;

		//Create a randome string
		while ((c = rand()%95+33) != 127 )
			str[j++] = c;
		str[j] = 0;

		//Print if only alpha or not
		printf(   "%s -> %s\n\n\n",
				str, 
				(ft_str_is_alphaPro(str)) ? 
				"This string contains only alpha chars or is empty" : 
				"Also non alpha chars");
		
		//Fun condition, 
		if (ft_str_is_alphaPro(str) && (strlen(str) > 10)) break;
	}	
}
