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

char	**place_tet(char **board, char **tet, int pos_y, int pos_x, int index)
{
	int		y;
	int		x;
	char	**modified_board;
	int		board_size;

	y = 0;
	x = 0;
	board_size = ft_strlen(board[0]);
	modified_board = duplicate_board(board);
	while (tet[y])
	{
		x = 0;
		while (tet[y][x] && (pos_y + y < board_size))
		{
			if (tet[y][x] == '#' && (pos_x + x < board_size))
			{
				modified_board[pos_y + y][pos_x + x] = ('A' + index);
			}
			x++;
		}
		y++;
	}
	return (modified_board);
}

int		recursive(t_list *curr, char **board, char ***result)
{
	t_tet	*tet;
	int		y;
	int		x;
	int		board_size;

	if (curr == NULL)
	{
		*result = duplicate_board(board);
		free(board);
		return (1);
	}
	board_size = ft_strlen(board[0]);
	tet = curr->content;
	y = -1;
	while (++y < board_size && (x = -1))
	{
		while (++x < board_size)
		{
			if ((check_tet_placement(board, tet, y, x)) == 1)
				if (recursive(curr->next, place_tet(board, tet->tetrimino,
				y, x, curr->content_size), result) == 1)
					return (1);
		}
	}
	return (0);
}
