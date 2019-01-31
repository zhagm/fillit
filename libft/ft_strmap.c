/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:11:25 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/05 07:16:25 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		l;
	int		i;
	char	*mapped_str;

	l = 0;
	while (s && s[l])
		l++;
	if ((mapped_str = (char *)malloc((l + 1) * sizeof(*mapped_str))) == NULL)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		mapped_str[i] = f(s[i]);
		i++;
	}
	mapped_str[i] = '\0';
	return (mapped_str);
}
