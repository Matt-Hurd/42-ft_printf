#include "ft_printf.h"

char g_hex[] = "0123456789abcdef";

int		handle_unsign(uintmax_t *value, char type)
{
	if (type == l && *value > LONG_MAX)
		*value = *value - (UINTMAX_MAX - ULONG_MAX);
	else if (type == ll && *value > LLONG_MAX)
		*value = *value - (UINTMAX_MAX - ULLONG_MAX);
	else if (type == h && *value > SHRT_MAX)
		*value = *value - (UINTMAX_MAX - USHRT_MAX);
	else if (type == hh && *value > SCHAR_MAX)
		*value = *value - (UINTMAX_MAX - UCHAR_MAX);
	else if (*value > INT_MAX)
		*value = *value - (UINTMAX_MAX - UINT_MAX);
	return (1);
}

int		handle_sign(uintmax_t *value, u32 base, char unsign, char type)
{
	if (unsign || base != 10)
		return (handle_unsign(value, type));
	else if (type == hh && *value > SCHAR_MAX)
		*value = UCHAR_MAX - (unsigned char)(*value) + 1;
	else if (type == h && *value > SHRT_MAX)
		*value = USHRT_MAX - (unsigned short)(*value) + 1;
	else if (type == l && *value > LONG_MAX)
		*value = ULONG_MAX - (unsigned long)(*value) + 1;
	else if (type == ll && *value > LLONG_MAX)
		*value = ULLONG_MAX - (unsigned long long)(*value) + 1;
	else if ((type == j || type == z) && *value > (uintmax_t)INTMAX_MIN)
		*value = UINTMAX_MAX - *value + 1;
	else if (*value > INT_MAX)
		*value = UINT_MAX - (unsigned int)(*value) + 1;
	else
		return (1);
	return (2);
}

char	*ft_num_to_base(uintmax_t value, u32 base, char unsign, char type)
{
	char		*ret;
	uintmax_t	x;
	int			count;
	int			neg;

	if (base < 2)
		return (NULL);
	count = handle_sign(&value, base, unsign, type);
	neg = ((count == 2) ? 1 : 0);
	x = value;
	while (x > base - 1)
	{
		x /= base;
		count++;
	}
	ret = ft_strnew(count);
	x = value;
	ret[0] = ((value == 0) ? '0' : ret[0]);
	ret[0] = (neg ? '-' : ret[0]);
	while (x != 0)
	{
		ret[--count] = (g_hex[x % base]);
		x /= base;
	}
	return (ret);
}

// char	*ft_itoa_base_sign(int value, int base, char unsign)
// {
// 	char	*ret;
// 	long	x;
// 	int		count;
// 	long	y;

// 	if (base < 2)
// 		return (NULL);
// 	x = (base == 10 && !unsign) ? value : 0;
// 	x = (base != 10 || unsign) ? (unsigned int)value : x;
// 	y = x;
// 	count = (x < 0) ? 2 : 1;
// 	while (x > base - 1 || x < -9)
// 	{
// 		x /= base;
// 		count++;
// 	}
// 	ret = ft_strnew(count);
// 	ret[0] = ((value == 0) ? '0' : ret[0]);
// 	ret[0] = ((base == 10 && value < 0 && !unsign) ? '-' : ret[0]);
// 	while (y != 0)
// 	{
// 		ret[--count] = (g_hex[ABS(y % base)]);
// 		y /= base;
// 	}
// 	return (ret);
// }

// char	*ft_ltoa_base(long value, int base, char unsign)
// {
// 	char		*ret;
// 	long long	x;
// 	int			count;
// 	long long	y;

// 	if (base < 2)
// 		return (NULL);
// 	x = (base == 10 && !unsign) ? value : 0;
// 	x = (base != 10 || unsign) ? (unsigned long)value : x;
// 	y = x;
// 	count = (x < 0) ? 2 : 1;
// 	while (ABS(x) > base - 1)
// 	{
// 		x /= base;
// 		count++;
// 	}
// 	ret = ft_strnew(count);
// 	ret[0] = ((value == 0) ? '0' : ret[0]);
// 	ret[0] = ((base == 10 && value < 0 && !unsign) ? '-' : ret[0]);
// 	while (y != 0)
// 	{
// 		ret[--count] = (g_hex[ABS(y % base)]);
// 		y /= base;
// 	}
// 	return (ret);
// }

// char	*ft_lltoa_base(long long value, int base, char unsign)
// {
// 	char	*ret;
// 	ull		x;
// 	int		count;
// 	ull		y;

// 	if (base < 2)
// 		return (NULL);
// 	x = value;
// 	y = x;
// 	count = (base == 10 && (ll)x < 0) ? 2 : 1;
// 	while (ABS(x) > base - 1 || x < -9)
// 	{
// 		x /= base;
// 		count++;
// 	}
// 	ret = ft_strnew(count);
// 	ret[0] = ((value == 0) ? '0' : ret[0]);
// 	ret[0] = ((base == 10 && value < 0) ? '-' : ret[0]);
// 	while (y != 0)
// 	{
// 		ret[--count] = (g_hex[ABS(y % base)]);
// 		y /= base;
// 	}
// 	return (ret);
// }
