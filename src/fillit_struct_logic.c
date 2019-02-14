/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:06:24 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/01 18:06:25 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_lstnew_tet(t_tet *content)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		if ((new->content = (t_tet *)malloc(sizeof(t_tet))) == NULL)
			return (NULL);
		new->content = content;
		new->content_size = 0;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}

t_tet	*make_new_tet(char **tet_array)
{
	t_tet	*new;
	char	**tet;
	int		x;
	int		y;

	if ((new = (t_tet *)malloc(sizeof(t_tet))) == NULL)
		return (NULL);
	if (tet_array)
	{
		tet = trim_tet_array(tet_array);
		new->tetrimino = tet;
		y = 0;
		x = 0;
		while (tet[y] && tet[y][0])
			y++;
		while (tet[0][x])
			x++;
		(new->height) = y;
		(new->width) = x;
	}
	else
	{
		ft_putstr("ERROR IN MAKE_NEW_TET\n");
	}
	return (new);
}
