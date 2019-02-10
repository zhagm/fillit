/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:28:10 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/06 10:28:12 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_min_board_size(int count)
{
	int		hash_count;
	int		x;

	x = 1;
	hash_count = count * 4;
	while ((x * x) < hash_count)
		x++;
	return (x);
}

char	**make_board(int size)
{
	char	**board;
	int		i;
	char	*hold;

	board = (char **)malloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		hold = (char *)malloc((size + 1) * sizeof(char));
		ft_memset(hold, '.', size);
		hold[size] = '\0';
		board[i] = hold;
		i++;
	}
	board[i] = NULL;
	return (board);
}

char	**board_solver(t_list **tetriminos)
{
	int		board_size;
	int		solved;
	char	**board;
	char	**solved_board;

	board_size = get_min_board_size(ft_lstlen(tetriminos));
	solved = 0;
	while (!solved)
	{
		board = make_board(board_size++);
		solved = recursive(*tetriminos, board, &solved_board);
	}
	return (solved_board);
}
