/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 21:24:22 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/12/25 22:19:08 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_int(char *s, va_list *st)
{
	int n;
	int cd;

	reset();
	z_detect(s + 1, st);
	s_detect(s + 1, st);
	p_detect(s + 1, st);
	n = va_arg(*st, int);
	g_f.l = ncount(n);
	cd = !(!is_point(s + 1) || g_f.p != 0 || n != 0);
	flags(s, NEG(n), 0);
	if (g_f.ns >= 0)
		g_f.np += print_s(g_f.ns - MAX(g_f.nz, g_f.l) - NEG(n) + cd);
	g_f.np += print_z(g_f.nz - g_f.l, NEG(n));
	if (!is_point(s + 1) || g_f.p != 0 || n != 0)
		ft_putnbr_fd(ABS(n), 1);
	else
		g_f.np -= 1;
	if (g_f.ns < 0)
		g_f.np += print_s(ABS(g_f.ns) - MAX(g_f.nz, g_f.l) - NEG(n) + cd);
	return (g_f.l + NEG(n));
}

int		print_pointer(char *s, va_list *st)
{
	unsigned long	n;
	int				size;
	int				cd;

	reset();
	z_detect(s + 1, st);
	s_detect(s + 1, st);
	p_detect(s + 1, st);
	n = va_arg(*st, unsigned long);
	hex8(n, &size, 0);
	cd = !(!is_point(s + 1) || g_f.p != 0 || n != 0);
	g_f.np += 2;
	flags(s, 0, 1);
	if (g_f.ns >= 0)
		g_f.np += print_s(g_f.ns - MAX(g_f.nz, size + 2) + cd);
	write(1, "0x", 2);
	g_f.np += print_z(g_f.nz - size, 0);
	if (!is_point(s + 1) || g_f.p != 0 || n)
		hex8(n, &size, 1);
	else
		g_f.np--;
	if (g_f.ns < 0)
		g_f.np += print_s(ABS(g_f.ns) - MAX(g_f.nz, size + 2) + cd);
	return (size);
}

int		print_hex(char *s, va_list *st, char font)
{
	unsigned int	n;
	int				size;
	int				cd;

	reset();
	z_detect(s + 1, st);
	s_detect(s + 1, st);
	p_detect(s + 1, st);
	n = va_arg(*st, unsigned int);
	hex(n, 0, &size, 0);
	cd = !(!is_point(s + 1) || g_f.p != 0 || n != 0);
	flags(s, 0, 0);
	if (g_f.ns >= 0)
		g_f.np += print_s(g_f.ns - MAX(g_f.nz, size) + cd);
	g_f.np += print_z(g_f.nz - size, 0);
	if (!is_point(s + 1) || g_f.p != 0 || n != 0)
		hex(n, font, &size, 1);
	else
		g_f.np--;
	if (g_f.ns < 0)
		g_f.np += print_s(ABS(g_f.ns) - MAX(g_f.nz, size) + cd);
	return (size);
}

int		print_uint(char *s, va_list *st)
{
	unsigned int	n;
	int				cd;

	reset();
	z_detect(s + 1, st);
	s_detect(s + 1, st);
	p_detect(s + 1, st);
	n = va_arg(*st, unsigned int);
	g_f.l = uncount(n);
	cd = !(!is_point(s + 1) || g_f.p != 0 || n != 0);
	flags(s, 0, 0);
	if (g_f.ns >= 0)
		g_f.np += print_s(g_f.ns - MAX(g_f.nz, g_f.l) + cd);
	g_f.np += print_z(g_f.nz - g_f.l, 0);
	if (!is_point(s + 1) || g_f.p != 0 || n != 0)
		ft_putunbr(n);
	else
		g_f.np--;
	if (g_f.ns < 0)
		g_f.np += print_s(ABS(g_f.ns) - MAX(g_f.nz, g_f.l) + cd);
	return (g_f.l);
}
