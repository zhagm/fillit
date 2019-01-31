/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 08:25:51 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/09 08:55:01 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src_c;
	char	*dst_c;
	int		i;

	src_c = (char *)src;
	dst_c = (char *)dst;
	if (src_c < dst_c)
	{
		i = ((int)len) - 1;
		while (i >= 0)
		{
			dst_c[i] = src_c[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((unsigned int)i < len)
		{
			dst_c[i] = src_c[i];
			i++;
		}
	}
	return (dst);
}
