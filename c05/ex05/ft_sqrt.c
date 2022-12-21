/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:52:33 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/19 13:16:06 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

//Create a function that returns the square root of a number (if it exists),
//or 0 if the square root is an irrational number.


//ITERATION is the best here imo
int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	
	//Negatives cannot have a sqrt
	if (nb < 0)
		return 0;

	//Iteratively search
	while ((i * i) <= nb)
	{
		if ((i * i) == nb)
			return (i);
		++i;
	}
	return (0);
}



//RECURSION with 2 functions. Kinda meh..
int		helperFunction(int nb, int tryValue)
{
	if ((tryValue * tryValue) > nb)
		return 0;
	else if ((tryValue * tryValue) == nb)
		return tryValue;
	return helperFunction(nb, tryValue + 1);
}

int 	ft_sqrtRec(int nb)
{
	if (nb < 0)
		return 0;
	return helperFunction(nb, 1); 
}



int main()
{
	int		sqr;

	for (int i = -10; i <= 1000; ++i) 
	{
		sqr = ft_sqrtRec(i);
		if ( ! sqr && i <= 0)
		{
			if (0 == i)
				printf("The sqrt of 0 is 0");
			else 
				printf("There is no sqrt for negatives like %i\n", i);
		}
		else if (sqr)	
			printf("\n\n\t\tThe sqrt of %d is %d\n"
					"\t\tFrom the original sqrt %.0f\n\n\n", i, sqr, sqrt(i));
		else 
			printf("The sqrt of %d is irrational"
					"-> %f\n", i, sqrt(i)); 
	}
}
