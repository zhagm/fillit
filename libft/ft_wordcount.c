/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:23:44 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/05 10:28:00 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordcount(char const *s, char delim)
{
	int		i;
	int		count;
	int		bool;

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
			}
		}
		i++;
	}
	return (count);
}
