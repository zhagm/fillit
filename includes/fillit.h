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
# include "../libft/includes/libft.h"

typedef	struct	s_tet
{
	char		**tetrimino;
	int			width;
	int			height;
}				t_tet;

t_list			*ft_lstnew_tet(t_tet *content);
int				check_valid_file(int fd, t_list **input_list);
int				check_valid_tetrimino(char *tet, t_list **tet_list);
int				check_tet_format(char *tet);
int				get_sides_count(char **tet_array);
char			**trim_tet_array(char **tet_array);
int				*get_row_limits(char **tet_array);
int				*get_col_limits(char **tet_array);
t_tet			*make_new_tet(char **tet_array);
char			**make_board(int size);
int				get_min_board_size(int count);
void			board_solver(t_list **tetriminos);
int				check_tet_placement(char **board, t_tet *curr, int pos_y, int
pos_x);
int				place_tet(char **board, char **tet, int *pos, int index);
int				recursive(t_list *curr, char **board, int board_size);
void			free_board(char **board);
void			free_tet(t_tet *tet);
void			free_tet_list(t_list *list);

#endif
