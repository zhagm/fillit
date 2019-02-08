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
		while (tet[y])
			y++;
		while (tet[0][x])
			x++;
		(new->height) = y;
		(new->width) = x;
	}
	else
	{
		printf("ERROR IN MAKE_NEW_TET\n");
	}
	print_tet(new);
	return (new);
}
