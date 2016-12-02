
#include "ft_printf.h"

void	handle_padding(char **str, t_arg *flags, char type)
{
	char	*n;
	char	alt;

	if (!flags->got_width)
		return ;
	if (ft_strlen(*str) >= flags->width)
		return ;
	n = ft_strnew(flags->width);
	if (flags->left_justify)
	{
		ft_strcpy(n, *str);
		ft_memset(n + ft_strlen(*str), ' ', flags->width - ft_strlen(*str));
	}
	else
	{
		alt = 0;
		if (flags->pad_zeroes)
		{
			alt = (!ft_isalnum((*str)[0]) && type == 'd') ? (*str)[0] : 0;
			ft_memset(n, '0', flags->width - ft_strlen(*str) + !!alt);
			if (alt)
				n[0] = alt;
			if (alt)
				(*str)[0] = '0';
		}
		else
		{
			ft_memset(n, ' ', flags->width - ft_strlen(*str));
			if (flags->force_sign || (*str)[0] == '-')
				n[flags->width - ft_strlen(*str)] = ((*str)[0] == '-') ? '-' : '+';
		}
		ft_strcpy(n + flags->width - ft_strlen(*str) + !!alt, *str + !!alt);
	}
	*str = n;
}
