/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:33:33 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/21 12:13:43 by sergiodg         ###   ########.fr       */
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
