/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:26:38 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/09 05:32:06 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		n *= -1;
	else if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	get_char(int n, char *res, int *i)
{
	if (n == -2147483648)
	{
		res[++(*i)] = '-';
		res[++(*i)] = '2';
		get_char(147483648, res, i);
	}
	else if (n < 0)
	{
		res[++(*i)] = '-';
		get_char(n * -1, res, i);
	}
	else
	{
		if (n > 9)
		{
			get_char(n / 10, res, i);
			res[++(*i)] = n % 10 + '0';
		}
		else
			res[++(*i)] = n % 10 + '0';
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*res;

	len = get_length(n);
	if (n < 0)
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	get_char(n, res, &i);
	res[len] = '\0';
	return (res);
}
