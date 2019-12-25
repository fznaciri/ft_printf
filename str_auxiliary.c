/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_auxiliary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:50:24 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/12/25 22:11:54 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *s, int size)
{
	int i;

	i = 0;
	while (size && s[i])
	{
		ft_putchar(s[i]);
		i++;
		size--;
	}
	return (i);
}

int		print_s(int n)
{
	int temp;

	temp = n;
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
	return (temp <= 0 ? 0 : temp);
}

int		print_z(int n, int is_neg)
{
	int temp;

	temp = n;
	if (is_neg)
		write(1, "-", 1);
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
	return (temp <= 0 ? 0 : temp);
}

int		is_point(char *s)
{
	int i;

	i = 0;
	while (!IS_FORMAT(s[i]) && s[i] != '.')
		i++;
	return (s[i] == '.' ? 1 : 0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
