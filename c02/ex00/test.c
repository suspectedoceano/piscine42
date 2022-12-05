#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	//I use the char pointed as a boolean 💡
	while (*src)
		*(dest + i++) = *src++;
	
	//This line will handle both empty str and sentinel
	*(dest + i) = '\0';
	return (dest);
}
int main()
{
	char v[] = "////////";
	char v1[] = "";

	printf("%s\n", ft_strcpy(v, v1)); 
}
