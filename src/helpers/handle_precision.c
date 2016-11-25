
#include "ft_printf.h"

int		wchar_len(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	else if (chr <= 0x7FF)
		return (2);
	else if (chr <= 0xFFFF)
		return (3);
	else if (chr <= 0x10FFFF)
		return (4);
	return (0);
}

size_t	wcharp_len(wchar_t *in)
{
	size_t len;

	len = 0;
	while (*in)
	{
		len += wchar_len(*in);
		in++;
	}
	return (len);
}

void	handle_wchar_precision(wchar_t **str, t_arg *flags)
{
	size_t	curr_len;
	int		count;

	if (wcharp_len(*str) <= flags->precision) //TODO: probably need to check, might not be null terminated
		return ;
	curr_len = 0;
	count = 0;
	while ((*str)[count] && curr_len <= flags->precision)
		curr_len += wchar_len((*str)[count++]);
	if ((*str)[count])
		(*str)[count - 1] = 0;
}

void	handle_precision(char **str, t_arg *flags, char type)
{
	char *n;

	if (!flags->got_precision)
		return ;
	if (type == 'w')
		handle_wchar_precision((wchar_t **)str, flags);
	else if (type == 's')
	{
		if (ft_strlen(*str) <= flags->precision) //TODO: probably need to check, might not be null terminated
			return ;
		(*str)[flags->precision] = 0;
	}
	else if (type == 'd')
	{
		if (ft_strlen(*str) >= flags->precision)
			return ;
		n = ft_memalloc(sizeof(char) * flags->precision);
		ft_memset(n, '0', flags->precision - ft_strlen(*str));
		ft_strcpy(n + flags->precision - ft_strlen(*str), *str);
		*str = n;
	}
}