/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 19:17:17 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/01 22:24:04 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*wchar_dup(wchar_t *in)
{
	wchar_t *ret;
	size_t	count;
	size_t	i;

	count = 0;
	while (in[count])
		count++;
	ret = (wchar_t *)ft_memalloc(sizeof(wchar_t) * (count + 1));
	i = 0;
	while (i < count)
	{
		ret[i] = in[i];
		i++;
	}
	return (ret);
}

char	*wchar_to_str(wchar_t *in)
{
	size_t	len;
	char	*ret;
	int		pos;

	len = wcharp_len(in);
	ret = ft_strnew(len);
	pos = 0;
	while (*in)
	{
		if (*in <= 0x7F)
			ret[pos++] = *in;
		else if (*in <= 0x7FF)
		{
			ret[pos++] = 192 | (((unsigned int)(*in) >> 6) & 63);
			ret[pos++] = 128 | ((unsigned int)(*in) & 63);
		}
		else if (*in <= 0xFFFF)
		{
			ret[pos++] = 224 | (((unsigned int)(*in) >> 12) & 63);
			ret[pos++] = 128 | (((unsigned int)(*in) >> 6) & 63);
			ret[pos++] = 128 | ((unsigned int)(*in) & 63);
		}
		else if (*in <= 0x10FFFF)
		{
			ret[pos++] = 240 | (((unsigned int)(*in) >> 18) & 63);
			ret[pos++] = 128 | (((unsigned int)(*in) >> 12) & 63);
			ret[pos++] = 128 | (((unsigned int)(*in) >> 6) & 63);
			ret[pos++] = 128 | ((unsigned int)(*in) & 63);
		}
		in++;
	}
	return (ret);
}

void	ft_conv_ws(char in, t_output *out, t_arg *flags, va_list *ap)
{
	wchar_t *s;
	char	*str;

	(void)in;
	s = va_arg(*ap, wchar_t *);
	if (!s)
	{
		if (!flags->got_precision ||(flags->got_precision && flags->precision >= 6))
			str = ft_strdup("(null)");
		else
			str = ft_strdup("");
	}
	else
	{
		s = wchar_dup(s);
		handle_precision((char **)&s, flags, 'w');
		str = wchar_to_str(s);
	}
	handle_padding(&str, flags, 'w');
	out->str = ft_strnjoin(out->str, out->len, str, ft_strlen(str));
	out->len += ft_strlen(str);
}

void	ft_conv_s(char in, t_output *out, t_arg *flags, va_list *ap)
{
	char *s;

	(void)in;
	if (flags->length == l || in == 'S')
	{
		ft_conv_ws(in, out, flags, ap);
		return ;
	}
	s = va_arg(*ap, char *);
	if (!s)
	{
		if (!flags->got_precision ||(flags->got_precision && flags->precision >= 6))
			s = ft_strdup("(null)");
		else
			s = ft_strdup("");
	}
	else
		s = ft_strdup(s);
	handle_precision(&s, flags, 's');
	handle_padding(&s, flags, 's');
	out->str = ft_strnjoin(out->str, out->len, s, ft_strlen(s));
	out->len += ft_strlen(s);
}
