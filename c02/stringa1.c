#include <stdio.h>


int main()
{
	char str[] = "hello";

	printf("%s\n", str);

	//legal
	str[2] = 'k';


	printf("%s\n", str);
}
