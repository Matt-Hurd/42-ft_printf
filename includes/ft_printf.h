/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:27:59 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/26 19:55:08 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_conv
{
	char *conv;
	char *(*ft)(char *, int, va_list);
}				t_conv;

typedef struct		s_arg
{
	int				left_justify : 1; //'-'
	int				force_sign : 1; //'+'
	int				blank_sign : 1; //' '
	int				pad_zeroes : 1; //'0'
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum { //#
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}					t_arg;

char	*ft_conv_unimp(char *in, int len, va_list ap);

#endif
