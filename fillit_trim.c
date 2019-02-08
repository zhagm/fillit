/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:03:46 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/01 18:03:47 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_trim_array(char **arr, int *row_limits, int *col_limits)
{
	int		width;
	int		height;
	char	**res;
	int		i;
	int		j;

	width = ((col_limits[1] - col_limits[0]) + 1);
	height = ((row_limits[1] - row_limits[0]) + 1);
	res = malloc((height + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (i >= row_limits[0] && i <= row_limits[1])
			res[j++] = ft_strndup(arr[i] + col_limits[0], width);
		i++;
	}
	res[j] = NULL;
	return (res);
}

int		*get_row_limits(char **tet_array)
{
	int i;
	int *res;

	res = (int *)malloc(2 * sizeof(int));
	res[0] = -1;
	i = 0;
	while (tet_array[i] && i < 4)
	{
		if ((ft_strchr(tet_array[i], '#')))
		{
			if (res[0] < 0)
			{
				res[0] = i;
				res[1] = i;
			}
			else
				res[1] = i;
		}
		i++;
	}
	return (res);
}

int		*get_col_limits(char **tet_array)
{
	int i;
	int j;
	int *res;

	res = (int *)malloc(2 * sizeof(int));
	res[0] = -1;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (tet_array[++j] && j < 4)
		{
			if (tet_array[j][i] == '#')
			{
				if (res[0] < 0)
				{
					res[0] = i;
					res[1] = i;
				}
				else
					res[1] = i;
			}
		}
	}
	return (res);
}

char	**trim_tet_array(char **tet_array)
{
	int *row_limits;
	int *col_limits;

	row_limits = get_row_limits(tet_array);
	col_limits = get_col_limits(tet_array);
	return (get_trim_array(tet_array, row_limits, col_limits));
	return (tet_array);
}
