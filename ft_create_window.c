//
// Created by Аида Сайдашева on 02.03.2021.
//
#include "cub.h"

//
double radian(double degree)
{
	if (degree >= 360)
		degree = fmod(degree, 360);
	return (degree*PI/180);
}
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void texture_test(t_all *all)
{
	all->tex[0].img = mlx_xpm_file_to_image(all->img->mlx, all->params->no, &all->tex[0].width, &all->tex[0].height);
	all->tex[0].addr = mlx_get_data_addr(all->tex[0].img, &all->tex[0].bits_per_pixel, &all->tex[0].line_length,
										&all->tex[0].endian);
	all->tex[1].img = mlx_xpm_file_to_image(all->img->mlx, all->params->so, &all->tex[1].width, &all->tex[1].height);
	all->tex[1].addr = mlx_get_data_addr(all->tex[1].img, &all->tex[1].bits_per_pixel, &all->tex[1].line_length,
									   &all->tex[1].endian);
	all->tex[2].img = mlx_xpm_file_to_image(all->img->mlx, all->params->ea, &all->tex[2].width, &all->tex[2].height);
	all->tex[2].addr = mlx_get_data_addr(all->tex[2].img, &all->tex[2].bits_per_pixel, &all->tex[2].line_length,
									   &all->tex[2].endian);
	all->tex[3].img = mlx_xpm_file_to_image(all->img->mlx, all->params->we, &all->tex[3].width, &all->tex[3].height);
	all->tex[3].addr = mlx_get_data_addr(all->tex[3].img, &all->tex[3].bits_per_pixel, &all->tex[3].line_length,
									   &all->tex[3].endian);
	all->tex[4].img = mlx_xpm_file_to_image(all->img->mlx, all->params->s, &all->tex[4].width, &all->tex[4].height);
	all->tex[4].addr = mlx_get_data_addr(all->tex[4].img, &all->tex[4].bits_per_pixel, &all->tex[4].line_length,
										 &all->tex[4].endian);
}

void get_tex_color(t_all *all, int x, int y, int i)
{
	char *dst;
	dst = all->tex[i].addr + (y * all->tex[i].line_length + x * (all->tex[i].bits_per_pixel/8));
	all->tex[i].color = *(unsigned int *)dst;
}
//void put_the_wall(t_all *all, float c, size_t x)
//{
//	size_t column = (SCALE/ c) * all->ray->distance;
//	int starty = all->params->y/2 - column/2;
//	if (starty < 0)
//		starty = 0;
//	int endy = column/2 + all->params->y/2;
//	if (endy >= all->params->y)
//		endy = all->params->y - 1;
//	double step = 1.0  * all->texture->height/column;
//	double texPos = (starty - all->params->y/2 + column/2) * step;
//	int i;
//	i = 0;
//	while (i < starty)
//		my_mlx_pixel_put(all->img, x, i++, all->params->up);
//	while (i < endy && i < all->params->y)
//	{
//		int texY = (int)texPos & (all->texture->height - 1);
//		texPos += step;
//		get_tex_color(all, all->texture->texX, texY);
//		my_mlx_pixel_put(all->img, x, i++, all->texture->color);
//	}
//	while (i < all->params->y)
//		my_mlx_pixel_put(all->img, x, i++, all->params->down);
//}
//
//static int hit_the_wall(t_all *all, int x, int y)
//{
//	if (all->map->map[x>>6][y>>6] == '1')
//		return (1);
//	return (0);
//}
//
//static float distance_hor(t_all *all)
//{
//	int hit;
//	int Ax;
//	int Ay;
//	float tgn = tan(all->ray->angle);
//
//	Ay = (int)all->map->playery>>6 * 64 - 1;
//	Ax = (int)(all->map->playerx + (all->map->playery - Ay)/tgn);
//	hit = hit_the_wall(all, Ax, Ay);
//	while (hit != 1)
//	{
//		Ay -= 64;
//		Ax += (int)(64/tgn);
//		hit = hit_the_wall(all, Ax, Ay);
//	}
//	all->ray->hitx =
//	return (fabs((all->map->playerx - Ax)/cos(all->ray->angle)));
//}
//
//static float distance_ver(t_all *all, int i)
//{
//	int hit;
//	int Ax;
//	int Ay;
//	int Xa;
//	float tgn = tan(all->ray->angle);
//
//	Ax = (int)all->map->playerx>>6 * 64 + 64;
//	Xa = 64;
//	if (i < all->params->x/2)
//	{
//		Ax = (int) all->map->playerx >> 6 * 64 - 1;
//		Xa = -64;
//	}
//	Ay = (int)(all->map->playery + (all->map->playerx - Ax) * tgn);
//	hit = hit_the_wall(all, Ax, Ay);
//	while (hit != 1)
//	{
//		Ax += Xa;
//		Ay += 64 * tgn;
//		hit = hit_the_wall(all, Ax, Ay);
//	}
//	return (fabs((all->map->playerx - Ax)/cos(all->ray->angle)));
//}
//
//float opt(t_all *all, int i) {
//
//	// Старый метод
//	float c;
////	c = 0;
////	float cosinus = cos(all->ray->angle);
////	float sinus = sin(all->ray->angle);
////	while (all->map->map[(int)all->ray->x>>6][(int)all->ray->y>>6] != '1') {
////		c += 5;
////		all->ray->x = all->map->playerx + c * cosinus;
////		all->ray->y = all->map->playery + c * sinus;
////	}
////	if (c > 5)
////	c -= 5;
////	all->ray->x = all->map->playerx + c * cosinus;
////	all->ray->y = all->map->playery + c * sinus;
////	while (all->map->map[(int)all->ray->x>>6][(int)all->ray->y>>6] != '1') {
////		c += 1;
////		all->ray->x = all->map->playerx + c * cosinus;
////		all->ray->y = all->map->playery + c * sinus;
////	}
////	c -= 1;
////	all->ray->x = all->map->playerx + c * cosinus;
////	all->ray->y = all->map->playery + c * sinus;
////	while (all->map->map[(int)all->ray->x>>6][(int)all->ray->y>>6] != '1') {
////		c += 0.05;
////		all->ray->x = all->map->playerx + c * cosinus;
////		all->ray->y = all->map->playery + c * sinus;
//////		c += 0.0005;
////	}
////	c -= 0.05;
//
//// попытка permadi
//	//Поиск горизонтального пересечения
//	int hit = 0;
//	float distx = distance_hor(all);
//	float disty = distance_ver(all, i);
//
//	if (distx < disty)
//	{
//		all->map->side = 0;
//		all->texture->texX = hitx;
//	}
//	else
//	{
//		all->map->side = 1;
//		all->texture->texX = hity;
//	}
//	return (c * cos(all->ray->angle - all->map->rad));
//}
//
//static void draw_map(t_all *all) {
//	size_t i = 0;
//	all->map->rad = radian(all->map->playera);
//	float c;
//	while (i < all->params->x) {
//		all->ray->angle = all->map->rad + 0.523 - i * (1.047/all->params->x);
//		all->ray->x = all->map->playerx;
//		all->ray->y = all->map->playery;
//		put_the_wall(all, opt(all, i), i);
//		i++;
//	}
//	mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
////	printf("%lf\n", all->map->rad);
//}
//

//}
//
//

//
//	static int hit_the_wall(t_all *all, int x, int y)
//	{
//		printf("x %d y %d\n", x, y);
//		printf("x %d y %d\n", x>>6, y>>6);
////		printf("char is %c\n", all->map->map[x>>6][y>>6]);
//		if (x < 0 || y < 0)
//			return (-1);
//		if (all->map->map[x>>6][y>>6] == '1')
//			return (1);
//		return (0);
//	}
//
//static void distance_ver(t_all *all)
//{
//	t_dist hor;
//	int hit;
//
//	if (all->ray->angle == 90.0 || all->ray->angle == 270.0)
//	{
//		all->ray->distY = -1;
//		return ;
//	}
//
//	if (all->ray->angle > 90 && all->ray->angle < 270)
//	{
//		hor.Ax = ((int)all->map->playerx>>6) * 64 + 64;
//		hor.Xa = 64;
//	}
//	else {
//		hor.Ax = ((int)all->map->playerx>>6) * 64 - 1;
//		hor.Xa = -64;
//	}
//	hor.Ay = (int)(all->map->playery + (all->map->playerx - hor.Ax)/all->ray->tgn);
//	hor.Ya = (int)(64*all->ray->tgn);
//	hit = hit_the_wall(all, hor.Ax, hor.Ay);
//	while (hit == 0)
//	{
//		hor.Ax += hor.Xa;
//		hor.Ay += hor.Ya;
//		hit = hit_the_wall(all, hor.Ax, hor.Ay);
//	}
//	if (hit == 1)
//	{
//		all->ray->hity = hor.Ay % 64;
//		all->ray->distY = fabs((all->map->playerx - hor.Ax) / all->ray->cosinus);
//	}
//	else
//	{
//		all->ray->distY = -1;
//	}
//
//	printf("Ya %d Xa %d\n", hor.Ya, hor.Xa);
//	printf("Vertical Distance is %lf\n", all->ray->distY);
//}
//
//	static void distance_hor(t_all *all)
//	{
//		t_dist hor;
//		int hit;
//
//		printf("PlayerX %lf PlayerY %lf\n", all->map->playerx, all->map->playery);
//		if (all->ray->angle > 0 && all->ray->angle < 180)
//		{
//			hor.Ay = ((int)all->map->playery>>6) * 64 - 1;
//			hor.Ya = -64;
//		}
//		else {
//			hor.Ay = ((int)all->map->playery>>6) * 64 + 64;
//			hor.Ya = 64;
//		}
//		if (all->ray->angle == 90.0 || all->ray->angle == 270.0)
//		{
//			hor.Ax = all->map->playerx;
//			hor.Xa = 0;
//		}
////		printf("test 0\n");
//		else
//		{
//			hor.Ax = (int) (all->map->playerx + (all->map->playery - hor.Ay) / all->ray->tgn);
////		printf("test 1\n");
//			hor.Xa = (int) (64 / all->ray->tgn);
//		}
//		if (all->ray->angle == 90)
//		{
//			hor.Ax = all->map->playerx;
//			hor.Xa = 0;
//		}
//		hit = hit_the_wall(all, hor.Ax, hor.Ay);
//		while (hit == 0)
//		{
//			hor.Ay += hor.Ya;
//			hor.Ax += hor.Xa;
//			hit = hit_the_wall(all, hor.Ax, hor.Ay);
//		}
//		if (hit == 1) {
////		printf("test 2\n");
//			all->ray->hitx = hor.Ax % 64;
//			all->ray->distX = fabs((all->map->playerx - hor.Ax) / all->ray->cosinus);
//			if (all->ray->angle == 90.0 || all->ray->angle == 270.0)
//				all->ray->distX = fabs(all->map->playery - hor.Ay);
//		}
//		else
//			all->ray->distX = -1;
//		printf("Ya %d Xa %d\n", hor.Ya, hor.Xa);
//		printf("Horizontal Distance is %lf\nX %d Y %d\n", all->ray->distX, hor.Ax>>6, hor.Ay>>6);
//	}
//
//	static void put_the_wall(t_all *all, int x)
//	{
//		int column;
//		int starty;
//		int i;
//
//		column = (SCALE/all->ray->c) * all->ray->distance;
//		starty = all->params->y/2 - column/2;
//		i = starty;
//		double step = 1.0  * all->texture->height/column;
//		double texPos = (starty - all->params->y/2 + column/2) * step;
////		printf("column = %d, starty = %d\n", column, starty);
//		while (i < starty + column && i < all->params->y)
//		{
////			int texY = (int)texPos & (all->texture->height - 1);
////			texPos += step;
////			get_tex_color(all, all->texture->texX, texY);
////			printf("%d\n", i);
//			my_mlx_pixel_put(all->img, x, i++, 0x800800);
//		}
//	}
//
//	static void put_floor(t_all *all)
//	{
//		int x;
//		int y;
//
//		x = 0;
//		y = 0;
//		while (y < all->params->y/2)
//		{
//			x = 0;
//			while (x < all->params->x)
//			{
//				my_mlx_pixel_put(all->img, x, y, all->params->up);
//				x++;
//			}
//			y++;
//		}
//		while (y < all->params->y)
//		{
//			x = 0;
//			while (x < all->params->x)
//			{
//				my_mlx_pixel_put(all->img, x, y, all->params->down);
//				x++;
//			}
//			y++;
//		}
//	}
//
//	static void draw_map(t_all *all)
//	{
//		int i;
//
//		i = 0;
////		all->ray->angle = all->ray->pov - (all->ray->fov/2);
//		put_floor(all);
//		while (i < all->params->x)
//		{
//			printf("start %d\n", i);
//			all->ray->angle = all->map->playera - (all->ray->fov/2) + i * all->ray->col;
//
//			printf("i = %d ray is %lf\n",i, all->ray->angle);
////			printf("i = %d angle is %lf\n",i, all->ray->angle + all->map->playera);
//			all->ray->tgn = -tan(radian(all->ray->angle));
//			all->ray->cosinus = cos(radian(all->ray->angle));
//			printf("tan = %lf\n", all->ray->tgn);
////			printf("col is %lf\n", all->ray->col);
////			printf("pov is %d\n", all->map->playera);
////			printf("test 0\n");
//			distance_hor(all);
////			printf("test 1\n");
//			distance_ver(all);
////			printf("test 2\n");
//			if (all->ray->distY == -1 || all->ray->distX < all->ray->distY)
//			{
//				all->map->side = 0;
//				all->texture->texX = all->ray->hitx;
//				all->ray->c = all->ray->distX;
//			}
//			else if (all->ray->distX == -1 || all->ray->distY < all->ray->distX)
//			{
//				all->map->side = 1;
//				all->texture->texX = all->ray->hity;
//				all->ray->c = all->ray->distY;
//			}
//			printf("i = %d, distance = %lf\n", i, all->ray->c);
////			printf("DICTANCE %lf\n", all->ray->c);
//			put_the_wall(all, i);
//			i++;
//		}
//		mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
//	}
//static void press_s(t_all *all) {
//	float x;
//	float y;
//	int i;
//	float cosinus;
//	float sinus;
//
//	i = 0;
//	cosinus = cos(all->map->rad);
//	sinus = sin(all->map->rad);
////	while (i < SCALE / 4) {
////		mlx_clear_window(all->img->mlx, all->img->win);
//		x = all->map->playerx - cosinus * 8;
//		y = all->map->playery - sinus * 8;
//		if (all->map->map[(int) x / SCALE][(int) y / SCALE] &&
//			all->map->map[(int) x / SCALE][(int) y / SCALE] != '1') {
//			all->map->playerx -= cosinus;
//			all->map->playery -= sinus;
//		}
////		} else
////			i = SCALE / 4;
//
//		draw_map(all);
////		i++;
//	}
////}
////}
////
//	static void press_w(t_all *all) {
//		float x;
//		float y;
//		int i;
//		float cosinus;
//		float sinus;
////
//		cosinus = cos(all->map->rad);
//		sinus = sin(all->map->rad);
//		i = 0;
////		while (i < SCALE / 4) {
////		mlx_clear_window(all->img->mlx, all->img->win);
//			x = all->map->playerx + cosinus * 8;
//			y = all->map->playery + sinus * 8;
//			if (all->map->map[(int) (x) / SCALE][(int) y / SCALE] != '1') {
//				all->map->playerx += cosinus;
//				all->map->playery += sinus;
//			} else
////			{
////				i = SCALE / 4;
////			}
//			draw_map(all);
////			i++;
//		}
////	}


		void get_distance_params(t_all *all, t_dist *dist, int i)
		{
			dist->cameraX = 2 * i / (double)all->params->x - 1;
//			printf("camerax = %f\n", dist->cameraX);
			dist->rayDirX = all->map->dir_x + all->map->planeX * dist->cameraX;
			dist->rayDirY = all->map->dir_y + all->map->planeY * dist->cameraX;
			if (dist->rayDirY == 0)
				dist->deltaDistX = 0;
			else if (dist->rayDirX == 0)
				dist->deltaDistX = 1;
			else
				dist->deltaDistX= fabs(1/dist->rayDirX);
			if (dist->rayDirX == 0)
				dist->deltaDistY = 0;
			else if (dist->rayDirY == 0)
				dist->deltaDistY = 1;
			else dist->deltaDistY = fabs(1/dist->rayDirY);
		}

		void get_distance_params2(t_all *all, t_dist *dist)
		{
			dist->mapX = (int)all->map->playerx;
			dist->mapY = (int)all->map->playery;
			if (dist->rayDirX < 0)
			{
				dist->stepX = -1;
				dist->sideDistX = (all->map->playerx - dist->mapX) * dist->deltaDistX;
			}
			else
			{
				dist->stepX = 1;
				dist->sideDistX = (dist->mapX + 1.0 - all->map->playerx) * dist->deltaDistX;
			}
			if (dist->rayDirY < 0)
			{
				dist->stepY = -1;
				dist->sideDistY = (all->map->playery - dist->mapY) * dist->deltaDistY;
			}
			else
			{
				dist->stepY = 1;
				dist->sideDistY = (dist->mapY + 1.0 - all->map->playery) * dist->deltaDistY;
			}
		}

		void dda_distance2(t_all *all, t_dist *dist, int i, int x)
		{
			if (dist->side == 0) {
				dist->perpWallDist = (dist->mapX - all->map->playerx + (1 - dist->stepX) / 2) / dist->rayDirX;
				all->tex[i].wallX = all->map->playery + dist->perpWallDist * dist->rayDirY;
			}
			else {
				dist->perpWallDist = (dist->mapY - all->map->playery + (1 - dist->stepY) / 2) / dist->rayDirY;
				all->tex[i].wallX = all->map->playerx + dist->perpWallDist * dist->rayDirX;
			}
			all->tex[i].wallX -= floor(all->tex[i].wallX);
			all->tex[i].texX = (int)(all->tex[i].wallX * (double)all->tex[i].width);
			if (dist->side == 0 && dist->rayDirX > 0)
				all->tex[i].texX = all->tex[i].width - all->tex[i].texX - 1;
			if (dist->side == 1 && dist->rayDirY < 0)
				all->tex[i].texX = all->tex[i].width - all->tex[i].texX - 1;
		}

		int what_side(t_all *all, t_dist *dist)
		{
			if (dist->side == 0)
			{
				if (dist->rayDirX < 0)
					return (0);
				if (dist->rayDirX > 0)
					return (1);
			}
			if (dist->side == 1)
			{
				if (dist->rayDirY < 0)
					return (2);
				if (dist->rayDirY > 0)
					return (3);
			}
			return (0);
		}
		void dda_distance(t_all *all, t_dist *dist)
		{
			int hit;

			hit = 0;
			while (hit == 0)
			{
				if (dist->sideDistX < dist->sideDistY) {
					dist->sideDistX += dist->deltaDistX;
					dist->mapX += dist->stepX;
					dist->side = 0;
				} else {
					dist->sideDistY += dist->deltaDistY;
					dist->mapY += dist->stepY;
					dist->side = 1;
				}
				if (all->map->map[dist->mapX][dist->mapY] == '1')
					hit = 1;
			}
		}

		void put_the_wall(t_all *all, t_dist *dist, int x, int i)
		{
			t_draw draw;

			draw.lineHeight = (int)((1 / dist->perpWallDist) * all->map->dist);
			draw.drawStart = -draw.lineHeight / 2 + all->params->y / 2;
			if (draw.drawStart < 0)
				draw.drawStart = 0;
			draw.drawEnd = draw.lineHeight / 2 + all->params->y / 2;
			if (draw.drawEnd >= all->params->y)
				draw.drawEnd = all->params->y - 1;
			draw.step = 1.0 * all->tex[i].height / draw.lineHeight;
			draw.texPos = (draw.drawStart - all->params->y / 2 + draw.lineHeight / 2) * draw.step;
			while (draw.drawStart < draw.drawEnd)
			{
				draw.texY = (int)draw.texPos & (all->tex[i].height - 1);
				draw.texPos += draw.step;
				get_tex_color(all, all->tex[i].texX, draw.texY, i);
				my_mlx_pixel_put(all->img, x, draw.drawStart++, all->tex[i].color);
			}

//			printf("dist = %f\n", dist->perpWallDist);
		}

		void sprite_sort(t_sprite *sp, int x)
		{
			int		i;
			int		j;
			t_sprite temp;

			i = 0;
			while (i < x)
			{
				j = x;
				while (j  > i)
				{
					if (sp[j - 1].dis < sp[j].dis)
					{
//						temp = sp[j - 1].dis;
//						sp[j - 1].dis = sp[j].dis;
//						sp[j].dis = temp;
						temp.x = sp[j - 1].x;
						temp.y = sp[j - 1].y;
						temp.dis = sp[j - 1].dis;
						sp[j - 1].x = sp[j].x;
						sp[j - 1].y = sp[j].y;
						sp[j - 1].dis = sp[j].dis;
						sp[j].x = temp.x;
						sp[j].y = temp.y;
						sp[j].dis = temp.dis;
					}
					j--;
				}
				i++;
			}
		}

		void sprite_dis(t_sprite *sp, int x, float posX, float posY)
		{
			int i;

			i = 0;
			while (i < x)
			{
				sp[i].dis = (posX - sp[i].x) * (posX - sp[i].x) + (posY - sp[i].y) * (posY - sp[i].y);
				i++;
			}
			sprite_sort(sp, x - 1);
//			i = 0;
//			while (i < x)
//			{
//				printf("dis = %f\n", sp[i].dis);
//				i++;
//			}
		}

		void get_drawSpriteParams(t_all *all, t_drawSprite *ds)
		{
			int i;

			i = 0;
			while (i < all->map->sprite)
			{
				ds->spriteX = all->map->sp[i].x - all->map->playerx;
				ds->spriteY = all->map->sp[i].y - all->map->playery;
				printf("x %f, y %f\n", ds->spriteX, ds->spriteY);
				ds->invDet = 1.0 / (all->map->planeX * all->map->dir_y - all->map->dir_x * all->map->planeY);
				ds->transformX = ds->invDet * (all->map->dir_y * ds->spriteX - all->map->dir_x * ds->spriteY);
				ds->transformY = ds->invDet * (-all->map->planeY * ds->spriteX + all->map->planeX * ds->spriteY);
//				printf("transformY %f\n", ds->transformY);
				ds->spriteScreenX = (int)((all->params->x / 2) * (1 + ds->transformX / ds->transformY));
//				printf("screenX %d\n", ds->spriteScreenX);
				ds->spriteHeight = abs((int)(all->params->y / ds->transformY));
				ds->drawStartY = -ds->spriteHeight / 2 + all->params->y / 2;
				if (ds->drawStartY < 0)
					ds->drawStartY = 0;
				ds->drawEndY = ds->spriteHeight / 2 + all->params->y / 2;
				if (ds->drawEndY >= all->params->y)
					ds->drawEndY = all->params->y - 1;
				ds->spriteWidth = abs((int)(all->params->y / ds->transformY));

//				printf("width %d\n", ds->spriteWidth);
				ds->drawStartX =  ds->spriteScreenX - ds->spriteWidth / 2;
				if (ds->drawStartX < 0)
					ds->drawStartX = 0;
				ds->drawEndX = ds->spriteWidth / 2 + ds->spriteScreenX;
				if (ds->drawEndX >= all->params->x)
					ds->drawEndX = all->params->x - 1;
				ds->stripe = ds->drawStartX;
//				printf("stripe %d EndX %d\n", ds->stripe, ds->drawEndX);
				while (ds->stripe < ds->drawEndX)
				{
					ds->texX = (int)(256 * (ds->stripe - (-ds->spriteWidth / 2 + ds->spriteScreenX)
							 * all->tex[4].width / ds->spriteWidth) / 256);
					if (ds->transformY > 0 && ds->stripe > 0 && ds->stripe < all->params->x && ds->transformY < all->ZBuffer[ds->stripe])
						ds->y = ds->drawStartY;
						while (ds->y < ds->drawEndY)
						{
							ds->d = (ds->y) * 256 - all->params->y * 128 + ds->spriteHeight * 128;
							ds->texY = ((ds->d * all->tex[4].height) / ds->spriteHeight) / 256;
							get_tex_color(all, ds->texX, ds->texY, 4);
							if ((all->tex[4].color & 0xFFFFFF) != 0)
								my_mlx_pixel_put(all->img, ds->stripe, ds->y, all->tex[4].color);
							ds->y++;
						}
					ds->stripe++;
				}

//				printf("hello\n");
				i++;
			}
		}

		void put_sprites(t_all *all)
		{
			t_drawSprite ds;

			sprite_dis(all->map->sp, all->map->sprite, all->map->playerx, all->map->playery);
			get_drawSpriteParams(all, &ds);

		}
		static void put_floor(t_all *all)
		{
			int x;
			int y;

			x = 0;
			y = 0;
			while (y < all->params->y/2)
			{
				x = 0;
				while (x < all->params->x)
				{
					my_mlx_pixel_put(all->img, x, y, all->params->up);
					x++;
				}
				y++;
			}
			while (y < all->params->y)
			{
				x = 0;
				while (x < all->params->x)
				{
					my_mlx_pixel_put(all->img, x, y, all->params->down);
					x++;
				}
				y++;
			}
		}
		void draw_map(t_all *all)
		{
			t_dist dist;
			int i;
			int x;

			i = 0;
			put_floor(all);
			while (i < all->params->x)
			{
				get_distance_params(all, &dist, i);
				get_distance_params2(all, &dist);
				dda_distance(all, &dist);
				x = what_side(all, &dist);
				dda_distance2(all, &dist, x, i);

				all->ZBuffer[i] = dist.perpWallDist;
//				printf("%f\n", all->ZBuffer[i]);
				put_the_wall(all, &dist, i, x);
				put_sprites(all);
				i++;
			}
			mlx_put_image_to_window(all->img->mlx, all->img->win, all->img->img, 0, 0);
		}

		void press_s(t_all *all)
		{
			double tempX;
			double tempY;

			tempX = all->map->playerx - all->map->dir_x * 2 * MOVESPEED;
			tempY = all->map->playery - all->map->dir_y * 2 * MOVESPEED;
			if (all->map->map[(int)tempX][(int)all->map->playery] != '1')
				if (all->map->map[(int)tempX][(int)all->map->playery] != '2')
					all->map->playerx -= all->map->dir_x *  MOVESPEED;
			if (all->map->map[(int)all->map->playerx][(int)tempY] != '1')
				if (all->map->map[(int)all->map->playerx][(int)tempY] != '2')
					all->map->playery -= all->map->dir_y  * MOVESPEED;
			draw_map(all);
		}

		void press_w(t_all *all)
		{
			double tempX;
			double tempY;

			tempX = all->map->playerx + all->map->dir_x * 2 * MOVESPEED;
			tempY = all->map->playery + all->map->dir_y * 2 * MOVESPEED;
			if (all->map->map[(int)tempX][(int)all->map->playery] != '1')
				if (all->map->map[(int)tempX][(int)all->map->playery] != '2')
					all->map->playerx += all->map->dir_x *  MOVESPEED;
			if (all->map->map[(int)all->map->playerx][(int)tempY] != '1')
				if (all->map->map[(int)all->map->playerx][(int)tempY] != '2')
					all->map->playery += all->map->dir_y  * MOVESPEED;
			draw_map(all);
		}

		void press_right(t_all *all)
		{
			double speed;
			double oldDirX;
			double oldPlaneX;

			speed = 0.0872665;
			oldDirX = all->map->dir_x;
			oldPlaneX = all->map->planeX;
			all->map->dir_x = all->map->dir_x * cos(-speed) - all->map->dir_y * sin(-speed);
			all->map->dir_y = oldDirX * sin(-speed) + all->map->dir_y * cos(-speed);
			all->map->planeX = all->map->planeX * cos(-speed) - all->map->planeY * sin(-speed);
			all->map->planeY = oldPlaneX * sin(-speed) + all->map->planeY * cos(-speed);
			draw_map(all);
		}

		void press_left(t_all *all)
		{
			double speed;
			double oldDirX;
			double oldPlaneX;

			speed = 0.0872665;
			oldDirX = all->map->dir_x;
			oldPlaneX = all->map->planeX;
			all->map->dir_x = all->map->dir_x * cos(speed) - all->map->dir_y * sin(speed);
			all->map->dir_y = oldDirX * sin(speed) + all->map->dir_y * cos(speed);
			all->map->planeX = all->map->planeX * cos(speed) - all->map->planeY * sin(speed);
			all->map->planeY = oldPlaneX * sin(speed) + all->map->planeY * cos(speed);
			draw_map(all);
		}

		void press_d(t_all *all)
		{
			double tempX;
			double tempY;

			tempX = all->map->playerx + all->map->dir_y * 2 * MOVESPEED;
			tempY = all->map->playery - all->map->dir_x * 2 * MOVESPEED;
			if (all->map->map[(int)tempX][(int)all->map->playery] != '1')
				if (all->map->map[(int)tempX][(int)all->map->playery] != '2')
				all->map->playerx += all->map->dir_y * MOVESPEED;
			if (all->map->map[(int)all->map->playerx][(int)tempY] != '1')
				if (all->map->map[(int)all->map->playerx][(int)tempY] != '2')
				all->map->playery -= all->map->dir_x * MOVESPEED;
			draw_map(all);
		}
		void press_a(t_all *all)
		{
			double tempX;
			double tempY;

			tempX = all->map->playerx - all->map->dir_y * 2 * MOVESPEED;
			tempY = all->map->playery + all->map->dir_x * 2 * MOVESPEED;
			if (all->map->map[(int)tempX][(int)all->map->playery] != '1')
				if (all->map->map[(int)tempX][(int)all->map->playery] != '2')
				all->map->playerx -= all->map->dir_y * MOVESPEED;
			if (all->map->map[(int)all->map->playerx][(int)tempY] != '1')
				if (all->map->map[(int)all->map->playerx][(int)tempY] != '2')
				all->map->playery += all->map->dir_x * MOVESPEED;
			draw_map(all);
		}

		int key_hook(int key, t_all *all) {
			if (key == 13)
				press_w(all);
			if (key == 1)
				press_s(all);
			if (key == 124)
				press_right(all);
			if (key == 123)
				press_left(all);
			if (key == 2)
				press_d(all);
			if (key == 0)
				press_a(all);
			if (key == 53) {
				mlx_destroy_window(all->img->mlx, all->img->win);
				exit(0);
			}
			return (0);
		}

		void ft_create_window(t_all *all) {
//		radian(360 * 2);
//		printf("%d\n", (int)64.7>>6);
			all->img->mlx = mlx_init();
			all->img->win = mlx_new_window(all->img->mlx, all->params->x, all->params->y, "cub3D");
			all->img->img = mlx_new_image(all->img->mlx, all->params->x, all->params->y);
			all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bits_per_pixel, &all->img->line_length,
											   &all->img->endian);
//			all->ray->fov = 60;
//			all->ray->col = (float)all->ray->fov/all->params->x;
//			printf("col is %lf, fov %d, x %d\n", all->ray->col,all->ray->fov, all->params->x );
//			all->ray->distance = (all->params->x / 2) / tan(radian(all->ray->fov / 2));
			texture_test(all);
			all->map->dist = (all->params->x / 2) / tan(0.575959);
			draw_map(all);
//			printf("%f\n", all->ZBuffer[0]);
//		all->texture->img = mlx_xpm_file_to_image(all->img->mlx, all->params->no, &all->texture->width, &all->texture->height);
//			draw_map(all);
//		printf("%lf\n", all->map->rad);
			mlx_hook(all->img->win, 2, (1L << 0), &key_hook, all);

			mlx_loop(all->img->mlx);
		}
