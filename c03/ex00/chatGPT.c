/*reproduce strcmp function in C with all cases in the main test*/

#include<stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int		main(void)
{
	char *s1;
	char *s2;

	s1 = "";
	s2 = "";
	printf("%d\n", ft_strcmp(s1, s2));
	s1 = "";
	s2 = "a";
	printf("%d\n", ft_strcmp(s1, s2));
	s1 = "a";
	s2 = "";
	printf("%d\n", ft_strcmp(s1, s2));
	s1 = "a";
	s2 = "a";
	printf("%d\n", ft_strcmp(s1, s2));
}
