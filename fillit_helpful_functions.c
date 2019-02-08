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
		while (array[i][j])
		{
			printf("%c", array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("|_END OF TET\n");
}

void	print_tet(t_tet *tet)
{
	printf("Tetrimino array: \n");
	print_array(tet->tetrimino);
	printf("height: %d, width: %d\n", tet->height, tet->width);
}

int	loop_through_tet_list(t_list **tet_list)
{
	char	**tet_array;
	t_tet	*tet_object;
	t_list	*curr;
	int		i;

	curr = *tet_list;
	while (curr)
	{
		tet_object = curr->content;
		tet_array = tet_object->tetrimino;
		print_array(tet_array);
		curr = curr->next;
		i++;
	}
	return (i);
}

int		ft_lstlen(t_list **list)
{
	t_list	*curr;
	int		i;

	curr = *list;
	i = 0;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

char	**duplicate_board(char **board)
{
	char	**res;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (board[l])
		l++;
	res = (char **)malloc((l + 1) * sizeof(char *));
	while (i < l)
	{
		res[i] = ft_strdup(board[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}


t_list	*ft_lstnew_tet(t_tet *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((new->content = (t_tet *)malloc(sizeof(t_tet))) == NULL)
		return (NULL);
	if (content)
	{
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