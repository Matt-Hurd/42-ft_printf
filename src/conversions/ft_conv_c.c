/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 19:17:17 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/06 16:25:49 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//TODO: Wide chars

void	ft_conv_c(char in, t_output *out, t_arg *flags, va_list *ap)
{
	int		c;

	(void)in;
	(void)flags;
	c = va_arg(ap, int);
	out->str = ft_strnjoin(out->str, out->len, (char *)(&c), 1);
	out->len += 1;
}
