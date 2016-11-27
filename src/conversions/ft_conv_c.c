#include "ft_printf.h"

//TODO: Wide chars

void	ft_conv_wc(char **str, va_list *ap)
{
	wchar_t in;
	int		len;
	
	in = va_arg(ap, wchar_t);
	len = wchar_len(in);
	*str = ft_strnew(len);
	if (in <= 0x7F)
		(*str)[0] = in;
	else if (in <= 0x7FF)
	{
		(*str)[0] = (in >> 6) + 0xC0;
		(*str)[1] = (in & 0x3F) + 0x80;
	}
	else if (in <= 0xFFFF)
	{
		(*str)[0] = ((in >> 12) & 0xE0);
		(*str)[1] = ((in >> 6) & 0x3F) + 0x80;
		(*str)[2] = (in & 0x3F) + 0x80;
	}
	else if (in <= 0x10FFFF)
	{
		(*str)[0] = ((in >> 18) & 0xF0);
		(*str)[1] = ((in >> 12) & 0x3F) + 0x80;
		(*str)[2] = ((in >> 6) & 0x3F) + 0x80;
		(*str)[3] = (in & 0x3F) + 0x80;
	}
}

void	ft_conv_c(char in, t_output *out, t_arg *flags, va_list *ap)
{
	int		c;
	char	*str;
	char	null;
	size_t	len;
	size_t	pos;

	(void)in;
	if (in == 'C')
		ft_conv_wc(&str, ap);
	else
	{
		c = va_arg(ap, int);
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
