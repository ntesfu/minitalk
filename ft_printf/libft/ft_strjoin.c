/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:44:10 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/08 17:12:01 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	int		i;
	char	*res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < l1)
		res[i] = s1[i];
	i--;
	while (++i < l1 + l2)
		res[i] = s2[i - l1];
	res[i] = '\0';
	return (res);
}
