/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:08:10 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/07 07:44:17 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			else if (s1[i] == s2[i])
				i++;
		}
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
