#include "ft_printf.h"

void	ft_cleanflags(t_flags *flags)
{
	flags->g_width = -1;
	flags->g_minus = -1;
	flags->g_dot = -1;
	flags->g_zero = -1;
}

void	ft_toch(const char *str, t_flags *flags)
{
	while (*str != 's' && *str != 'c' && *str != 'x'
		&& *str != 'X' && *str != 'd' && *str != 'i'
		&& *str != 'u' && *str != 'p' && *str != '\0')
	{
		if (*str == '.')
			flags->g_dot = 0;
		str++;
	}
}

int	ft_zero_nul(const char *str, t_flags *flags)
{
	int	i;

	i = 0;
	while (*str == '0' || *str == '-')
	{
		if (*str == '-')
		{
			flags->g_minus = 1;
			if (flags->g_zero == 0)
				flags->g_zero = -1;
		}
		if (*str == '0' && flags->g_minus == -1)
			flags->g_zero = 0;
		str++;
		i++;
	}
	ft_toch(str, flags);
	return (i);
}

int	ft_width(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	if (str[i] >= '0' && str[i] <= '9')
	{
		flags->g_width = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			flags->g_width = flags->g_width *10 + (str[i] - '0');
			i++;
		}
	}
	return (i);
}
