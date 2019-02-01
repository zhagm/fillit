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
/*
int		get_sides_count(char **tet_array)
{
	printf("+++get_sides_count+++\n");
	// tet_array is splitted
	int x;
	int y;
	int count_side;
	int side_found;

	x = 0;
	y = 0;
	count_side = 0;
	// tet_array is empty pointer into which you should put ["...#", "...#", (etc..)]
	while(tet_array[y])
	{
		x = 0;
		while(tet_array[y][x] != '\0')
		{
			side_found = 0;
			if (tet_array[y][x] == '#')
			{
				if (y != 0)
				{
					if (tet_array[y - 1][x] == '#'){
						count_side++;
						side_found++;
					}
				}
				if (y != 3)
				{
					if (tet_array[y + 1][x]== '#')
					{
						count_side++;
						side_found++;
					}
				}
					if ((x + 1) != '\0')
					{
						if(tet_array[y][x+1]== '#')
						{
							count_side++;
							side_found++;
						}
					}
				if (x != 0)
				{
					if (tet_array[y][x-1]== '#'){
						count_side++;
						side_found++;
					}
				}
				if (side_found == 0)
				{
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	printf("---get_side_count---\n");
	// return the count
	return (count_side);
}
*/

void	print_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	printf("y:%d\n",i);
}

int		ft_charcount(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	printf("hashes counted %d\n", count);
	return (count);
}

int		check_valid_tetrimino(char *tet, t_tet **tet_list)
{
	printf("+++check_valid_tetrimino+++\n");
	int		i;
	int		count;
	char	**tet_array;
	t_tet	*new_item;

	i = 0;
	while (tet[i])
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
	// printf("format checked\n");
	tet_array = ft_strsplit(tet,'\n');
	// print_array(tet_array);
	// printf("+++string splitted+++\n");
	if ((ft_charcount(tet, '#')) != 4)
	{
		printf("-----------------------ERROR: NOT 4 #'S!!!\n");
		return (0);
	}
	printf("-----passed hashes\n");
	count = get_sides_count(tet_array); // --------------------------------------------Check validity of tets with get_sides_count
	// printf("!!!sides counted %d\n!!!",count);
	if (count == 6 || count == 8) // -------------------------------------------------------If all checks pass, create list item for tet and add to tet_list
	{
		 printf("Count: %d sides\n", count);
		
		// new_item = ft_tet_lstnew(tet_array);
		// ft_tet_lstadd(tet_list, new_item);
		return (1);
	}
	printf("not six or eight sides\n");
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
