#include <stdio.h>

int		fibNaruto(int nb)
{
	if (nb == 1 || nb == 2)
		return 1;
	else if (nb == 3)
		return 33;
	else 
		return fibNaruto(nb - 1) + fibNaruto(nb - 2) + fibNaruto(nb - 3);

}




int main()
{
	for (int i=1; i<31; i++)
		printf("%d\n", fibNaruto(i));
}
