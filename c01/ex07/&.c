#include <stdio.h>

void	address(int *array)
{
	printf("\n%p\n\n", array);
		
}


int main()
{
	int		v[10];

	for (int i=0; i<10; i++)v[i]=i;

	printf("\n\n%p\n\n", &v);
	address(v);
}
