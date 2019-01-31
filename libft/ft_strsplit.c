/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 04:26:29 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/09 07:47:27 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char			*get_word(char const *s, char c, unsigned int start)
{
	unsigned int	end;
	unsigned int	len;
	char			*res;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	len = end - start;
	res = ft_strsub(s, start, len);
	return (res);
}

static unsigned int	get_nth_start(char const *s, char delim, unsigned int index)
{
	unsigned int	i;
	unsigned int	count;
	int				bool;

	i = 0;
	count = 0;
	bool = 0;
	while (s[i])
	{
		if (s[i] == delim)
			bool = 0;
		else
		{
			if (bool == 0)
			{
				bool = 1;
				count++;
				if (count == index + 1)
					return (i);
			}
		}
		i++;
	}
	return (0);
}

char				**ft_strsplit(char const *s, char c)
{
	int				wc;
	int				i;
	char			**res;
	unsigned int	start;

	if (!s || !c)
		return (NULL);
	wc = ft_wordcount(s, c);
	if ((res = (char **)malloc((wc + 1) * sizeof(*res))) == NULL)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		start = get_nth_start(s, c, i);
		res[i] = get_word(s, c, start);
		i++;
	}
	res[wc] = NULL;
	return (res);
}
