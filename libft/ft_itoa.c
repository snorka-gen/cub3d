/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:46:26 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/06 16:57:50 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(unsigned int n)
{
	int count;

	count = 1;
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*ft_number(unsigned int n, int minus, int power)
{
	char *str;

	if (!(str = (char *)malloc(power + minus + 1)))
		return (NULL);
	str[power + minus] = '\0';
	if (minus == 1)
		str[0] = '-';
	while (n >= 10)
	{
		str[--power + minus] = n % 10 + 48;
		n = n / 10;
	}
	str[--power + minus] = n + 48;
	return (str);
}

char		*ft_itoa(int n)
{
	int				minus;
	unsigned int	res;

	minus = 0;
	if (n < 0)
	{
		minus = 1;
		res = -n;
		return (ft_number(res, minus, power(res)));
	}
	return (ft_number((unsigned int)n, minus, power(n)));
}
