/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:34:21 by tbauer            #+#    #+#             */
/*   Updated: 2019/01/29 17:13:36 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	void	init_var(t_env *e, int x)
{
	e->posX = 22;
	e->posY = 12; // coor de position du joueur
	e->dirX = -1;
	e->dirY = 0; // direction du regard du joueur
	e->planeX = 0;
	e->planeY = 0.66; //version du plan de la camera
	e->time = 0; // time of current frame
	e->pretime = 0; // time of previous frame 
	e->x = 0;
	e->cameraX = 2 * x / (double)SCREEN_X - 1; //x-coordinate in camera space
	e->rayDirX = dirX + planeX * cameraX;
	e->rayDirY = dirY + planeY * cameraX;
	e->mapX = (int)posX;
	e->mapY = (int)posY;
	e->deltaDistX = fabs(1 / rayDirX);
	e->deltaDistY = fabs(1 / rayDirY);
	e->hit = 0;
}
	double sideDistX;
	double sideDistY;
	double perpWallDist;
	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;
	int hit = 0; // was there a wall hit ?
	int side; // was a NS or a EW wall hit ?
		//calculate step and initial sideDistX
static	void	init_dir(t_env *e)
{
	if (e->rayDirX < 0)
	{
		e->stepX = -1;
		e->sideDistX = (e->posX - e->mapX) * e->deltaDistX;
	}
	else
	{
		e->stepX = 1;
		e->sideDistX = (e->mapX + 1.0 - e->posX) * e->deltaDistX;
	}
	if (e->rayDirY < 0)
	{
		e->stepY = -1;
		e->sideDistY = (e->posY - e->mapY) * e->deltaDistY;
	}
	else
	{
		e->stepY = 1;
		e->sideDistY = (e->mapY + 1.0 - e->posY) * e->deltaDistY;
	}
}

static	void	dda_algo(t_env *e)
{
	init_dir(e);
	while (e->hit == 0)
	{
	//ju;p to next map square, OR in x-direction, OR in y-direction
		if (e->sideDistX < e->sideDistY)
		{
			e->sideDistX += e->deltaDistX;
			e->mapX += e->stepX;
			e->side = 0;
		}
		else
		{
			e->sideDistY += e->deltaDistY;
			e->mapY += e->stepY;
			e->side = 1;
		}
		//Check if ray has hit a wall
		if (worldmap[e->mapX][e->mapY] > 0) // a adpater avec data->tab[i][j]
			e->hit = 1;
	}

static	void	dist_calc(t_env *e)
{
	//calculate distance projected on camera direction 
	if (e->side == 0)
		e->perpWallDist = (e->mapX - e->posX + (1 - e->stepX) / 2) / e->rayDirX;
	else
		e->perpWallDist = (e->mapY - e->posY + (1 - e->stepY) / 2) / e->rayDirY;
	//calculate height of line to draw on screen 
	e->lineHeight = (int)(SCREEN_Y / e->perpWallDist)
	//calculate lowest and highest pixel to fill in current stripe
	e->drawStart = - e->lineHeight / 2 + SCREEN_Y / 2;
	if (e->drawStart < 0)
		e->drawStart = 0;
	e->drawEnd = e->lineHeight / 2 + SCREEN_Y / 2;
	if (e->drawEnd >= SCREEN_Y)
		e->drawEnd = SCREEN_Y - 1;
}

int		raycasting(t_env *e)
{
	int	x;
	x = 0;
	while(x < SCREEN_X)
	{
		init_var(e, x);
		dda_algo(e);
		dist_calc(e);
		draw();
		x++;
	}
	return (0);
}

