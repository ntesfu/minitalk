/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:42:04 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/24 18:00:14 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	size_t			tot;
	void			*ptr;
	size_t			i;
	unsigned char	*str;

	i = 0;
	tot = nmeb * size;
	ptr = malloc(tot);
	if (ptr == NULL)
		return (NULL);
	str = (unsigned char *)ptr;
	while (i < tot)
	{
		str[i] = '\0';
		i++;
	}
	return (ptr);
}
