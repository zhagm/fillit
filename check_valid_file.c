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

int		get_sides_count(char *tet, char **tet_array)
{
	// tet is string of tetrimino
	// tet_array is empty pointer into which you should put ["...#", "...#", (etc..)]
	// return the count
	return (6);
}

void	print_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

int		check_valid_tetrimino(char *tet, t_tet **tet_list)
{
	int		i;
	int		count;
	char	**tet_array;
	t_tet	*new_item;

	i = 0;
	while (tet[i]) // -----------------------------------------------------------Checks whether string is formatted correctly
	{
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
		i++;
	}
	count = get_sides_count(tet, tet_array); // --------------------------------------------Check validity of tets with get_sides_count
	if (count == 6 || count == 8) // -------------------------------------------------------If all checks pass, create list item for tet and add to tet_list
	{
		printf("Count: %d sides\n", count);
		print_array(tet_array);
		// new_item = ft_tet_lstnew(tet_array);
		// ft_tet_lstadd(tet_list, new_item);
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
	t_tet  *tet_list;

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
