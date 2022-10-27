/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 07:46:42 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/27 18:02:32 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	while ((size_t)++i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	}
	return (dest);
}
