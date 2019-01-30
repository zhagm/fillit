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
int main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*full_file;

	if (argc == 2)
	{
		fd = open(argv[1],O_RDONLY);
		full_file = "\0";
		while((ret = read(fd,buff,BUFF_SIZE)))
		{

			buff[ret] = '\0';
			// check for memory leaks!!!
			full_file = ft_strjoin(full_file, buff);
		}
		ft_putstr( full_file);
		//check_valid_file(full_file);
	}
	else
	{
		ft_putstr("usage: fillit input_file\n");
	}
	return 0;
}
