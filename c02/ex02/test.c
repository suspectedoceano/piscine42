#include<stdio.h>


int		ft_str_is_alpha(char *str)
{
	//Assume String not empty, Until  don't reach \0, keep going
	while (*str != '\0')
	{
		if ((*str >= 97 && *str <= 122) || (*str >= 65 && *str <= 90))
			++str; 
		else
			//Stumbled upon a non char
			return (0);
	}
	//Or the string is empty, or only alpha chars
	return (1);
}
int		ft_str_is_alphaPro(char *str)
{
	//Use directly the char pointed as a bool 💡
	while (*str)
	{	//This ! inverts the logic
		if ( ! ((*str >= 97 && *str <= 122) || (*str >= 65 && *str <= 90)))
			return (0);
		++str;
	}
	return (1);
}



int main()
{
	printf("%d\n", ft_str_is_alphaPro(""));	
	printf("%d\n", ft_str_is_alphaPro("hello"));	
	printf("%d\n", ft_str_is_alphaPro("he770"));	
}
