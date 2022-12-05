/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:28:32 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/05 11:36:21 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

/*
 * Sick ASCII website-> https://www.asciihex.com/ascii-control-characters🔥
 * Create a function that displays a string of characters onscreen. 
 * If this string contains characters that aren’t printable, 
 * they’ll have to be displayed in the shape of hexadecimals (lowercase), preceeded by a "backslash".
*/

//hexadecimals (lowercase), preceeded by a "backslash"
void	write_hex(char byte)
{
	char	c;

	//One \ acts as escape char
	write(1, "\\", 2);
	
	//Ternary operators...kinda neat here, 🚨Forbidden by norminette but not from real life code🚨
	c = (byte/16 > 9)? byte/16 + 87 : byte/16 + 48;
	write(1, &c, 1);
   	c = (byte%16 > 9)? byte%16 + 87 : byte%16 + 48;
	write(1, &c, 1);
	
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
	    //If the char is not_printable->go to ad hoc routine
		if ((*str >= 0 && *str < 32) || *str == 127)
			write_hex(*str); 
		//otherwise just write char and then add 1 to pointer
		else 
			write(1, str, 1);
		++str;
	}
}

int main()
{
	char	*s;

	s = "Coucou\n\v\tu vas bien ?";
	ft_putstr_non_printable(s);
}	
