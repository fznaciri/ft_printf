/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:13:14 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/12/25 22:35:58 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ncount(int n)
{
	int i;

	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	i = 0;
	n = (n < 0 ? -n : n);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int				uncount(unsigned int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

unsigned int	ft_putunbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n < 10)
		ft_putchar(n % 10 + '0');
	return (n);
}

void			hex(unsigned int number, char font, int *size, char aff)
{
	char	s[9];
	int		i;

	i = 0;
	while (number >= 16)
	{
		if ((number % 16) < 10)
			s[i] = (number % 16) + '0';
		else
			s[i] = (number % 16) - 10 + (font == 1 ? 'A' : 'a');
		number /= 16;
		i++;
	}
	if (number < 10)
		s[i] = number + '0';
	else
		s[i] = number - 10 + (font == 1 ? 'A' : 'a');
	*size = i + 1;
	if (aff)
		while (i >= 0)
			ft_putchar(s[i--]);
}

void			hex8(unsigned long number, int *size, char aff)
{
	char	s[20];
	int		i;

	i = 0;
	while (number >= 16)
	{
		if ((number % 16) < 10)
			s[i] = (number % 16) + '0';
		else
			s[i] = (number % 16) - 10 + 'a';
		number /= 16;
		i++;
	}
	if (number < 10)
		s[i] = number + '0';
	else
		s[i] = number - 10 + 'a';
	*size = i + 1;
	if (aff)
		while (i >= 0)
			ft_putchar(s[i--]);
}
