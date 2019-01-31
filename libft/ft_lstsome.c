/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 09:24:23 by zmagauin          #+#    #+#             */
/*   Updated: 2019/01/21 09:24:25 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsome(t_list *lst, int (*f)(t_list *elem))
{
	t_list *curr;
	t_list *hold;

	curr = lst;
	while (curr)
	{
		hold = curr->next;
		if (f(curr))
			return (1);
		curr = hold;
	}
	return (0);
}
