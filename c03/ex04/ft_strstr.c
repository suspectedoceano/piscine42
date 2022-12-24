/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:00:52 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/21 17:07:49 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
 *
 *char *strstr(const char *haystack, const char *needle);
 *
 *  DESCRIPTION
 *  strstr locates the first occurrence of the null-terminated string needle in the
 *  null-terminated string haystack.
 *
 *  RETURN VALUES
 *  If needle is an empty string, haystack is returned;
 *  If needle occurs nowhere in haystack, NULLis returned;
 *  otherwise a pointer to the first character of the first occurrence of needle is returned.
 *
*/

#include<stdio.h>
#include<string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		k, k1, l;

	k = 0; //Haystack cursor

	//if not needle return Haystack
	if (!to_find)
		return (str);


	//Search for the matching pattern
	//	        kk1				        k1	 
	//		    ⬇︎⬇︎  .  . . .  . .  . .  ⬇︎
	//str->	    "This is a random string\0"
	//
	//		     l
	//			 ⬇︎
	//to_find->	" rando\0"
	//
	while (*(str + k))  //Until there is an haystack str, select a char
	{
		//k1 subhayack cursor
		k1 = k;
		l = 0;

		
		//If char == to needle 1^ char, start checking all chars
				  //char  is  equal 	        //Needle !end
		while (*(str + k1) == *(to_find + l) && *(to_find + l))
			++k1, ++l;

		//If managed to reach end of needle,THAT'S a MATCH. return sub-string
		if (!(*(to_find + l)))
			return (str + k);

		//Keep moving on haystack
		++k;
	}
	//If no match, NULL pointer
	return (NULL);	
}


int main()
{
	char	*s;

	s = "This is a random string with another rare word with ra";	

	puts("\n\n");

	//pointer to the first character of the first occurrence of needle is returned
	//when there is a match
	printf("%s -> |\"ra\"|  return from ft_strstr-> %s\n",s, ft_strstr(s, "ra"));
	printf("%s -> |\"ra\"|  return from    strstr-> %s\n",s , strstr(s, "ra"));
	puts("");
	//If needle occurs nowhere in haystack, NULLis returned;
	printf("%s -> |\"Ra\"|  return from ft_strstr-> %s\n",s, ft_strstr(s, "Ra"));
	printf("%s -> |\"Ra\"|  return from    strstr-> %s\n",s , strstr(s, "Ra"));
	puts("");
    //If needle is an empty string, haystack is returned;	
	printf("%s -> |\"\"|  return from ft_strstr-> %s\n",s, ft_strstr(s, ""));
	printf("%s -> |\"\"|  return from    strstr-> %s\n",s , strstr(s, ""));




}



