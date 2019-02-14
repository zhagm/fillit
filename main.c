/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:39:29 by marrodri          #+#    #+#             */
/*   Updated: 2019/01/29 13:55:11 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*input_list;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(check_valid_file(fd, &input_list)))
		{
			ft_putstr("error\n");
			return (0);
		}
		board_solver(&input_list);
		free_tet_list(input_list);
		close(fd);
	}
	else
	{
		ft_putstr("usage: fillit input_file\n");
	}
	return (0);
}

/*
** Todo before submission:
** delete external files
** check pdf for submission requirements
** have executable in root
** potential error in check_valid_file: if one tetrimino ret is
** 20 and next is 21, edge case where we'd be f-ed
*/
