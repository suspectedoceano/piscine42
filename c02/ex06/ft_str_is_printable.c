#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


int		ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 32 && *str != 127)
			++str; 
		else
			return (0);
	}
	return (1);
}


int		ft_str_is_printablePro(char *str)
{
	while (*str)
	{	
		if ((*str >= 0 && *str <= 32) || *str == 127)
			return (0);
		++str;
	}
	return (1);
}

int		main()
{
	char			str[2000];
	int 			j;
	unsigned char	c;
	
	while (1)
	{
		j = 0;
		//Check random, with all 127 chars
		while ((c = rand()%129) != 128)
			str[j++] = c;
		str[j] = 0;

		printf("%s-> %s\n\n\n",
				str, 
				(ft_str_is_printablePro(str)) ? 
				"This string contains only printable chars, or the string is empty" :
			   	"Also non printable chars");

		if (ft_str_is_printablePro(str) && (strlen(str) > 3)) break;
	}	
}

