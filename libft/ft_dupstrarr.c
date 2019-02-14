/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:43:15 by zmagauin          #+#    #+#             */
/*   Updated: 2019/02/09 19:43:25 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_dupstrarr(char **src)
{
	char	**dest;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (src[l])
		l++;
	dest = (char **)malloc((l + 1) * sizeof(char *));
	while (i < l)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
