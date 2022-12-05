#include <stdio.h>
#include <string.h>

int main()
{
	//size is not len
	char 	v[] = "";
	printf("%lu\n", sizeof(v));
	printf("%lu\n", strlen(v));

}
