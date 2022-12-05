/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:37:44 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/05 09:57:50 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Good article about this function -> https://lwn.net/Articles/507319/
 * strcpy() function copies the string src to dst (including the terminating `\0' character.)
 * returns dest
 * The strcpy() function is easily misused, buffer overflow issue ->  https://www.youtube.com/watch?v=1S0aBV-Waeo
 * If the destination string of a strcpy() is not large enough, then anything might happen.
*/

//change the size of destBuffer here
#define BUF_SIZE 111

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	//I use the char pointed as a boolean 💡
	while (*src)
		*(dest + i++) = *src++;
	
	//Append sentinel
	*(dest + i) = '\0';
	return (dest);
}

int	main()
{
	char	srcBuffer[256];
	char	destBuffer[BUF_SIZE];
	char	c;
	int 	i;

	i = 0;
	
	//Dest buffer is {////////////////}
	for(int i=0; i<BUF_SIZE; ++i)destBuffer[i]='/';

	//fancy check
	for (int j=0; j<10; ++j)
	{
		//Create a random string in srcBuffer
		while ((c = rand()%27+97) != 123)
			srcBuffer[i++] = c; 
		//My final sentinel
		srcBuffer[i] = 0;
		//Refresh i for next iteration
		i = 0; 

		//Check if algo correct
		puts("RANDOM STRING SOURCE");
		//Ternary operator
		(*srcBuffer) ? printf("%s SIZE-> %lu\n", srcBuffer, strlen(srcBuffer)) : puts("empty string");		

		//I can feed directly the function to printf, cause return value is dest
		printf("DEST BUFFER SIZE -> %d\n", BUF_SIZE);
		printf("\nFrom the original function->           DEST =  %s\n", strcpy(destBuffer, srcBuffer));
		//clean the buffer
		for(int i=0; i<BUF_SIZE; ++i)destBuffer[i]='/';
		printf("From my function->                     DEST =  %s\n\n\n", ft_strcpy(destBuffer, srcBuffer));
		printf("-----------------\n\n");
	}
}


