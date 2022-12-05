/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:14:51 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 18:24:06 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The first combination has all digits set to their minimum value, starting at 0 for the leftmost digit.
For four digits:
0123
The last combination has all digits set to their maximum value, starting at 10 - N for an N digit number.
For four digits:
6789
The combinations inbetween are found by "incrementing" the previous combination. 
This involves a search from right to left looking for the rightmost digit that is not at its maximum value. 
For example, if the current combination for 4 digits is:
0589
 ^ this is the rightmost digit that can be incremented
Form the next combination by incrementing that digit and setting all digits to its right 
to one more than the previous digit:
0678
 ^ this is the first changed digit, the digits to the right are set sequentially
*/

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_array(char v[], int size, int last)
{
	int		i;

	i = 0;
	if (v[0] == last)
	{
		while (i < size)
			ft_putchar(v[i++]);
		write(1, ".\n", 2);
		return ;
	}
	while (i < size)
		ft_putchar(v[i++]);
	write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	v[10];
	char	v_max[10];
	int		flag;
	int		base;

	if (n <= 0 || n > 10)
	{
		write(1, "Insert an 0<n<10\n", 17);
		return ;
	}

	for (int i=0; i<n; ++i)
	{
		v[i] = i + 48;
		// I create both initial and final STATES that i wanna reach.
		// USE A WHILE HERE for Norminette
		v_max[i] = (10 - n) + i + 48;
	}		
	
	//Routine to print the checked vector
	print_array(v, n, v_max[0]);	
			
	//When v[0] has its max value i know i'm done, cause this is FORCEFULLY the last config possible 
	while (v[0] != v_max[0])
	{
		//Find position of int that should be increased
		//We assume initially it is in last position for every iteration
		flag = n-1;
		while (v[flag] == v_max[flag])
			--flag;
		base = ++(v[flag]);
		//Set following numbers properly
		while (flag < n-1)
			v[++flag] = ++base;
		print_array(v, n, v_max[0]);
	}
}

int		main(void)
{	

	ft_print_combn(0);
	write(1, "\nCOMBO 1\n", 9);
	ft_print_combn(1);
	write(1, "\nCOMBO 2\n", 9);
	ft_print_combn(2);
	write(1, "\nCOMBO 3\n", 9);
	ft_print_combn(3);
	write(1, "\nCOMBO 4\n", 9);	
	ft_print_combn(4);
	write(1, "\nCOMBO 5\n", 9);
	ft_print_combn(5);
	write(1, "\nCOMBO 6\n", 9);
	ft_print_combn(6);
	write(1, "\nCOMBO 7\n", 9);
	ft_print_combn(7);
	write(1, "\nCOMBO 8\n", 9);
	ft_print_combn(8);
	write(1, "\nCOMBO 9\n", 9);
	ft_print_combn(9);
	write(1, "\nFINAL 'UNNECESSARY' COMBO\n", 27);
	ft_print_combn(10);
}
