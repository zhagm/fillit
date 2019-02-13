/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:38:39 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/09 19:38:50 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_lstlen(t_list **list)
{
	t_list	*curr;
	int		i;

	curr = *list;
	i = 0;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	free(curr);
	return (i);
}
