/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:49:58 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/12/25 22:27:23 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define ABS(x) (x < 0 ? -x : x)
# define IS(c) (c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x')
# define IS_2(c) (c == 'c' || c == 's' || c == 'X' || c == '%')
# define IS_FORMAT(c) (IS(c) || IS_2(c) ? 1 : 0)
# define IS_FLAG(c) (c == '0' || c == '.' || c == '*' || c == '-' ? 1 : 0)
# define MAX(x,y) (x >= y ? x : y)
# define NEG(x) (x < 0 ? 1 : 0)

typedef struct	s_flags {
	int		z;
	int		p;
	int		s;
	int		ns;
	int		nz;
	int		l;
	int		np;
}				t_flags;

extern			t_flags g_f;
void			p_detect(char *s, va_list *st);
void			z_detect(char *s, va_list *st);
void			s_detect(char *s, va_list *st);
void			flags(char *s, int is_neg, int is_p);
void			reset(void);
int				ft_printf(const char *s, ...);
char			format_finder(char *s);
void			print_format(va_list *st, char format, char *s);
int				skip(char *s);
int				print_int(char *s, va_list *st);
int				print_uint(char *s, va_list *st);
int				print_hex(char *s, va_list *st, char font);
int				print_pointer(char *s, va_list *st);
unsigned int	ft_putunbr(unsigned int n);
int				uncount(unsigned int n);
void			hex8(unsigned long number, int *size, char aff);
int				ncount(int n);
void			hex(unsigned int number, char font, int *size, char aff);
int				print_char(char *s, va_list *st);
int				print_string(char *s, va_list *st);
int				print_percent(char *s, va_list *st);
int				skip_zm(char **s, int *j);
int				print_s(int n);
int				print_z(int n, int is_neg);
int				is_point(char *s);
void			ft_putchar(char c);
int				ft_putstr(char *s, int size);
#endif
