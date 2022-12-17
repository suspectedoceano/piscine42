#include <stdio.h>
#include <limits.h>

int main()
{
	int 	n = INT_MIN;

	printf("%d\n", n);

	n = ~n + 1;

	printf("%d\n", n);
	
}
