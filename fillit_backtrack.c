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

int		check_tet_placement(char **board, t_tet *tet_object, int pos_y, int pos_x)
{
	int		y;
	int		x;
	char	**tet;
	int		tet_width;
	int		tet_height;
	int		board_size;

	if (!board || !tet)
		return (0);
	tet = tet_object->tetrimino;
	tet_width = tet_object->width;
	tet_height = tet_object->height;
	printf("ALLS GOOD HERE\n");
	print_tet(tet_object);
	printf("tetsizes: y:%d  x:%d\n", tet_width, tet_height);
	board_size = 0;
	while (board[board_size])
		board_size++;
	y = 0;
	x = 0;
	while (y < tet_height)
	{
		x = 0;
		while (x < tet_width && ((pos_y + y < board_size) && (pos_x + x < board_size)))
		{
			if (tet[y][x] == '#')
			{
				if (board[pos_y + y][pos_x + x] != '.')
				{
					return (0);
				}
			}
			else
			{
			}
			x++;
		}
		y++;
	}
	return (1);
}

char	 **place_tet(char **board, char **tet, int pos_y, int pos_x)
{
	int		y;
	int		x;
	char	*hold;
	char	**modified_board;

	y = 0;
	x = 0;

	modified_board = duplicate_board(board);
	while (tet[y])
	{
		x = 0;
		while (tet[y][x])
		{
			if (tet[y][x] == '#')
			{
				modified_board[pos_y + y][pos_x + x] = 'A';
			}
			x++;
		}
		y++;
	}
	return (modified_board);
}

int		backtrack(char **orig_board, t_list **tetriminos, char **modified_board)
{
	// modify modified_board (it's NULL rn)
	// return 0 if fail, 1 if success
	int		valid;
	t_list  *curr;
	t_tet   *tet_object;
	int		placement_valid;
	int		x;
	int		y;

	curr = *tetriminos;
	tet_object = curr->content;
	x = 0;
	y = 0;

	recursive(curr, orig_board);
	return (1);
}

int		recursive(t_list *curr, char **board)
{
	int		placement;
	char	**tet;
	t_tet	*tet_object;
	int		y;
	int 	x;
	int		board_size;
	if (curr == NULL)
		return (1);
	board_size = 0;
	while (board[board_size])
		board_size++;
	y = 0;
	tet_object = curr->content;
	tet = tet_object->tetrimino;
	while (y < board_size)
	{
		x = 0;
		while (x < board_size)
		{
			if ((check_tet_placement(board, tet_object, y, x)) == 1)
			{
				if (recursive(curr->next, board) == 1)
				{
				// 	board = place_tet(board, tet, y, x);
				}
				else
				{
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}
