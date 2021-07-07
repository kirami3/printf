#include "ft_printf.h"

int	ft_dot_star(t_flags *flags, const char *str, va_list ap)
{
	int	i;

	i = 1;
	if (*(++str) == '*')
	{
		flags->g_dot = va_arg(ap, int);
		i += 1;
		if (flags->g_dot < 0 && flags->g_zero == 0)
		{
			flags->g_zero = 1;
			flags->g_dot = -1;
		}
	}
	if (*str >= '0' && *str <= '9')
	{	
		while (*str >= '0' && *str <= '9')
		{
			flags->g_dot = flags->g_dot * 10 + (*str - '0');
			str++;
			i++;
		}
		if (flags->g_zero == 0)
			flags->g_zero = -1;
	}
	return (i);
}

int	ft_star(t_flags *flags, va_list ap)
{
	int	i;

	i = 1;
	if (flags->g_width == -1)
	{
		flags->g_width = va_arg(ap, int);
		if (flags->g_width < 0)
		{
			flags->g_minus = 1;
			flags->g_width *= -1;
		}
	}
	return (i);
}
