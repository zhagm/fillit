/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:51:56 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/06 10:00:42 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		bool;

	bool = 0;
	i = 0;
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		while (i < n && s1[i] && s2[i])
		{
			if (s1[i] == s2[i])
				bool = 1;
			else
				return (0);
			i++;
		}
		if (i != n && ((s1[i] && !s2[i]) || (!s1[i] && s2[i])))
			return (0);
	}
	return (bool);
}
