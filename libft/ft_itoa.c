/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmagauin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:02:48 by zmagauin          #+#    #+#             */
/*   Updated: 2018/12/09 05:59:04 by zmagauin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		get_digits(int n)
{
	int		digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char			*ft_itoa(int n)
{
	int		l;
	int		neg;
	char	*res;

	neg = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n = -n;
		neg = 1;
	}
	l = get_digits(n) + neg + 1;
	if ((res = (char *)malloc(l * sizeof(*res))) == NULL)
		return (NULL);
	res[--l] = '\0';
	while (l--)
	{
		res[l] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
