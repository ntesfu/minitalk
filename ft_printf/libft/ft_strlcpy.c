/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:03:10 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/04 20:35:28 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size > 0)
	{
		while (src[len] && len < size - 1)
		{
			dest[len] = src[len];
			len++;
		}
		dest[len] = '\0';
	}
	while (src[len])
		len++;
	return (len);
}
