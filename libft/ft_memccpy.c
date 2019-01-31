/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:55:15 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/05 07:02:12 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		if (src_c[i] == (unsigned char)c)
			return (dst_c + i + 1);
		i++;
	}
	return (NULL);
}
