/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:14:06 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/08 15:02:19 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && (i + j < n))
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (needle[j] == '\0')
		{	
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
