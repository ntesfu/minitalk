/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 08:02:34 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/27 18:02:23 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	if (!dest && !src)
		return (NULL);
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = -1;
	if (s2 > s1)
	{
		while ((size_t)++i < n)
			s1[i] = s2[i];
	}
	else
	{
		while (n--)
			s1[n] = s2[n];
	}
	return (dest);
}
