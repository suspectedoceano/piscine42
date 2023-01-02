/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 09:48:55 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/24 17:24:09 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*	THEORY
	~Good article -> https://lwn.net/Articles/507319/
	~I have to copy N char from source to dest
	~If (N > source) i will pad [N - source] of 0s into dest.  
  	~Returns a pointer to dest

	1)
	strncpy() is not intended to be used as a safer strcpy(), 
	💡it is supposed to be used to insert one string in the middle of another💡
	That's why not '\0' is added.
	If there is no null byte among the first N bytes of src, the string placed in dest will not be null terminated.
	2)
	strncpy was never intended to be a "safe alternative" to strcpy,
   	though that is the impression a lot of new C programmers get since it does take a "size" parameter.
   	💡The third argument is for the number of char to be read from the source buffer, not the maximum capacity of the destination buffer💡
*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		i;

	i = 0;
	//Copy part
	while (*src && n)
	{
		*(dest + i++) = *src++;
		--n;
	}
	//Pad with 0s if n not exausted
	while (n--)
		*(dest + i++) = '\0';
	return (dest);
}


#define N 60
#define BUF_SIZE 60

int main()
{
	char	srcBuffer[256];
	char	dstBuffer[BUF_SIZE];
	int 	j;
	char	c;

	for (int i=0; i<20; ++i)
	{
		
		//Refresh j
		j = 0;
		//Clean the buffers
		for (int i=0; i<BUF_SIZE; ++i)dstBuffer[i]='/';
		for (int i=0; i<256; ++i)srcBuffer[i]=0;

		//Fill source with random chars
		while ((c = rand()%27 + 97) != 123)srcBuffer[j++] = c;
		//Sentinel '\0'
		srcBuffer[j] = '\0';

		printf("-----------------------------------------"
				"\nIf (N > source) i will pad [%d - %lu] of 0s dest."  
				"\n\n\nSource Buffer                -> %s Len->%lu\n", N, strlen(srcBuffer), *srcBuffer ? srcBuffer : "Empty line", strlen(srcBuffer));
		printf("Dest Buffer before function  -> %s Len-> %lu\n", dstBuffer, strlen(dstBuffer));
		printf("Elements to copy           N -> %d\n", N);
		printf("Dest Buffer after real function   -> %s\n", strncpy(dstBuffer, srcBuffer, N));

		//Check the bytes
		printf("BYTES IN MY DEST BUFFER AFTER STRNCPY ORIGINAL\n");
		for (int i=0; i<BUF_SIZE; ++i) 
			(dstBuffer[i] == 0) ? printf("0") : printf("%c ", dstBuffer[i]);
		printf("\n\n------------------------------------------\n");
		
		for (int i=0; i<BUF_SIZE; ++i)dstBuffer[i]='/';
		printf("Dest Buffer after my function     -> %s\n", ft_strncpy(dstBuffer, srcBuffer, N));
 		printf("BYTES IN MY DEST BUFFER AFTER MY FT_STRNCPY \n");
		for (int i=0; i<BUF_SIZE; ++i)
			(dstBuffer[i] == 0) ? printf("0") : printf("%c ", dstBuffer[i]);
		printf("\n\n------------------------------------------\n\n\n\n\n\n\n\n");
	}


}
