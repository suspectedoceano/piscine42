#include <stdio.h>

// xor swap 🎩

int main()
{	
	int 	cripto, nb, nb1;

	nb = 42;
	nb1 = 20;
	cripto = nb ^ nb1;
	printf("%d %d\n", cripto ^ nb, cripto ^ nb1);
}	
