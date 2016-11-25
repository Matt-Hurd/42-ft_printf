
#include "ft_printf.h"

void	handle_padding(char **str, t_arg *flags, char type)
{
	char *n;

	if (!flags->got_width)
		return ;
	if (ft_strlen(*str) >= flags->width)
		return ;
	n = ft_memalloc(sizeof(char) * flags->width);
	if (flags->left_justify)
	{
		ft_strcpy(n, *str);
		ft_memset(n + ft_strlen(*str), ' ', flags->width - ft_strlen(*str));
	}
	else
	{
		if (flags->pad_zeroes && type == 'd')
			ft_memset(n, '0', flags->width - ft_strlen(*str));
		else
			ft_memset(n, ' ', flags->width - ft_strlen(*str));
		ft_strcpy(n + flags->width - ft_strlen(*str), *str);
	}
	*str = n;
}
