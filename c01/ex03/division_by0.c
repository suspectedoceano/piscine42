#include <stdio.h>


int main()
{

	int i = 42;
	//Undefined behavior
	printf("%d\n", i/0);

	//Legal
	printf("%d\n", 0/42);
}
