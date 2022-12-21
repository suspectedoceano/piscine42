#include <stdio.h>


int fibNarutoOffset(int nb)
{
	if (nb == 1 || nb == 2)
		return 1;
	else if (nb == 3)
		return 2;
	return fibNarutoOffset(nb - 3) + 42;

}

int main()
{
	for (int i=1; i<21; ++i)
	printf("%d\n", fibNarutoOffset(i));
}
