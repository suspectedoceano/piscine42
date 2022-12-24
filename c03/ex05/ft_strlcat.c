/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:31:37 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/21 17:54:37 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strlcat() function appends the NUL-terminated string src to the end of dst. 
//It will append at most size.
//For strlcat() that means the initial length of dst plus the length of src. 
//While this may seem somewhat confusing, it was done to make truncation detection simple.

/*
  DESCRIPTION

     strlcat() appends string src to the end of dst.  
	 						  BUFFER      CHARS        For '\0'
	 It will append at most (dstsize - strlen(dst) - 1 characters) 
	 It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize.
     If the src and dst strings overlap, the behavior is undefined.

RETURN VALUES

     The total length of the string they tried to create-> (Len src + len dest)

     If the return value is >= dstsize, the output string has been truncated.  It is the caller's responsi-
     bility to handle this.

	size_t  strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
*/

#include <stdio.h>
#include <string.h>


int		size_sum(char *src, char *dst)
{
	int		k, k1;

	k = k1 = 0;
	while (*(src + k))
		++k;
	while (*(dst + k1))
		++k1;
  //(Len src + len dest)
	return (k + k1);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int		k;
	int		space;
	int		ret;

	k = 0;
	//Get the size of destStr
	while (*(dest + k))
		++k;

	//How much space i have to copy?
	//-1 for '\0'
	space = (size - k) - 1;
	ret = size_sum(dest, src);

	while (*src && space--)	
		*(dest + k++) = *src++;

	*(dest + k) = '\0';

	return (ret); 
}

#define DEST_BUFFER 30

int main()
{		
	char	s[DEST_BUFFER] = "Hello";
	char	s1[100] = " world i love you";

	printf("Before cat-> \"%s\"\n",s);
	
					//Check thelimit
	int i = strlcat(s, s1, sizeof(s));
	printf("\"%s\", src + dest %d, from real function\n",s, i);



	char	s2[DEST_BUFFER] = "Hello";
	char	s3[100] = " world i love you";

	printf("\n\nBefore cat-> \"%s\"\n",s2);
					//Check thelimit
	int d = ft_strlcat(s2, s3, sizeof(s));
	printf("\"%s\",  src + dest %d, from my function\n",s, d);


}
