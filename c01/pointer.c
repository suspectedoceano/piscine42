#include <stdio.h>

int main()
{
	int 	n;
	int 	*pn;

	n = 42;
	pn = &n;
	
	printf("0x%lx\n", pn);
	printf("%p\n", pn);

}	
