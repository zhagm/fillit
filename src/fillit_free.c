/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:39:57 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/11 18:39:59 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    free_board(char **board) // frees char**
{
    int i;

    i = 0;
    if (board)
    {
        while (board[i])
        {
            free(board[i]);
            i++;
        }
    }
}

void    free_tet(t_tet *tet) // frees t_tet, which has char**
{
    if (tet)
    {
        if (tet->tetrimino)
            free_board(tet->tetrimino);
        free(tet);
    }
}

void    free_tet_list(t_list *list) // frees list with t_tets
{
    t_list  *hold;
    t_tet   *tet;
	char	**tet_arr;

    while (list)
    {
        hold = list->next;
        if (list->content)
        {
            tet = list->content;
            tet_arr = tet->tetrimino;
            free_tet(list->content);
        }
        free(list);
        list = hold;
    }
}
