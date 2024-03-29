/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:54:03 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:54:05 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_struct	*ft_struct_init(void)
{
	t_struct *params;

	if (!(params = malloc(sizeof(t_struct))))
		ft_check_error("Malloc Error\n");
	params->y = 0;
	params->x = 0;
	if (!(params->sky = malloc(sizeof(int) * 3)))
		ft_check_error("Malloc Error\n");
	params->sky[0] = -1;
	if (!(params->floor = malloc(sizeof(int) * 3)))
		ft_check_error("Malloc Error\n");
	params->floor[0] = -1;
	if (!(params->tex = (char**)malloc(sizeof(char *) * 5)))
		ft_check_error("Malloc Error\n");
	params->tex[0] = NULL;
	params->tex[1] = NULL;
	params->tex[2] = NULL;
	params->tex[3] = NULL;
	params->tex[4] = NULL;
	return (params);
}
