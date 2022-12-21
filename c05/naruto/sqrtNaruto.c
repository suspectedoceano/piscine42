#include<stdio.h>

//Iteratively much better

int		sqrtNaruto(int nb, int factor)
{
	if (factor * factor == nb)
		return factor;
	else if (factor * factor > nb)
		return 0;
	return sqrtNaruto(nb, factor + 1);
}


int		ft_sqrt(int nb)
{
	return sqrtNaruto(nb, 0);
}


int main()
{
	for(int i=0; i<1000001; ++i)
	{
		if (ft_sqrt(i))
		printf("The sqrRoute of %d-> %d\n\n", i, ft_sqrt(i));
	}
}
