/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:11:33 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/08 15:34:10 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isspace(char c)
{
	int	a;
	int	b;

	a = (c == '\n' || c == ' ' || c == '\t');
	b = (c == '\r' || c == '\v' || c == '\f');
	return (a || b);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * minus);
}
