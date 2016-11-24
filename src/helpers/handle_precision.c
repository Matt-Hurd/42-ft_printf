
#include "ft_printf.h"

void	handle_precision(char **str, t_arg *flags, char type)
{
	if (!flags->got_precision)
		return ;
	if (type != 's')
		return ; //placeholder
	if (ft_strlen(*str) <= flags->precision) //TODO: probably need to check, might not be null terminated
		return ;
	(*str)[flags->precision] = 0;
}
