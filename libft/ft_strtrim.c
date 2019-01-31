/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:15:02 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/09 07:49:37 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*deal_with_empty_string(void)
{
	char	*res;

	if ((res = (char *)malloc(1 * sizeof(*res))) == NULL)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		l;
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start == l || s[0] == '\0' || l == 0)
		return (deal_with_empty_string());
	end = l - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	l = end - start + 1;
	if ((res = (char *)malloc((l + 1) * sizeof(*res))) == NULL)
		return (NULL);
	i = -1;
	while (++i < l)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}
