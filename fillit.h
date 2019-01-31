/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:18:24 by marrodri          #+#    #+#             */
/*   Updated: 2019/01/29 13:53:46 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1000
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"

// remove later
# include <stdio.h>

typedef	struct	s_tet
{
	char			**tetrimino;
	size_t			index;
	size_t			*tet_size; // [3, 4]
	struct s_tet	*next;
}				t_tet;

int     check_valid_file(int fd);
int		check_valid_tetrimino(char *tet, t_tet **tet_list);


#endif