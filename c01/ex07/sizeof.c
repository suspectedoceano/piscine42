#include<stdio.h>


void	size(int *array)
{
	printf("From function->%lu\n\n", sizeof(array));
}


int main()
{
	int 	v[10];

	//Fill array
	for(int i=0; i<10; i++)v[i]=i;

	printf("\nSizeof from main->%lu\n\n", sizeof(v));

	size(v);
}
