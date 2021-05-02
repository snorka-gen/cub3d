/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:53:22 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 11:53:25 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_map	*ft_map_init(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(t_map))))
		ft_check_error("Malloc Error\n");
	map->len = 0;
	map->count = 0;
	map->player = 0;
	map->map = NULL;
	map->sprite = 0;
	return (map);
}
