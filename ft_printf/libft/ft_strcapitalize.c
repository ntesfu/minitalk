/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:28:40 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/04 16:28:42 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcapitalize(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - ('z' - 'Z');
		str++;
	}
}