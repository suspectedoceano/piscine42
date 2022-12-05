#include <stdio.h>
#include <string.h>

int main()
{
	//An empty string has size 1
	char	v[] = "";
	printf("Size-> %lu\n", sizeof(v));
	printf("Len-> %lu\n", strlen(v));
}	
