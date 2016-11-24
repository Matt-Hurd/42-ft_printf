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

void	ft_conv_s(char in, t_output *out, t_arg *flags, va_list *ap)
{
	char *s;

	(void)in;
	(void)flags;
	s = va_arg(ap, char *);
	s = ft_strdup(s);
	handle_precision(&s, flags, 's');
	handle_padding(&s, flags);
	out->str = ft_strnjoin(out->str, out->len, s, ft_strlen(s));
	out->len += ft_strlen(s);
}
