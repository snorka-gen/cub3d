/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:38:50 by fcassey           #+#    #+#             */
/*   Updated: 2020/11/04 18:21:03 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		minus;
	int		res;

	minus = 0;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			minus++;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (minus % 2 == 0)
		return (res);
	return (-res);
}
