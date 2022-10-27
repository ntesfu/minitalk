/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:07:36 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/04 08:07:42 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*prints character: concerning flags: - & width*/
int	print_char(int c, int flags[])
{
	int	len;

	len = 0;
	if (flags[0] > 0)
	{
		ft_putchar_fd(c, 1 + (0 * len++));
		while (len < flags[6])
			write(1, " ", 1 + (0 * len++));
	}
	else
	{
		while (len < flags[6] - 1)
			write(1, " ", 1 + (0 * len++));
		ft_putchar_fd(c, 1 + (0 * len++));
	}
	return (len);
}

int	print_pointer(unsigned long long ptr, int flags[])
{
	int					len;
	char				*base;
	unsigned long long	clone;

	len = 0;
	clone = ptr;
	base = "0123456789abcdef";
	len += 2;
	if (clone == 0)
		len++;
	while (clone)
		clone = (clone / 16) + (0 * len++);
	if (flags[0])
	{
		ft_putstr_fd("0x", 1);
		print_unsgn_num_recurse(16, base, ptr, 0);
		print_space(&len, flags[6], ' ');
	}
	else
	{
		print_space(&len, flags[6], ' ');
		ft_putstr_fd("0x", 1);
		print_unsgn_num_recurse(16, base, ptr, 0);
	}
	return (len);
}

void	print_unsgn_rgt_jstf(int *p_dgt, int nm, t_unsgn_dt *data, int flags[])
{
	if (flags[1] && !flags[2])
	{
		ft_putstr_fd(data->sgn, 1);
		print_space(&data->len, flags[6], '0');
	}
	else
	{
		print_space(&data->len, flags[6], ' ');
		ft_putstr_fd((char *)data->sgn, 1);
	}
	print_space(p_dgt, flags[7], '0');
	print_unsgn_int_num_recurse(data->base_n, data->base, nm, flags[2]);
}

/*prints %u, %x and %X: concerned flags: -,0,#,.
flags= -,0,.,#, ,+,width,precision*/
int	print_unsigned_int_helper(unsigned int num, t_unsgn_dt *data, int flags[])
{
	int	p_digits;

	p_digits = 0;
	if (flags[2] && flags[7] > (data->len - (int)ft_strlen(data->sgn)))
	{
		p_digits = data->len - ft_strlen(data->sgn);
		data->len = flags[7] + ft_strlen(data->sgn);
	}
	else if (!flags[2] && num == 0)
		(data->len)++;
	else
		p_digits = flags[7];
	if (flags[0])
	{
		ft_putstr_fd(data->sgn, 1);
		print_space(&p_digits, flags[7], '0');
		print_unsgn_int_num_recurse(data->base_n, data->base, num, flags[2]);
		print_space(&data->len, flags[6], ' ');
	}
	else
		print_unsgn_rgt_jstf(&p_digits, num, data, flags);
	return (data->len);
}

/*prints %u, %x and %X: concerned flags: -,0,#,.
flags= -,0,.,#, ,+,width,precision*/
int	print_unsigned_int(unsigned int num, int flags[], int base_n, int cap)
{
	t_unsgn_dt		*data;
	int				len;

	data = (t_unsgn_dt *)malloc(sizeof(t_unsgn_dt));
	data->len = 0;
	data->base_n = base_n;
	data->base = ft_strdup("0123456789abcdef");
	data->sgn = "";
	if (flags[3] && num != 0 && data->base_n == 16)
	{
		if (!cap)
			data->sgn = "0x";
		else
			data->sgn = "0X";
		data->len += 2;
	}
	if (cap)
		ft_strcapitalize(data->base);
	data->len += ft_unsgn_numlen(num, data->base_n);
	print_unsigned_int_helper(num, data, flags);
	len = data->len;
	free(data->base);
	free(data);
	return (len);
}
