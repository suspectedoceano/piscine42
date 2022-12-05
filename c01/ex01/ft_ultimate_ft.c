/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:51:08 by Oceano            #+#    #+#             */
/*  * Updated: 2022/11/05 10:14:20 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <stdio.h>

void    ft_ultimate_ft(int *********nbr)
{
    *********nbr=42;
}

int main()
{
	int 	n;
	int		*pn1, **pn2, ***pn3, ****pn4, *****pn5, ******pn6, *******pn7, ********pn8, *********pn9;

	pn9 = &pn8;
	pn8 = &pn7;
	pn7 = &pn6;
	pn6 = &pn5;
	pn5 = &pn4;
	pn4 = &pn3;
	pn3 = &pn2;
	pn2 = &pn1;
	pn1 = &n;


	n = 21;
	printf("\nBefore the function ft_ultimate the value was %d\n", n);
	ft_ultimate_ft(pn9);
	printf("\nAfter the function now is %d\n\n", n);

	//THEORY PART
	printf("\n------------\nPOINTER ARITHMETIC\n------------\n");
	
	printf("Given a pointer to a specific data type, what happens if add to it a value 'n'?\n\n");

	printf("These pointers are in decimal, easier to see the increment\n\n");
	for (int i=0; i<10; ++i)
		printf("int pointer %10ld + %d-> %10ld\n"
				"This is like saying %d*sizeof(int)\n\n", (unsigned long)pn1, i, (unsigned long)(pn1+i), i);
	printf("\n\n");
		

	for(int i=0; i<10; ++i)printf("long pointer %10p + %d-> %10p\n", pn1, i, (long *)pn1+i);
	printf("\n\n");
	for(int i=0; i<10; ++i)printf("char pointer %10p + %d-> %10p\n", pn1, i, (char *)pn1+i);

}

