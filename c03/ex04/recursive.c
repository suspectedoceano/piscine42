#include<stdio.h>
#include<string.h>

char	*ft_strstr(char *str, char *to_find)
{
	//Check my video on recursion if stuck
	// -> https://www.youtube.com/watch?v=4W6CTp1eBe0

	if (!*str)
		return NULL;
	else 
	{
		int i;

		i = 0;
		while (*to_find == *(str + i))
			to_find++, i++;

		//Or empty to_find
		//or all the chars match
		if (!*to_find)
			return str;

		return ft_strstr(str + 1, to_find);	
	}
}


int main()
{
	char	*s;

	s = "This is a random string ";	

	puts("\n\n");

	//pointer to the first character of the first occurrence of needle is returned
	//when there is a match
	printf("%s -> |\"ra\"|  return from ft_strstr-> %s\n",s, ft_strstr(s, "ra"));
	printf("%s -> |\"ra\"|  return from    strstr-> %s\n",s , strstr(s, "ra"));
	puts("");
	//If needle occurs nowhere in haystack, NULL is returned;
	printf("%s -> |\"Ra\"|  return from ft_strstr-> %s\n",s, ft_strstr(s, "Ra"));
	printf("%s -> |\"Ra\"|  return from    strstr-> %s\n",s , strstr(s, "Ra"));
	puts("");
    //If needle is an empty string, haystack is returned;	
	printf("%s -> |\"\"|  return from ft_strstr-> %s\n",s, ft_strstr(s, ""));
	printf("%s -> |\"\"|  return from    strstr-> %s\n",s , strstr(s, ""));	
}

