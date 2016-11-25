/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:28:58 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/06 16:17:08 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_convs = "diouxXDOUeEfFgGaACcSspn%Z";

t_conv g_convtab[] =
{
	{"d", &ft_conv_nums},
	{"i", &ft_conv_nums},
	{"o", &ft_conv_nums},
	{"u", &ft_conv_nums},
	{"x", &ft_conv_nums},
	{"X", &ft_conv_nums},
	{"D", &ft_conv_nums},
	{"O", &ft_conv_nums},
	{"U", &ft_conv_nums},
	{"e", &ft_conv_unimp},
	{"E", &ft_conv_unimp},
	{"f", &ft_conv_unimp},
	{"F", &ft_conv_unimp},
	{"g", &ft_conv_unimp},
	{"G", &ft_conv_unimp},
	{"a", &ft_conv_unimp},
	{"A", &ft_conv_unimp},
	{"C", &ft_conv_c},
	{"c", &ft_conv_c},
	{"S", &ft_conv_s},
	{"s", &ft_conv_s},
	{"p", &ft_conv_nums},
	{"n", &ft_conv_unimp},
	{"%", &ft_conv_unimp},
	{"Z", &ft_conv_unimp}
};

void	handle_invalid(char **in, t_output *out, unsigned int len)
{
	char	*str;
	char	*search;
	int		i;
	
	search = ft_strnew(len + 1);
	ft_strncpy(search, *in, len + 1);
	str = ft_strnew(len + 1);
	str[0] = '%';
	if (ft_strchr(search, '#'))
		ft_strcat(str, "#");
	if (ft_strchr(search, '+'))
		ft_strcat(str, "+");
	if (ft_strchr(search, '-'))
		ft_strcat(str, "-");
	i = 0;
	while (search[++i])
		if (search[i] != '#' && search[i] != '+' && search[i] != '-' && search[i] != ' ' && (search[i] != '0' || !ft_strchr(search, '-')))
			break ;
	ft_strcat(str, search + i);
	out->str = ft_strnjoin(out->str, out->len, str, ft_strlen(str));
	out->len += ft_strlen(str);
}

void	do_conversion(char **in, t_output *out, va_list *ap, unsigned int len)
{
	int		pos_in_tab;
	t_arg	*flags;

	flags = find_flags(*in, len, ap);
	if (flags->invalid)
	{
		handle_invalid(in, out, len);
		*in += len + 1;
		return ;
	}
	pos_in_tab = ft_strchr(g_convs, (*in)[len]) - g_convs;
	g_convtab[pos_in_tab].ft((*in)[len], out, flags, ap);
	*in += len + 1;
}

void	get_next_string(char **in, t_output *out, va_list *ap)
{
	char			*tmp;
	long			dist;

	tmp = *in;
	dist = ft_strchr(tmp, '%') - tmp;
	if (dist > 0)
	{
		*in += dist;
		out->str = ft_strnjoin(out->str, out->len, tmp, dist);
		out->len += dist;
		return ;
	}
	else if (dist < 0)
	{
		dist = ft_strchr(*in, '\0') - tmp;
		out->str = ft_strnjoin(out->str, out->len, tmp, dist);
		out->len += dist;
		*in += dist;
		return ;
	}
	tmp++;
	while (*tmp && !ft_strchr(g_convs, *tmp))
		tmp++;
	if (*tmp)
		do_conversion(in, out, ap, tmp - *in);
}

long	count_strings(char *in)
{
	long	ct;
	char	*tmp;

	ct = 0;
	tmp = in;
	while (*tmp)
	{
		while (*tmp != '%' && *tmp)
			tmp++;
		if (in != tmp)
			ct++;
		if (*tmp == '%')
		{
			in = ++tmp;
			while (*tmp && !ft_strchr(g_convs, *tmp))
				tmp++;
			ct++;
			if (*tmp)
				in = ++tmp;
			else
				return (-1);
		}
	}
	return (ct);
}

int		ft_printf(char *in, ...)
{
	va_list		ap;
	va_list		ap2;
	t_output	out;

	va_start(ap, in);
	va_copy(ap2, ap);
	out.str = (char *)ft_memalloc(1);
	out.len = 0;
	while (*in)
		get_next_string(&in, &out, &ap);
	write(1, out.str, out.len);
	return (out.len);
}
