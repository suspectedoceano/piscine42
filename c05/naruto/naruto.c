#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int		naruto(char *money)
{
	if (money[0] == '\0')
		return 0;
	else
		return naruto(money + 1) + 1;
}	

int		sasuke(char money[])
{
	int		counter;

	counter = 0;
	while (money[counter] != '\0') 
	{
		counter++;
	}
	return counter;
}

int main()
{
	char	*bucket;

	bucket = "$$$$$$\0";
	printf("%d\n", 	naruto(bucket));
	printf("%d\n", 	sasuke(bucket));
}

