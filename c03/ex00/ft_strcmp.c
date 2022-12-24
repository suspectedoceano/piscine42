/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:10:47 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/22 17:38:13 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/*
  
   The strcmp() compares two strings char wise.
   ~ If the strings are equal, the function returns 0.
   ~ > 0 if the first non-matching character in str1 is greater (in ASCII) than that of str2.
   ~ < 0 if the first non-matching character in str1 is lower (in ASCII) than that of str2.
   
   We have 3 cases
   1) "hello", "hello"  ->Strings are equal.
   2) "hel  ", "hello"  ->Strings are different s1 < s2
   3) "hello", "hel\0"    ->Strings are different s1 > s2
*/







int		ft_strcmp(char *s1, char *s2)
{
			         //Redundant 👀⬇︎
	while (*s1 == *s2 && *s1) //&& *s2) //this *s1 is for when strings are equal 
									//     ⬇︎
		++s1, ++s2;					//hello\0
									//hello\0  "yeah, equal, but Aren't we at the bottom??"
									//     ⬆︎
	return (*s1 - *s2);
}

















int main()
{
	char	*s; 
	char	*s1; 

	s = "Hello";
	s1 = "Hello";
	printf("%s\n%s\nft_strcmp-> %d\nstrcmp->    %d\n\n\n", s, s1, ft_strcmp(s, s1), strcmp(s, s1));

	s = "hello";
	s1 = "hel";
	printf("%s\n%s\nft_strcmp-> %d\nstrcmp->    %d\n\n\n", s, s1, ft_strcmp(s, s1), strcmp(s, s1));

	s = "hel";
	s1 = "hello";
	printf("%s\n%s\nft_strcmp-> %d\nstrcmp->    %d\n\n\n", s, s1, ft_strcmp(s, s1), strcmp(s, s1));


	s = "";
	s1 = "";
	printf("\"%s\"\n\"%s\"\nft_strcmp-> %d\nstrcmp->    %d\n\n\n", s, s1, ft_strcmp(s, s1), strcmp(s, s1));
}

