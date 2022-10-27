/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsgn_numlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:28:52 by ntesfu            #+#    #+#             */
/*   Updated: 2022/02/04 16:28:54 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unsgn_numlen(unsigned int clone, int base_n)
{
	int	len;

	len = 0;
	while (clone)
		clone = clone / base_n + (0 * len++);
	return (len);
}
