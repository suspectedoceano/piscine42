/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:14:29 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/21 13:39:13 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//Create a function that returns the next prime number greater or equal to the number given as argument.

int		ft_find_next_prime(int nb);
int		ft_sqrt_trunc(int nb);
int		ft_is_prime(int nb);


int main()
{
	for(int i = 0; i < 1000; i++) 
		if (ft_is_prime(i))printf("The next prime of %d is %d\n",i, ft_find_next_prime(i));
}

int		ft_find_next_prime(int nb)
{
//					RUSSEL congecture
//       "Chebyshev said it and i'll say it again,
//    there is ALWAYS a prima number between n and 2n"
	//💡 0 and 1 are not primes 💡
	if (nb < 2)
		return (2);
	int		k;

	k = nb * 2;
	while (++nb < k)
		if (ft_is_prime(nb))
			return (nb);
	return (-1); //Cannot never reach this return. Otherwise Russel disproved ;).
}

int		ft_sqrt_floor(int nb)
{
	int		i;

	i = 0;
    //This = in the logic is important	 
	while ((i * i) <= nb)
		++i;
	return (--i);
}

int		ft_is_prime(int nb)
{
	//Integers divide into COMPOSITE or PRIMES
	//COMPOSITEs can be derived from multiplications of PRIMEs (Prime Factorization)
	//At least 1 Factor (one building block) has to be <= √n (floor)
	//To get 81 the max factors are 9x9...can u add to both with no overflowing 81?
	//To check if n is COMPOSITE i divide it with range [2..√n]
	//A neat division tells me n is composed, deducing if prime or not.
	
	if (nb < 2)			//Prime divide only by 1 and itself
		return (0);		//0 and 1 are not prime by exercise

	int		sqr;
	int		primeFactor;

	sqr = ft_sqrt_floor(nb);	
	primeFactor = 2;
	while (primeFactor <= sqr)
		if (!(nb % primeFactor++)) //If there is a neat division (no remainder)
			return (0);  //This is a composite number, j is a factor
	return (1); //Checked all the potential FACTORS, Here's a PRIME
}


