/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 21:32:47 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/12/25 22:43:28 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char *s, va_list *st)
{
	char c;

	reset();
	z_detect(s + 1, st);
	s_detect(s + 1, st);
	c = va_arg(*st, int);
	g_f.ns = g_f.s;
	if (g_f.ns >= 0)
		g_f.np += print_s(g_f.ns - g_f.nz - 1);
	g_f.np += print_z(g_f.nz - 1, 0);
	ft_putchar(c);
	if (g_f.ns < 0)
		g_f.np += print_s(ABS(g_f.ns) - g_f.nz - 1);
	return (1);
}

int		print_string(char *s, va_list *st)
{
	char	*str;
	int		precision;

	reset();
	s_detect(s + 1, st);
	p_detect(s + 1, st);
	str = va_arg(*st, char *);
	if (!str)
		str = "(null)";
	g_f.l = (int)ft_strlen(str);
	precision = g_f.l;
	g_f.ns = g_f.s;
	if (is_point(s + 1) && (g_f.p < 0 || g_f.p >= g_f.l))
		precision = g_f.l;
	else if (is_point(s + 1) && g_f.p >= 0)
		precision = g_f.p;
	if (g_f.ns >= 0)
		g_f.np += print_s(g_f.ns - precision);
	g_f.np += ft_putstr(str, precision);
	if (g_f.ns < 0)
		g_f.np += print_s(ABS(g_f.ns) - precision);
	return (0);
}

int		print_percent(char *s, va_list *st)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 1;
	reset();
	if ((k = skip_zm(&s, &i)))
		j = -1;
	z_detect(s + i, st);
	s_detect(s + i, st);
	p_detect(s + i, st);
	if (s[i] == '0' && g_f.z < 0)
		g_f.ns = (k ? ABS(g_f.z) * j : g_f.z);
	else if (s[i] != '0')
		g_f.ns = (k ? ABS(g_f.s) * j : g_f.s);
	if (s[i] == '0' && g_f.z >= 0)
		g_f.nz = g_f.z;
	if (g_f.ns >= 0)
		g_f.np += print_s(g_f.ns - (MAX(g_f.nz, 1)));
	g_f.np += print_z(g_f.nz - 1, 0);
	ft_putchar('%');
	if (g_f.ns < 0)
		g_f.np += print_s(ABS(g_f.ns) - (MAX(g_f.nz, 1)));
	return (1);
}

int		skip_zm(char **s, int *j)
{
	int i;
	int z;
	int m;

	z = 0;
	m = 0;
	i = 1;
	while (*(*s + i) == '0' || *(*s + i) == '-')
	{
		if (*(*s + i) == '0')
			z = 1;
		else if (*(*s + i) == '-')
			m = 1;
		i++;
	}
	if (z && m)
		*j = i;
	return (z && m ? 1 : 0);
}
