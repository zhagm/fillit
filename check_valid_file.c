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

int		check_tet_format(char *tet)
{
	int		i;
	int 	hash_count;

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

char	**trim_tet_array(char **tet_arr)
{
	return (tet_array);
}

t_tet	*make_new_tet(char **tet_array)
{
	int 	x;
	int 	y;
	int		*size_array;
	t_tet	*new_tet;

	size_array = (int *)malloc(2 * sizeof(int));
	x = 0;
	while (tet_array[x])
		x++;
	while (tet_array[0][y])
		y++;
	size_array[0] = x;
	size_array[1] = y;
	new_tet->size = size_array;
	new_tet->tetrimino = trim_tet_array(tet_array);

	return (new_tet);
}

void	print_array(char **array)
{
	// int i;
	// int j;

	// i = 0;
	// while (array[i])
	// {
	// 	j = 0;
	// 	while (array[i][j])
	// 	{
	// 		printf("%");
	// 	}
	// }
	printf("ARRAY PRINT PLACEHOLDER (WRITE CODE HERE)");
}

void	print_tet(t_tet *tet)
{
	printf("Tetrimino array: \n");
	print_array(tet->tetrimino);
	printf("size: [%d, %d]\n", tet->size[0], tet->size[1]);
}

int		check_valid_tetrimino(char *tet, t_tet **tet_list)
{
	int		count;
	char	**tet_array;
	t_tet	*new_item;

	if (check_tet_format(tet) == 0)
		return (0);
	tet_array = ft_strsplit(tet, '\n');
	count = get_sides_count(tet_array); // --------------------------------------------Check validity of tets with get_sides_count
	if (count == 6 || count == 8) // -------------------------------------------------------If all checks pass, create list item for tet and add to tet_list
	{
		new_item = make_new_tet(tet_array);
		print_tet(new_item);
		// ft_tet_lstadd(tet_list, new_item);
		// free tet_array!!
		return (1);
	}
	return (0);
}

// ------------------------------------------------------------------------------takes fd, reads 1 tet at a time (buff[21), creates t_tet with all tet's if they're valid
int		check_valid_file(int fd)
{
	int		is_valid;
	int		ret;
	char	buff[21 + 1];
	t_tet	*tet_list;

	while ((ret = read(fd, buff, 21)) && is_valid)
	{
		buff[ret] = '\0';
		printf("Ret: %d\n", ret);
		if (ret == 21)
		{
			is_valid = check_valid_tetrimino(buff, &tet_list);
			printf("IS_VALID: %d\n", is_valid);
		}
		else
		{
			printf("is not valid\n");
			return (1);
			// free tet_list (mem leak)
		}
		// check for memory leaks!!!
	}
	return (0);
}
