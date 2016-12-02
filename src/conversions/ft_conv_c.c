#include "ft_printf.h"

int		ft_conv_wc(char **str, va_list *ap)
{
	wchar_t in;
	int		len;

	in = va_arg(*ap, wchar_t);
	len = wchar_len(in);
	*str = ft_strnew(len);
	if (in <= 0x7F)
		(*str)[0] = in;
	else if (in <= 0x7FF)
	{
		(*str)[0] = 192 | (((unsigned int)(in) >> 6) & 63);
		(*str)[1] = 128 | ((unsigned int)(in) & 63);
	}
	else if (in <= 0xFFFF)
	{
		(*str)[0] = 224 | (((unsigned int)(in) >> 12) & 63);
		(*str)[1] = 128 | (((unsigned int)(in) >> 6) & 63);
		(*str)[2] = 128 | ((unsigned int)(in) & 63);
	}
	else if (in <= 0x10FFFF)
	{
		(*str)[0] = 240 | (((unsigned int)(in) >> 18) & 63);
		(*str)[1] = 128 | (((unsigned int)(in) >> 12) & 63);
		(*str)[2] = 128 | (((unsigned int)(in) >> 6) & 63);
		(*str)[3] = 128 | ((unsigned int)(in) & 63);
	}
	return (in == 0);
}

void	ft_conv_c(char in, t_output *out, t_arg *flags, va_list *ap)
{
	int		c;
	char	*str;
	char	null;
	size_t	len;
	size_t	pos;

	null = 0;
	if (in == 'C' || flags->length == l)
	{
		null = ft_conv_wc(&str, ap);
		if (null)
			str[0] = null;
	}
	else
	{
		c = va_arg(*ap, int);
		str = ft_strnew(1);
		null = (c == 0) ? 1 : 0;
		str[0] = c + null;
	}
	handle_padding(&str, flags, 's');
	if (null)
	{
		len = ft_strlen(str);
		pos = 0;
		while (pos < len)
		{
			if (str[pos] == null)
				str[pos] = 0;
			pos++;
		}
		out->str = ft_strnjoin(out->str, out->len, str, len);
		out->len += len;
	}
	else
	{
		out->str = ft_strnjoin(out->str, out->len, str, ft_strlen(str));
		out->len += ft_strlen(str);
	}
}
