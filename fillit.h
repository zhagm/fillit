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
	char		**tetrimino;
	int			*size; // [3, 4]

}				t_tet;


// Delete before submission
void	print_array(char **array);
void	print_tet(t_tet *tet);

int		check_valid_file(int fd);
int		check_valid_tetrimino(char *tet, t_list **tet_list);
int		check_tet_format(char *tet);
int		get_sides_count(char **tet_array);

char	**trim_tet_array(char **tet_array);
char	**get_trim_array(char **arr, int *row_limits, int *col_limits);
int		*get_row_limits(char **tet_array);
int		*get_col_limits(char **tet_array);

t_tet	*make_new_tet(char **tet_array);

// RUN FOR EXECUTABLE: gcc main.c libft/libft.a fillit_*.c

#endif
