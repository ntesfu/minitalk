/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:08:22 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/08 16:44:29 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (ft_strlen(s) < start)
	{
		res = (char *)malloc(sizeof(char));
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (NULL);
		while (i < (int)len && s[start])
			res[i++] = s[start++];
		res[i] = '\0';
	}
	return (res);
}
