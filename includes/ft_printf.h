/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:27:59 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/06 17:09:39 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

# define SIZET_MAX (~(size_t)0)



#include <stdio.h>

typedef unsigned int u32;

enum { //length
		none,
		hh,
		h,
		l,
		ll,
		L,
		q,
		j,
		z,
		t
	}				length;

typedef struct		s_arg
{
	int				alternative : 1; //'#'
	int				left_justify : 1; //'-'
	int				force_sign : 1; //'+'
	int				blank_sign : 1; //' '
	int				pad_zeroes : 1; //'0'
	int				grouping : 1; //'
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	char			length;
}					t_arg;

typedef struct	s_output
{
	char	*str;
	int		len;
}				t_output;

typedef struct	s_conv
{
	char	*conv;
	void	(*ft)(char, t_output *, t_arg *, va_list *);
}				t_conv;

void	ft_conv_unimp(char in, t_output *out, t_arg *flags, va_list *ap);
void	ft_conv_s(char in,  t_output *out, t_arg *flags, va_list *ap);
void	ft_conv_nums(char in, t_output *out, t_arg *flags, va_list *ap);
t_arg	*find_flags(char *in, int len);
int		ft_printf(char *in, ...);

void	handle_padding(char **str, t_arg *flags);
void	handle_precision(char **str, t_arg *flags, char type);
void	ft_conv_c(char in, t_output *out, t_arg *flags, va_list *ap);
char	*ft_num_to_base(uintmax_t value, u32 base, char unsign, char type);

#endif
