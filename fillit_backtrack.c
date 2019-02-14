/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_backtrack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:42:53 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/06 13:42:56 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tet_placement(char **board, t_tet *curr, int pos_y, int pos_x)
{
	int		y;
	int		x;
	char	**tet;
	int		board_size;
	int		hash_count;

	tet = curr->tetrimino;
	if (board == NULL || tet == NULL)
		return (0);
	board_size = ft_strlen(board[0]);
	y = 0;
	hash_count = 0;
	while (y < curr->height)
	{
		x = 0;
		while (x < curr->width && (pos_y + y < board_size))
		{
			if (tet[y][x] == '#' && (pos_x + x < board_size) && ++hash_count)
				if (board[pos_y + y][pos_x + x] != '.')
					return (0);
			x++;
		}
		y++;
	}
	return (hash_count == 4 ? 1 : 0);
}

int		place_tet(char **board, char **tet, int *pos, int index)
{
	int		y;
	int		x;
	int		board_size;

	y = 0;
	x = 0;
	board_size = ft_strlen(board[0]);
	while (tet[y])
	{
		x = 0;
		while (tet[y][x] && (pos[0] + y < board_size))
		{
			if (tet[y][x] == '#' && (pos[1] + x < board_size))
			{
				if (index == -1)
					board[pos[0] + y][pos[1] + x] = '.';
				else
					board[pos[0] + y][pos[1] + x] = ('A' + index);
			}
			x++;
		}
		y++;
	}
	free(pos);
	return (1);
}

int		*send_pos(int first, int second)
{
	int	*pos;

	pos = (int *)malloc(2 * sizeof(int));
	pos[0] = first;
	pos[1] = second;
	return (pos);
}

int		recursive(t_list *curr, char **board, int board_size)
{
	t_tet	*tet;
	int		y;
	int		x;

	if (curr == NULL)
		return (1);
	tet = curr->content;
	y = -1;
	while (++y < board_size)
	{
		x = -1;
		while (++x < board_size)
		{
			if ((check_tet_placement(board, tet, y, x)) == 1)
			{
				place_tet(board, tet->tetrimino,
				send_pos(y, x), curr->content_size);
				if (recursive(curr->next, board, board_size) == 1)
					return (1);
				else
					place_tet(board, tet->tetrimino, send_pos(y, x), -1);
			}
		}
	}
	return (0);
}
