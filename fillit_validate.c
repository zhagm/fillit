/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:16:39 by marrodri          #+#    #+#             */
/*   Updated: 2019/01/29 19:17:30 by marrodri         ###   ########.fr       */
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
				count_side = side_counter(count_side, tet_array, x, y);
			x++;
		}
		y++;
	}
	return (count_side);
}

int		check_tet_format(char *tet)
{
	int		i;
	int		hash_count;

	i = -1;
	hash_count = 0;
	while (tet[++i] && hash_count <= 4)
	{
		if (tet[i] == '#')
			hash_count++;
		if ((i + 1) % 5 && i < 20)
		{
			if (tet[i] != '.' && tet[i] != '#')
				return (0);
		}
		else
		{
			if (tet[i] != '\n')
				return (0);
		}
	}
	if (hash_count != 4)
		return (0);
	return (1);
}

int		check_valid_tetrimino(char *tet, t_list **tet_list)
{
	int		count;
	char	**tet_array;
	t_tet	*new_tet;
	t_list	*new_item;

	if (check_tet_format(tet) == 0)
		return (0);
	tet_array = ft_strsplit(tet, '\n');
	count = get_sides_count(tet_array);
	if (count == 6 || count == 8)
	{
		new_tet = make_new_tet(tet_array);
		new_item = ft_lstnew_tet(new_tet);
		new_item->content_size = ft_lstlen(tet_list);
		if (*tet_list == NULL)
			*tet_list = new_item;
		else
			ft_lstaddtoend(tet_list, new_item);
		new_tet = (*tet_list)->content;
		free(tet_array);
		return (1);
	}
	free(tet_array);
	return (0);
}

int		check_valid_file(int fd, t_list **input_list)
{
	int		is_valid;
	int		ret;
	char	buff[21 + 1];
	int		count;
	int		last_ret;

	count = 0;
	is_valid = 1;
	while ((ret = read(fd, buff, 21)) && is_valid)
	{
		buff[ret] = '\0';
		if (ret == 20)
		{
			buff[20] = '\n';
			buff[21] = '\0';
		}
		if (ret == 21 || (ret == 20))
			is_valid = check_valid_tetrimino(buff, input_list);
		if (!is_valid || (ret != 21 && ret != 20))
			return (0);
		if (ret != 0)
			last_ret = ret;
	}
	return (last_ret != 20 ? 0 : 1);
}
