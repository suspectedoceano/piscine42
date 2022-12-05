/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:35:57 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/05 11:31:43 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Create a function that capitalizes the first letter of each word and transforms all other letters to lowercase.
//A word is a string of alphanumeric characters.
//salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un
//Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	short	i;

	i = 0;
	while (str[i])
	{
		//Until you don't find an alpha thing, UPPER{65..90} or LOWER{97..122}, keep going on. The '!' is crucial for the logic 
		while ( ! ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) )	
			++i;

		//The first char is an alpha
		if (0 == i)
		{
			if (str[i] >= 97 && str[i] <= 122 )
				str[i] -= 32;
			++i;
			continue; //Restart the cycle
		}

		//Here i have a char, UP or LOW.. (char-1) what is that motherfucker?
		//If it is a space{9..13 || 32} or every other symbol{~..$}, Capitalize it
		if ((str[i-1] >= 9 && str[i-1] <= 13) || 
		   (str[i-1] >= 32 && str[i-1] <= 47) || 
		   (str[i-1] >= 59 && str[i-1] <= 64) ||  //All the culprits 
		   (str[i-1] >= 91 && str[i-1]<= 96)  ||  //i'm searching 👀
		   (str[i-1] >= 123 && str[i-1]<= 127))
		{
			//The char is also lowercase? make it UP	
		   if (str[i] >= 97 &&  str[i]<= 122)
				   str[i] -= 32;
		   ++i;
		}

		//are some "saLUTmOiMadmoiseLLe" strange words with post UPPERCASES there?	
		//Make a normal format string
		//Here we are inside a word
		while ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{ 
			if ((str[i] >= 65 && str[i] <= 90))
				str[i++] += 32;
			else
				++i;
		}
	}
	return (str);
}	


int		main()
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	str1[] = "s  ALUT, commENt tu vas madM\tIseLLe ? 42mots quAr\vante-deux; cinquante+et+un";
	char 	*correct= "Correct str\n"
					  "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\n"
				      "Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un\n";

	puts(correct);
	puts("\n\n");
	puts(str);
	puts(ft_strcapitalize(str));		
	puts("\n\n");
	puts(str1);
	puts(ft_strcapitalize(str1));		
}
