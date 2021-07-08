#include "ft_printf.h"

void	ft_swrite(t_flags *flags, char *str2)
{
	int	l;

	l = ft_strlen(str2);
	if (flags->g_dot > -1 && flags->g_dot < l)
		l = flags->g_dot;
	if ((flags->g_minus == 1 && flags->g_dot != 0 && str2))
		ft_putstr(str2, flags);
	while (flags->g_width > l)
	{
		ft_putchar(' ', flags);
		flags->g_width--;
	}
	if (flags->g_minus == -1 && flags->g_dot != 0 && str2)
		ft_putstr(str2, flags);
}

void	ft_printf_s_help(t_flags *flags)
{
	int		m;
	int		i;
	char	*str2;
	char	*str3;
	char	*str4;

	i = 0;
	str4 = "(null)";
	str2 = (char *)malloc(7);
	str3 = str2;
	m = flags->g_dot;
	if (m > 6 || m <= 0)
		m = 6;
	while (m)
	{
		str2[i] = str4[i];
		i++;
		m--;
	}
	str2[i] = '\0';
	ft_swrite(flags, str2);
	free(str3);
}

void	ft_printf_s_help_1(t_flags *flags, char *str)
{
	char	*str2;

	if (!str)
		ft_printf_s_help(flags);
	else if (!(flags->g_dot > 0 && flags->g_dot < ft_strlen(str) && str))
	{
		str2 = str;
		ft_swrite(flags, str2);
	}
}

void	ft_printf_s(char *str, t_flags *flags)
{
	int		m;
	char	*str3;
	char	*str2;
	int		i;

	str2 = (char *)malloc(ft_strlen(str) + 6);
	m = flags->g_dot;
	i = 0;
	str3 = str2;
	if (flags->g_dot > 0 && flags->g_dot < ft_strlen(str) && str)
	{
		while (m)
		{
			str2[i] = str[i];
			i++;
			m--;
		}
		str2[i] = '\0';
		ft_swrite(flags, str2);
	}
	ft_printf_s_help_1(flags, str);
	free(str3);
}
