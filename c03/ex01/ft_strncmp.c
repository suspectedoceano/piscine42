/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:51:04 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/22 17:53:55 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//DESCRIPTION
//     The strcmp() and strncmp() functions lexicographically compare the null-terminated strings s1 and s2.
//     The strncmp() function compares not more than n characters.

//RETURN VALUES
//     The strcmp() and strncmp() functions return an integer greater than, equal to, or less than 0, according as the string s1 is greater than,
//     equal to, or less than the string s2.  
//     The comparison is done using unsigned characters, so that `\200' is greater than `\0'.

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{						//If i use n-- i will reach s[4]
						//⬇︎ prefix decrement, i want to reach s1[3]
	while (*s1 == *s2 && --n && *s1)
	{
		s1++, s2++;
	}
	return (*s1 - *s2);
}

#define N 4	

int main()
{
	char	*s;
	char	*s1;

	s = "Hel~o world";
	s1 = "Hell world";
	printf("N->%d\n%s\n%s\nstrncmp-> %d\nft_strcmp-> %d\n\n\n",N, s, s1, strncmp(s, s1, N), ft_strncmp(s, s1, N));

	s = "hello world";
	s1 = "hel world";
	printf("N->%d\n%s\n%s\nstrncmp-> %d\nft_strcmp-> %d\n\n\n", N ,s, s1, strncmp(s, s1, N), ft_strncmp(s, s1, N));

	s = "hel world";
	s1 = "hello world";
	printf("N->%d\n%s\n%s\nstrncmp-> %d\nft_strcmp-> %d\n\n\n",N, s, s1, strncmp(s, s1, N), ft_strncmp(s, s1, N));


	s = "";
	s1 = "";
	printf("N->%d\n\"%s\"\n\"%s\"\nstrncmp-> %d\nft_strcmp-> %d\n\n\n",N, s, s1, strncmp(s, s1, N), ft_strncmp(s, s1, N));
}
