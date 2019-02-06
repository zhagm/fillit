/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 07:50:51 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/06 07:56:09 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtoend(t_list **alst, t_list *new)
{
	t_list	*hold;

	hold = *alst;
	while (hold->next)
	{
		hold = hold->next;
	}
	hold->next = new;
}
