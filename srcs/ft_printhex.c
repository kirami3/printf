#include "ft_printf.h"

void	ft_printf_x(unsigned long nbr, t_flags *flags)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr, 16);
	len = ft_strlen(str);
	if (flags->g_dot != -1 && flags->g_dot > len)
		len = flags->g_dot;
	if (nbr == 0 && flags->g_dot == 0)
		len = 0;
	if (flags->g_minus == 1)
		ft_uprint_left(flags, str, len, nbr);
	else
		ft_uprint_right(flags, str, len, nbr);
	free(str);
}

void	ft_printf_X(unsigned long nbr, t_flags *flags)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = NULL;
	str = ft_itoa(nbr, 16);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] = str[i] - 32;
		i++;
	}
	len = ft_strlen(str);
	if (flags->g_dot != -1 && flags->g_dot > len)
		len = flags->g_dot;
	if (nbr == 0 && flags->g_dot == 0)
		len = 0;
	if (flags->g_minus == 1)
		ft_uprint_left(flags, str, len, nbr);
	else
		ft_uprint_right(flags, str, len, nbr);
	free(str);
}
