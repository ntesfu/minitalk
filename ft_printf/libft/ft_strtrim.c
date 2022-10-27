/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:12:55 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/28 13:46:11 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

static int	count_len(char const *s1, char const *set)
{
	int	len;
	int	trimlen;
	int	i;
	int	j;

	len = ft_strlen(s1);
	trimlen = 0;
	i = 0;
	while (isset(s1[i], set) && s1[i])
	{
		i++;
		trimlen++;
	}
	j = len - 1;
	while (isset(s1[j], set) && s1[j] && i < j)
	{
		j--;
		trimlen++;
	}
	return (len - trimlen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*res;
	int		j;

	len = count_len(s1, set);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = -1;
	while (isset(s1[i], set) && s1[i])
		i++;
	while (s1[i] && j < len - 1)
	{
		res[++j] = s1[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}
