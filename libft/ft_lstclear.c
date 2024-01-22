/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:51:02 by qdeviann          #+#    #+#             */
/*   Updated: 2023/11/19 15:42:46 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	**head;

	if (!del || !lst)
		return ;
	head = lst;
	while ((*lst))
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, *del);
		*lst = ptr;
	}
	*head = NULL;
}
