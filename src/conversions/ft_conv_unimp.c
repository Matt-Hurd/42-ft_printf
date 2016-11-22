/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unimp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 19:17:17 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/06 17:22:44 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"





#include <stdio.h>






char	*ft_conv_unimp(char in, t_arg *flags, va_list ap)
{
	(void)ap;
	printf("Flag info for conversion %c:\n", in);
	printf("Alternative: %d\n", flags->alternative);
	printf("left_justify: %d\n", flags->left_justify);
	printf("force_sign: %d\n", flags->force_sign);
	printf("blank_sign: %d\n", flags->blank_sign);
	printf("pad_zeroes: %d\n", flags->pad_zeroes);
	printf("grouping: %d\n", flags->grouping);
	printf("got_width: %d\n", flags->got_width);
	printf("got_precision: %d\n", flags->got_precision);
	printf("width: %d\n", flags->width);
	printf("precision: %d\n", flags->precision);
	return "unimplemented";
}
