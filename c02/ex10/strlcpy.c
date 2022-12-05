/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:05:42 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/24 17:39:11 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*
    ~GOOD ARTICLE->https://lwn.net/Articles/507319/
	~The strlcpy() function returns the total length of the string strlcpy tried to create.  
	~For strlcpy() that means the length of src. 
    ~If the return value is >= dstsize, the output string has been truncated. 
   	~It is the caller's responsibility to handle this, i.e. Losing information.
*/

#define DEST_BUF 10

unsigned int	ft_strlcpy(char *dest,char *src, unsigned int size);

int main()
{
	char	destBuffer[DEST_BUF];
	char	srcBuffer[256];
	int		i;
	char	c;

	for (int j=0; j<10; ++j)
	{	
		//clean the buffers
		for (int i=0; i<256; ++i)srcBuffer[i]=0;for(int i=0; i<DEST_BUF; ++i)destBuffer[i]='/';
		//Create a random string in buffer
		i = 0;
		while ((c = rand()%27+97) != 123)
			srcBuffer[i++] = c;
		
		//strlcpy returns me the bytes copied
		printf("\n\n---------------------------------------------------"
				"\nRandom  source-> %s Len-> %lu"
				"\n            The size of destBuffer                 -> %lu"
				"\n      The len of srcBuffer (return value strlcpy)  -> %lu\n",
				 *srcBuffer == 0 ? "empty string" : srcBuffer, strlen(srcBuffer),
				 sizeof(destBuffer), strlcpy(destBuffer, srcBuffer, DEST_BUF));	
		puts("DEST AFTER ORIGINAL FUNCTION");
			puts(destBuffer);

		//See the bytes
		printf("BYTES FROM DEST\n");
		for(int i=0; i<DEST_BUF; ++i)destBuffer[i] == 0 ? printf("\\0") : printf("%c ", destBuffer[i]);
	
		//clean the destBuffer
		for(int i=0; i<DEST_BUF; ++i)destBuffer[i]='/';

		printf("\n\n---------------------------------------------------"
				"\nRandom  source-> %s Len-> %lu"
				"\n            The size of destBuffer                 -> %lu"
				"\n      The len of srcBuffer (return value strlcpy)  -> %d\n",
				 *srcBuffer == 0 ? "empty string" : srcBuffer, strlen(srcBuffer),
				 sizeof(destBuffer), ft_strlcpy(destBuffer, srcBuffer, DEST_BUF));	
		puts("DEST AFTER MY FUNCTION");
			puts(destBuffer);
		//See the bytes
		printf("BYTES FROM DEST\n");
		for(int i=0; i<DEST_BUF; ++i)destBuffer[i] == 0 ? printf("\\0") : printf("%c ", destBuffer[i]);
		puts("\n"
			"--------------------------------------------------\n\n\n\n");
	}
}

unsigned int    ft_strlcpy(char *dest,char *src, unsigned int size)
{
	//Pro typing, 🚨not good practice🚨
	int		len;

	len = 0;
	while (*(src + len) && --size)
		*dest++ = *(src + len++);
	*dest = '\0';		
	while (*(src + len))
		++len;
	return (len);
}

