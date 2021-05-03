/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_sprite_things.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcassey <fcassey@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 20:37:59 by fcassey           #+#    #+#             */
/*   Updated: 2021/05/02 20:38:01 by fcassey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sprite_texx(t_all *all, t_drawsprite *ds)
{
	ds->texx = (int)(256 * (ds->stripe - (-ds->spritewidth / 2 +
			ds->spritescreenx)) * all->tex[4].width / ds->spritewidth) / 256;
}
