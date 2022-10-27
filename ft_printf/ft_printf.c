/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:07:20 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/04 08:07:27 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*initializes the flags to 0: flags= -,0,.,#, ,+,width,precision*/
void	flag_initialize(int flag[])
{
	int	i;

	i = -1;
	while (++i < 8)
		flag[i] = 0;
}

char	*get_sign_char(char *sgn, int *len)
{
	(*len)++;
	return (sgn);
}

/*reads flags if present: flags= -,0,.,#, ,+,width,precision*/
void	flag_format(char *str, int *ps, int flag_arr[])
{
	char	*flags;
	int		n_vl;

	flags = "-0.# +";
	n_vl = 0;
	(*ps)++;
	while ((str[*ps] && indexof(flags, str[*ps]) != -1) || ft_isdigit(str[*ps]))
	{
		if (!ft_isdigit(str[*ps]))
			flag_arr[indexof(flags, str[*ps])]++;
		else
		{
			if (flag_arr[1] == 0 && str[*ps] == '0')
				flag_arr[1] = 1;
			if (str[*ps - 1] == '.')
				n_vl = 1;
			while (ft_isdigit(str[*ps]))
			{
				flag_arr[n_vl + 6] = flag_arr[n_vl + 6] * 10 + (str[*ps] - 48);
				(*ps)++;
			}
			continue ;
		}
		(*ps)++;
	}
}

int	va_arg_specifier(char s, va_list args, int flag[])
{
	int	len;

	len = 0;
	if (s == 'c')
		len = print_char(va_arg(args, int), flag);
	else if (s == 's')
		len = print_string(va_arg(args, char *), flag);
	else if (s == 'p')
		len = print_pointer(va_arg(args, unsigned long long), flag);
	else if (s == 'd')
		len = print_signed_int(va_arg(args, int), flag);
	else if (s == 'i')
		len = print_signed_int(va_arg(args, int), flag);
	else if (s == 'u')
		len = print_unsigned_int(va_arg(args, unsigned int), flag, 10, 0);
	else if (s == 'x')
		len = print_unsigned_int(va_arg(args, unsigned int), flag, 16, 0);
	else if (s == 'X')
		len = print_unsigned_int(va_arg(args, unsigned int), flag, 16, 1);
	else if (s == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ps;
	int		len;
	int		flag[8];

	ps = 0;
	len = 0;
	flag_initialize(flag);
	va_start(args, str);
	while (str[ps])
	{
		if (str[ps] == '%')
		{
			flag_format((char *)str, &ps, flag);
			len += va_arg_specifier(str[ps], args, flag);
			flag_initialize(flag);
		}
		else
		{
			ft_putchar_fd(str[ps], 1);
			len++;
		}
		ps++;
	}
	return (len);
}
