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
	int		hash_count;

	hash_count = 0;
	tet = tet_object->tetrimino;
	if (board == NULL || tet == NULL)
		return (0);
	tet_width = tet_object->width;
	tet_height = tet_object->height;
	board_size = 0;
	while (board[board_size])
		board_size++;
	y = 0;
	x = 0;
	// printf("-----------board_size %d\n", board_size);
	// printf("-----------tet_width %d\n", tet_width);
	// printf("-----------tet_height %d\n", tet_height);
	// printf("-----------x %d\n", x);
	// printf("-----------y %d\n", y);
	// printf("-----------pos_x %d\n", pos_x);
	// printf("-----------pos_y %d\n", pos_y);
	while (y < tet_height)
	{
		x = 0;
		while (x < tet_width && (pos_y + y < board_size))
		{
			if (tet[y][x] == '#' && (pos_x + x < board_size))
			{
				hash_count++;
				if (board[pos_y + y][pos_x + x] != '.')
					return (0);
			}
			x++;
		}
		y++;
	}
	// ft_putstr("RETURN VAL IS");
	return (hash_count == 4 ? 1 : 0);
}

char	 **place_tet(char **board, char **tet, int pos_y, int pos_x, int index)
{
	int		y;
	int		x;
	char	*hold;
	char	**modified_board;
	int		board_size;

	y = 0;
	x = 0;
	board_size = 0;
	while (board[board_size])
		board_size++;
	modified_board = duplicate_board(board);
	while (tet[y])
	{
		x = 0;
		while (tet[y][x] && (pos_y + y < board_size))
		{
			if (tet[y][x] == '#' && (pos_x + x < board_size))
			{
				modified_board[pos_y + y][pos_x + x] = ('A' + index);
				// print_array(modified_board);
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
	char	**result;

	curr = *tetriminos;
	tet_object = curr->content;
	x = 0;
	y = 0;

	result = NULL;
	recursive(curr, orig_board, &result);
	if (result == NULL)
		return (0);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	print_array(result);
	return (1);
}

int		recursive(t_list *curr, char **board, char ***result)
{
	printf("RECURSION IS COMMENCING: \n");
	print_array(board);
	int		placement;
	char	**tet;
	t_tet	*tet_object;
	int		y;
	int 	x;
	int		board_size;
	char	**modified_board;

	if (curr == NULL)
	{
		printf("CURR == NULL!!!!!!++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		print_array(board);
		printf("CURR == NULL!!!!!!++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		*result = duplicate_board(board);
		printf("RESULT");
		print_array(*result);
		return (1);
		// exit(1);
	}
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
				// printf("FOLLOWING TET PASSED PLACEMENT\n");
				// print_array(tet);
				// print_array(board);
				// printf("-----------x %d\n", x);
				// printf("-----------y %d\n", y);
				// printf("-----------content_size %zu\n", curr->content_size);
				modified_board = place_tet(board, tet, y, x, curr->content_size);
				printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
				print_array(modified_board);
				printf("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
				if (recursive(curr->next, modified_board, result) == 1)
				{
					if (result == NULL)
					{
						printf("RESULT IS NULLLLL\n");
					}
					board = modified_board;
					printf("RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
					print_array(board);
					printf("RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
					return 1;
				}
				// else
				// {
				// 	printf("ELSED OUT BC RECURSIVE FUNC RETURNED FALSE\n");
				// 	return (0);
				// }
			}
			x++;
		}
		y++;
	}
	printf("REACHED END OF RECURSIVE---------------------------------------------------\n");
	return (0);
}

// void	tester_func(t_list **tets)
// {
// 	char	**board;
// 	t_tet	*tet_ptr;

// 	board = make_board(4);
// 	// print_array(board);
// 	// print_tet((*tets)->content);
// 	// printf("content_size = %zu\n", (*tets)->content_size);
// 	tet_ptr = (*tets)->content;
// 	//char **board, t_tet *tet_object, int pos_y, int pos_x
// 	printf("CHECK TET PLACEMENT RETURNED %d\n", check_tet_placement(board, tet_ptr, 0, 0));
// 	printf("CHECK TET PLACEMENT RETURNED %d\n", check_tet_placement(board, tet_ptr, 0, 1));
// 	printf("CHECK TET PLACEMENT RETURNED %d\n", check_tet_placement(board, tet_ptr, 0, 2));
// 	printf("CHECK TET PLACEMENT RETURNED-- %d\n", check_tet_placement(board, tet_ptr, 0, 3));
// 	// print_tet
// }