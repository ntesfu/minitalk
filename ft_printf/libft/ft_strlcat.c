/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:47:06 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/24 18:56:20 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s_dst;
	size_t	s_src;
	size_t	len;
	size_t	j;

	j = 0;
	s_dst = ft_strlen(dest);
	s_src = ft_strlen(src);
	len = s_dst;
	if (size < 1)
		return (s_src + size);
	if (len < size - 1)
	{
		while (src[j] && len < size - 1)
		{
			dest[len++] = src[j++];
		}
		dest[len] = '\0';
	}
	if (size < s_dst)
		return (s_src + size);
	else
		return (s_src + s_dst);
}
