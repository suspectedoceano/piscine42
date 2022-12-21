/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:56:19 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/21 14:08:51 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		sqr(int n)
{
	if (n < 0)
		return -1;

	int		k;

	k = 0;
	while (k * k <= n)
		k++;
	return --k;
}

int		ft_is_prime(int nb)
{
	int		i;
	int 	square;

	i = 2;
	square = sqr(nb);
	if (nb < 2)
		return 0;
	//Every number is Composite or Prime. Composite means, u can derive it "factoring(multipling)" primes.
	//If composite, there must be at least 1 factor less then √n..From number theory.
	//so...check is done in range [2..√n]
	while (i <= square)//TODO
		if (!(nb % i++))
			return 0;
	//If nothing divides neatly in the range, not a composite number. Yeah...a Prime.
	return 1;

	//TL;DR
	//Numbers are like Molecules. 
	//Molecules(composite Numbers) are made up of atoms, you can find these atmos(factors) in the range [2..√n].
	//
	//	->Let's decompose 30...Factors combo : 1x30, 2x15, 3x10, 5x6, 10x3, 15x2, 30x1. √30=5.48~
	//
	//	30|2
	//	15|3
	//	 5|5	2,3 and 5 divide neatly 30
	//	 1| 
	//I can always find a factor which is minor √n. In this case i find in every combo an n < √5.
	//Finding a factor, means findig an atom. Somenthing that neatly fit into the molecule_number. 
	//If no atoms there in range, you stumbled upon a big danr Atom_Prime.
}

int main()
{
	for(long i=0; i<100; ++i)
		if (ft_is_prime(i))printf("\n%ld ", i);
}
