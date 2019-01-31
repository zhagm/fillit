/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:20:53 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/05 07:15:21 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		l;
	int		i;
	char	*mapped_str;

	if (s == NULL || f == NULL)
		return (NULL);
	l = 0;
	while (s && s[l])
		l++;
	if ((mapped_str = (char *)malloc((l + 1) * sizeof(*mapped_str))) == NULL)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		mapped_str[i] = f(i, s[i]);
		i++;
	}
	mapped_str[i] = '\0';
	return (mapped_str);
}
