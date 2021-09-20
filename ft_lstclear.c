/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:33:33 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/20 16:01:28 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	if (lst && del)
	{
		while (*lst)
		{
			nxt = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = nxt;
		}
		*lst = 0;
	}
}
