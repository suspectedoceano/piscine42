#include <stdio.h>


int 	ft_square(int nb)
{
	int		probeNbr;
	
	probeNbr = 1;
	while ((probeNbr * probeNbr) <= nb)
		probeNbr++;

	//Floor sqrt
	return --probeNbr;
}

int		helper(int nb, int factor)
{
	int 	limit;

	limit = ft_square(nb);
	//0 and 1 are not primes for this ex
	if (0 == nb || 1 == nb)
		return 0;
	//If even, fo sure not a prime
	else if (!(nb % 2) && nb != 2)
		return 0;
	//check till [2..√nb]
	//if i pass all these chacks, prime
	else if (factor > limit)
		return 1;
	//if neat division, not a prime
	//return the factor i wanna see
	else if (!(nb % factor))
		return factor;
	return helper(nb, factor + 1);

}

int		ft_isprimeRec(int nb)
{
	return helper(nb, 2);
}

int main()
{
	for (int i = 0; i < 1000; ++i)
	{
		if (ft_isprimeRec(i) == 1) 
			printf("The num %i is prime\n", i);
		if (ft_isprimeRec(i) > 1) 
			printf("You can divide %i per %i\n", i, ft_isprimeRec(i));
	}

}
