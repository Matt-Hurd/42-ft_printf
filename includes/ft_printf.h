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
}					t_arg;

typedef struct	s_conv
{
	char *conv;
	char *(*ft)(char, t_arg *, va_list);
}				t_conv;

char	*ft_conv_unimp(char in, t_arg *flags, va_list ap);
t_arg	*find_flags(char *in, int len);
void	ft_printf(char *in, ...);

#endif
