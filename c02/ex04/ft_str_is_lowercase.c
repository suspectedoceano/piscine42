#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


int		ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 97 && *str <= 122)
			++str; 
		else
			return (0);
	}
	return (1);
}

///*
int		ft_str_is_lowercasePro(char *str)
{
	//Use directly the char pointed as a bool 💡
	while (*str)
	{	//This ! inverts the logic
		if (!(*str >= 97 && *str <= 122))
			return (0);
		++str;
	}
	return (1);
}
//*/

int		main()
{
	char	str[2000];
	int 	j;
	char	c;
	
	while (1)
	{
		j = 0;

		while ((c = rand()%95+33) != 127)
			str[j++] = c;
		str[j] = 0;

		printf("%s -> %s\n\n\n",
				str, 
				(ft_str_is_lowercase(str)) ? 
				"This string contains only lower chars, or is empty" : 
				"Also non lowe chars");

		if (ft_str_is_lowercase(str) && (strlen(str) > 7)) break;
	}	
}

