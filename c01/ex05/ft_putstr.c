/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:31:45 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/09 15:23:41 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr_rec(char *str)
{
	//Recursive version
	write(1, str, 1);
	if (*str)
		ft_putstr_rec(str+1);
}

int main()
{
	char	*s;

	s = "hi!";
	ft_putstr_rec(s);
}
