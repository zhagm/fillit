/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:12:25 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/02 03:42:01 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		l;
	int		i;

	l = 0;
	while (s1[l])
		l++;
	if ((res = (char *)malloc((l + 1) * sizeof(*res))) == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		res[i] = s1[i];
		i++;
	}
	res[l] = '\0';
	return (res);
}
