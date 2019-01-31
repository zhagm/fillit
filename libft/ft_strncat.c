/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 07:02:36 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/03 07:12:52 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	s1_end;

	s1_end = 0;
	while (s1[s1_end])
		s1_end++;
	i = 0;
	while (s2[i] && i < n)
	{
		s1[s1_end + i] = s2[i];
		i++;
	}
	s1[s1_end + i] = '\0';
	return (s1);
}
