/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 08:08:07 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/04 08:08:10 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_space(int *len, int width, char sp)
{
	while (*len < width)
	{
		write(1, &sp, 1);
		(*len)++;
	}
}

void	print_rev_number(long rev, int precision)
{
	if (precision == 0 && rev == 0)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	while (rev)
	{
		ft_putchar_fd(rev % 10 + '0', 1);
		rev /= 10;
	}
}

void	print_signed_num_recursive(long nbr, int precision)
{
	if (precision > 0 && nbr == 0)
		return ;
	else if (nbr > (long)9)
	{
		print_signed_num_recursive(nbr / 10, 0);
		ft_putchar_fd(nbr % 10 + '0', 1);
	}
	else
		ft_putchar_fd(nbr % 10 + '0', 1);
}

void	print_unsgn_int_num_recurse(int b_n, char *b, unsigned int nb, int p)
{
	if (p > 0 && nb == 0)
		return ;
	else if (nb > (unsigned int)b_n - 1)
	{
		print_unsgn_int_num_recurse(b_n, b, nb / b_n, 0);
		ft_putchar_fd(b[nb % b_n], 1);
	}
	else
		ft_putchar_fd(b[nb % b_n], 1);
}

void	print_unsgn_num_recurse(int b_n, char *b, unsigned long long nb, int p)
{
	if (p > 0 && nb == 0)
		return ;
	else if (nb > (unsigned long long)b_n - 1)
	{
		print_unsgn_num_recurse(b_n, b, nb / b_n, 0);
		ft_putchar_fd(b[nb % b_n], 1);
	}
	else
		ft_putchar_fd(b[nb % b_n], 1);
}
