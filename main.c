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
	int		file_valid;
	char	**board;
	t_list	*curr;
	t_tet	*tet_pointer_del;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		file_valid = check_valid_file(fd, &input_list);
		curr = input_list;
		printf("STARTING HERE");
		while (curr)
		{
			printf("PRINTING TET RIGHT NOW\n");
			tet_pointer_del = curr->content;
			printf("tet_size: width: %d, height: %d\n", tet_pointer_del->width, tet_pointer_del->height);
			print_tet(curr->content);
			curr = curr->next;
		}
		if (file_valid)
		{
			board = board_solver(&input_list);
		}
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
 * check pdf for submission requirements
 * have executable in root
*/
