/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:34:46 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/05 05:21:50 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j] == haystack[i + j])
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)(haystack + i));
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
