#include <stdio.h>


int main()
{
	int		v[10];

	//Fill array
	for (int i=0; i<10; i++)v[i]=i;

	//Easy to read 
	printf("%d\n", v[3]);

	//What really happens
	printf("%d\n", *(v+3));
	
	//              WTF
	printf("%d\n", *(3+v));	

}
