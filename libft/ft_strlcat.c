/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 07:18:32 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/09 06:38:15 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_end;
	size_t	src_len;

	dst_end = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_end;
	j = 0;
	if (dst_end + 1 > dstsize)
		return (src_len + dstsize);
	if (dst_end + 1 < dstsize)
	{
		while (i < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (dst_end + src_len);
}
