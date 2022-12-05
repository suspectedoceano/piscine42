/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:05:11 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/18 14:29:38 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	swap(int *n, int *n1);
void	ft_sort_int_tab(int *tab, int size);

int	main()
{
	int	v[1000];

	printf("\n----------\nBEFORE SORT\n----------\n");
	for (int i=0; i<1000; i++)
	{
		v[i] = rand()%1001-500; 
		printf("%d ", v[i]);
	}
	
	ft_sort_int_tab(v, 1000);
	
	printf("\n----------\nAFTER SORT\n----------\n");
	for (int i = 0; i<1000; i++)
		printf("%d ", v[i]);
	printf("\n\n\n");	
}

void	swap(int *n, int *n1)
{
	//One line xor swap 😍
	*n ^= *n1, *n1 ^= *n, *n ^= *n1;
}

void	ft_sort_int_tab(int *tab, int size)
{
// Take home ideas
//1) We can have different implementations of the same functions. 
//2) All of these implementations are INVISIBLE to the final user. He can see only the interface (pervasive idea in CS).
//3) The user care only about the "deal" that the function is gonna give back what promised. printf every time works, only ~0.001% knows the real code.
//4) Some implementations are better than others, that's why we study algorithms. 

///*
	//Bubble implementation
	int		j;

	for (int i=0; i<size-1; i++)
	{
		j = 0;
						//This -i, thx to bubbles 🧼
		while (j < size - 1 -i)
		{
			if (tab[j] > tab[j+1])
				swap(&tab[j], &tab[j+1]);
			j++;
		}
	}
//*/

/*	//Insertion sort
	int		k;
	int		j;

	for (int i = 0; i < size-1; i++)
	{
		k = i + 1;
		j = i;
		while (tab[j] > tab[k] && j>=0)
		{
			if (tab[j] > tab[k])
				swap(&tab[j], &tab[k]);
			--j;
			--k;
		}
	}
*/
	
/*	//Selection sort
	int		k;
	int 	min;

	for (int i=0; i<size-1; i++)
	{
		min = tab[i];
		k = i + 1;
		while (k < size)
		{	
			if (tab[k] < min)
				swap(&min, &tab[k]);
			++k;
		}
		if (min != tab[i])
			swap(&tab[i], &min);
	}
*/
}

