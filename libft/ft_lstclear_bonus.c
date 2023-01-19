/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:37:01 by mabahani          #+#    #+#             */
/*   Updated: 2022/10/24 16:19:11 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*saver;

	if (*lst && del)
	{
		while (*lst)
		{
			saver = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = saver;
		}
	}
}
