/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sides_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:27:56 by marrodri          #+#    #+#             */
/*   Updated: 2019/01/31 15:28:01 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		side_counter(int sides, char **tet_array, int x, int y)
{
	if (y != 0)
		if (tet_array[y - 1][x] == '#')
			sides++;
	if (y != 3)
		if (tet_array[y + 1][x] == '#')
			sides++;
	if ((x + 1) != '\0')
		if (tet_array[y][x + 1] == '#')
			sides++;
	if (x != 0)
		if (tet_array[y][x - 1] == '#')
			sides++;
	return (sides);
}

int		get_sides_count(char **tet_array)
{
	int x;
	int y;
	int count_side;

	y = 0;
	count_side = 0;
	while (tet_array[y])
	{
		x = 0;
		while (tet_array[y][x] != '\0')
		{
			if (tet_array[y][x] == '#')
			{
				count_side = side_counter(count_side, tet_array, x, y);
			}
			x++;
		}
		y++;
	}
	return (count_side);
}
