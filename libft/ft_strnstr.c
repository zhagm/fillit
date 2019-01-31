/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:08:40 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/05 05:17:45 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j] == haystack[i + j] && i + j < len)
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
