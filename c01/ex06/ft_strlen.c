/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:47:33 by Oceano            #+#    #+#             */
/*   Updated: 2022/11/15 18:45:04 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int		ft_strlen_rec(char *str)
{
	if (!*str)
		return (0);
	return ft_strlen_rec(str + 1) + 1;
}

int main()
{
	char	*s;

	s = "hi!";

	printf("%d\n", ft_strlen_rec(s));
}

