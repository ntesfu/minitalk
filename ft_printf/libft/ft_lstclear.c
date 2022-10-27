/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:41:34 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/27 16:54:08 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	if (!*lst && !del)
		return ;
	while (tmp)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next;
	}
	*lst = NULL;
}
