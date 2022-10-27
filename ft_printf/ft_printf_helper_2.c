/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:07:55 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/04 08:07:58 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_str_helper(int precision, int p_flag, char *str)
{
	int	len;

	len = ft_min(precision, ft_strlen(str));
	if (p_flag)
		write(1, str, len);
	else
		ft_putstr_fd(str, 1);
}

/*prints string: concerning flags: -, . & width*/
int	print_string(char *str, int flags[])
{
	int	precision;
	int	len;

	precision = 0;
	if (str == NULL)
		return (print_string("(null)", flags));
	if (flags[2] > 0)
	{
		precision = 1;
		len = ft_min(ft_strlen(str), flags[7]);
	}
	else
		len = ft_strlen(str);
	if (flags[0] > 0)
	{
		print_str_helper(flags[7], precision, str);
		print_space(&len, flags[6], ' ');
	}
	else
	{
		print_space(&len, flags[6], ' ');
		print_str_helper(flags[7], precision, str);
	}
	return (len);
}

void	print_sgn_right_jstfd(int *len, int *p_digits, char *sgn, int flags[])
{
	if (flags[1] && !flags[2])
	{
		ft_putstr_fd(sgn, 1);
		print_space(len, flags[6], '0');
	}
	else
	{	
		print_space(len, flags[6], ' ');
		ft_putstr_fd(sgn, 1);
	}
	print_space(p_digits, flags[7], '0');
}

/*flags= -,0,.,#, ,+,width,precision*/
int	print_signed_int_helper(long rev, int *len, char *sgn, int flags[])
{	
	int	p_digits;

	p_digits = 0;
	if (flags[2] && flags[7] > (*len - (int)ft_strlen(sgn)))
	{
		p_digits = *len - ft_strlen(sgn);
		*len = flags[7] + ft_strlen(sgn);
	}
	else if (!flags[2] && rev == 0)
		(*len)++;
	else
		p_digits = flags[7];
	if (flags[0])
	{
		ft_putstr_fd(sgn, 1);
		print_space(&p_digits, flags[7], '0');
		print_signed_num_recursive(rev, flags[2]);
		print_space(len, flags[6], ' ');
	}
	else
	{
		print_sgn_right_jstfd(len, &p_digits, sgn, flags);
		print_signed_num_recursive(rev, flags[2]);
	}
	return (*len);
}

/*prints %d and %i: concerned flags: all except #
flags= -,0,.,#, ,+,width,precision*/
int	print_signed_int(int num, int flags[])
{
	int		len;
	long	val;
	long	rev;
	char	*sgn;

	len = 0;
	if (num < 0)
		rev = (long)num * -1;
	else
		rev = (long)num;
	val = rev;
	while (val)
		val = val / 10 + (0 * len++);
	if (flags[4] && !flags[5] && num >= 0)
		sgn = get_sign_char(" ", &len);
	else if (flags[5] && num >= 0)
		sgn = get_sign_char("+", &len);
	else if (num < 0)
		sgn = get_sign_char("-", &len);
	else
		sgn = "";
	return (print_signed_int_helper(rev, &len, sgn, flags));
}
