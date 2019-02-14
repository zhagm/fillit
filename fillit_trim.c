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

char	**trim_tet_array(char **arr)
{
	char	**res;
	int		i;
	int		j;
	int		*r_lims;
	int		*c_lims;

	r_lims = get_row_limits(arr);
	c_lims = get_col_limits(arr);
	if ((res =
	malloc((((r_lims[1] - r_lims[0]) + 1) + 1) * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (i >= r_lims[0] && i <= r_lims[1])
			res[j++] =
			ft_strndup(arr[i] + c_lims[0], ((c_lims[1] - c_lims[0]) + 1));
		i++;
	}
	free(r_lims);
	free(c_lims);
	res[j] = NULL;
	return (res);
}
