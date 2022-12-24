/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:41:54 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/21 16:25:23 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
 *
 * char * strcat(char *restrict s1, const char *restrict s2);
 *
 * Append src into dest, with a final '\0'
 *
 * RETURN dest
 *
 * 🚨Buffer overflow issue🚨
 *	   if (src > dest)
*/

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		destEnd;

	i = destEnd = 0;
      
	//      ⬇︎ i Wanna reach destEnd
	//"hello\0________"
	while (*(dest + destEnd))
		++destEnd;

	//	 destEnd
	//		⬇︎
	//"hello________" ⬅︎ dest
	//" world\0"      ⬅︎ src
	//I append all the src chars into dest
	while (*(src + i))
	{
		*(dest + destEnd) = *(src + i);
		++i;
		++destEnd;
	}

	//Append a \0 to dest
	//			  ⬇︎
	//"hello world\0"
	*(dest + destEnd) = '\0';

	return (dest);
}


#define DEST_SIZE 13

int main()
{
	char	s[DEST_SIZE] = "hello";
	char	s1[100] = " world";

	puts("ORIGINAL strcat");
	printf("\"%s\" + \"%s\" =\n", s, s1);
	printf("\"%s\"\n", strcat(s, s1));
	puts("");	
	char	s2[DEST_SIZE] = "hello";
	char	s3[100] = " world";

	puts("MY FAKE ft_strcat");
	printf("\"%s\" + \"%s\" =\n", s2, s3);
	printf("\"%s\"\n", ft_strcat(s2, s3));
}
