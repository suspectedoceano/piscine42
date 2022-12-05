/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:48:02 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 17:52:26 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered as a parameter.
	If n is negative, display ’N’.
	If n is positive or null, display ’P’.
*/

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

int	main(void)
{
	ft_is_negative(-42);
	ft_is_negative(0);
	ft_is_negative(42);
}
