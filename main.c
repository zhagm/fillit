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
	char	**board;
	t_list	*curr;
	int		i;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(check_valid_file(fd, &input_list)))
		{
			ft_putstr("error\n");
			return (0);
		}
		curr = input_list;
		i = 0;
		while (curr)
		{
			curr->content_size = i;
			curr = curr->next;
			i++;
		}
		board = board_solver(&input_list);
		print_array(board);
	}
	else
	{
		ft_putstr("usage: fillit input_file\n");
	}
	return (0);
}

/*
 * Todo before submission:
 * check for memory leaks (leaks on CL)
 * norm
 * Makefile
 * delete external files
 * check pdf for submission requirements
 * have executable in root
*/
