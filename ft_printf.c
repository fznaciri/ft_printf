/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:49:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/12/25 22:09:17 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	g_f;

int		ft_printf(const char *s, ...)
{
	int		k;
	va_list	st;

	va_start(st, s);
	k = 0;
	g_f.np = 0;
	while (s[k])
	{
		if (s[k] != '%')
		{
			write(1, s + k, 1);
			++g_f.np;
			k++;
		}
		else if (s[k] == '%')
		{
			print_format(&st, format_finder((char *)s + k), (char *)s + k);
			k += skip((char *)s + k + 1) + 1;
		}
	}
	va_end(st);
	return (g_f.np);
}

void	print_format(va_list *st, char format, char *s)
{
	if (format == 'i' || format == 'd')
		g_f.np += print_int(s, st);
	else if (format == 'c')
		g_f.np += print_char(s, st);
	else if (format == 's')
		g_f.np += print_string(s, st);
	else if (format == 'u')
		g_f.np += print_uint(s, st);
	else if (format == 'x' || format == 'X')
		g_f.np += print_hex(s, st, format == 'x' ? 0 : 1);
	else if (format == 'p')
		g_f.np += print_pointer(s, st);
	else if (format == '%')
		g_f.np += print_percent(s, st);
}

char	format_finder(char *s)
{
	int i;

	i = 1;
	while (!IS_FORMAT(s[i]) && (IS_FLAG(s[i]) || ft_isdigit(s[i])))
		i++;
	return (s[i]);
}

int		skip(char *s)
{
	int i;

	i = 0;
	while (IS_FLAG(s[i]) || ft_isdigit(s[i]))
		i++;
	return (i + 1);
}
