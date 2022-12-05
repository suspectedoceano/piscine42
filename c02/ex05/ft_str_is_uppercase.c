#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


int		ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 65 && *str <= 90)
			++str; 
		else
			return (0);
	}
	return (1);
}


int		ft_str_is_uppercasePro(char *str)
{
	while (*str)
	{
		if (!(*str >= 65 && *str <= 90))
			return (0);
		++str;
	}
	return (1);
}

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
				(ft_str_is_uppercase(str)) ? 
				"This string contains only UPPER chars, or the string is empty" : 
				"Also non UPPER chars");

		if (ft_str_is_uppercase(str) && (strlen(str) > 5)) break;
	}	
}

