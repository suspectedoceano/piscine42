/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:36:04 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/21 16:27:38 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*DESCRIPTION
 *
 * char * strncat(char *restrict s1, const char *restrict s2, size_t n);
 *
 * Append src into dest, with a final '\0'
 *
 * CONSTRAINT
 * This time i have a limit n of chars that i can copy
 *
 * RETURN dest
 *
 * 🚨Buffer overflow issue🚨
 *	   if (src > dest)
*/

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
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
	//I append <=nb chars from src chars into dest
	while (*(src + i) && nb--)
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
#define N 3

int main()
{
	char	s[DEST_SIZE] = "hello";
	char	s1[100] = " world";

	puts("ORIGINAL strncat");
	printf("Chars i wanna cat %d\n", N);
	printf("\"%s\" + \"%s\" =\n", s, s1);
	printf("\"%s\"\n", strncat(s, s1, N));
	
	char	s2[DEST_SIZE] = "hello";
	char	s3[100] = " world";
	puts("");

	puts("My FAKE strncat");
	printf("Chars i wanna cat %d\n", N);
	printf("\"%s\" + \"%s\" =\n", s2, s3);
	printf("\"%s\"\n", ft_strncat(s2, s3, N));
}

