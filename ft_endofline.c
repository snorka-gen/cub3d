/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endofline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:51:52 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:51:53 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_endofline(char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			ft_check_error("Something get wrong with map\n");
		i++;
	}
}
