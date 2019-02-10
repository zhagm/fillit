/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:36:15 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/09 19:36:16 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_printarray(char **array)
{
	int	i;
	int j;

	i = 0;
	while (array[i] && array[i][0])
	{
		j = 0;
		while (array[i][j])
		{
			ft_putchar(array[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
