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
	int		x;
	int		y;

	if ((new = (t_tet *)malloc(sizeof(t_tet))) == NULL)
		return (NULL);
	if ((new->size = (int *)malloc(2 * sizeof(int))) == NULL)
		return (NULL);
	if (tet_array)
	{
		new->tetrimino = trim_tet_array(tet_array);
		x = 0;
		while (new->tetrimino[x])
			x++;
		while (new->tetrimino[0][y])
			y++;
		(new->size)[0] = x;
		(new->size)[1] = y;
	}
	else
	{
		printf("ERROR IN MAKE_NEW_TET\n");
	}
	return (new);
}
