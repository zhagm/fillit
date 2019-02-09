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

typedef	struct	s_tet
{
	char		**tetrimino;
	int			width;
	int			height;
}				t_tet;

typedef	struct	s_position
{
	int		x;
	int		y;

}				t_position;

// Delete before submission
void	print_array(char **array);
void	print_tet(t_tet *tet);
int		loop_through_tet_list(t_list **tet_list);
int		ft_lstlen(t_list **list);
t_list	*ft_lstnew_tet(t_tet *content);
char    **duplicate_board(char **board);

int		check_valid_file(int fd, t_list **input_list);
int		check_valid_tetrimino(char *tet, t_list **tet_list);
int		check_tet_format(char *tet);
int		get_sides_count(char **tet_array);

char	**trim_tet_array(char **tet_array);
char	**get_trim_array(char **arr, int *row_limits, int *col_limits);
int		*get_row_limits(char **tet_array);
int		*get_col_limits(char **tet_array);

t_tet	*make_new_tet(char **tet_array);

char    **make_board(int size);
int     get_min_board_size(int count);
char    **board_solver(t_list **tetriminos);

int		check_tet_placement(char **board, t_tet *tet_object, int pos_y, int pos_x);
int		backtrack(char **orig_board, t_list **tetriminos, char **modified_board);
char	 **place_tet(char **board, char **tet, int pos_y, int pos_x, int index);

int		recursive(t_list *curr, char **board, char ***result);

void	tester_func(t_list **tets);

#endif
