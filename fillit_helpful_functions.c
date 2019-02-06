/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:02:08 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/01 18:02:10 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_array(char **array)
{
	int i;
	int j;

	i = 0;
	printf("|-START\n");
	while (array[i] && array[i][0])
	{
		j = 0;
		printf("|(%d)[", i);
		while (array[i][j] && j < 4)
		{
			printf(" %c ", array[i][j]);
			j++;
		}
		printf("]\n");
		i++;
	}
	printf("|_END OF TET\n");
}

void	print_tet(t_tet *tet)
{
	printf("Tetrimino array: \n");
	print_array(tet->tetrimino);
	printf("size: [%d, %d]\n", tet->size[0], tet->size[1]);
}

void	loop_through_tet_list(t_list **tet_list)
{
	char	**tet_array;
	t_tet	*tetrimino;
	t_list	*curr;
	int		i;

	curr = *tet_list;
	while (curr)
	{
		tetrimino = curr->content;
		tet_array = tetrimino->tetrimino;
		print_array(tet_array);
		curr = curr->next;
	}
}
