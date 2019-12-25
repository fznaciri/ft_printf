/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:57:51 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/12/25 22:26:34 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset(void)
{
	g_f.nz = 0;
	g_f.ns = 0;
	g_f.z = 0;
	g_f.s = 0;
	g_f.p = 0;
	g_f.l = 0;
}

void	p_detect(char *s, va_list *st)
{
	int i;

	i = 0;
	while (!IS_FORMAT(s[i]) && s[i] != '.')
		i++;
	if (s[i] == '.')
	{
		if (s[i + 1] != '*')
			g_f.p = ft_atoi(s + i + 1);
		else
			g_f.p = va_arg(*st, int);
	}
}

void	z_detect(char *s, va_list *st)
{
	int i;

	i = 0;
	if (s[0] == '0')
	{
		if (s[1] != '*')
			g_f.z = ft_atoi(s + 1);
		else
			g_f.z = va_arg(*st, int);
	}
}

void	s_detect(char *s, va_list *st)
{
	int i;
	int j;

	i = 1;
	if (s[0] == '*')
		g_f.s = va_arg(*st, int);
	else if (s[0] == '-')
	{
		while (s[i] == '-')
			i++;
		if (s[i] == '*' && s[i - 1] == '-')
		{
			j = va_arg(*st, int);
			g_f.s = ABS(j) * -1;
		}
		else if (s[i] == '*' && s[i - 1] != '-')
			g_f.s = va_arg(*st, int);
		else
			g_f.s = ft_atoi(s + i - 1);
	}
	else
		g_f.s = ft_atoi(s);
}

void	flags(char *s, int is_neg, int is_p)
{
	if (s[1] == '0' && is_point(s + 1) && g_f.p < 0 && g_f.z < 0)
		g_f.ns = g_f.z;
	else if (is_point(s + 1) && g_f.p >= 0 && s[1] != '0')
		g_f.ns = g_f.s;
	else if (s[1] == '0' && is_point(s + 1) && g_f.p >= 0)
		g_f.ns = g_f.z;
	else if (s[1] != '0')
		g_f.ns = g_f.s;
	else if (s[1] == '0' && !is_point(s + 1) && g_f.z < 0)
		g_f.ns = g_f.z;
	if (is_point(s + 1) && g_f.p > 0)
		g_f.nz = g_f.p;
	else if (is_point(s + 1) && g_f.p < 0 && g_f.z >= 0)
		g_f.nz = g_f.z - is_neg - (is_p ? 2 : 0);
	else if (!is_point(s + 1) && s[1] == '0' && g_f.z >= 0)
		g_f.nz = g_f.z - is_neg - (is_p ? 2 : 0);
}
