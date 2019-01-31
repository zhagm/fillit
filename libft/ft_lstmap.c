/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 07:59:32 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/06 08:31:35 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst_head;
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = f(lst);
	new_lst_head = curr;
	while (lst->next)
	{
		lst = lst->next;
		if ((curr->next = f(lst)) == NULL)
			return (NULL);
		curr = curr->next;
	}
	return (new_lst_head);
}
