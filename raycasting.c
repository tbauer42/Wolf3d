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

int	main(int argc, char **argv)
{
	double posX = 22;
	double posY = 12; // coor de position du joueur
	double dirX = -1;
	double dirY = 0; // direction du regard du joueur
	double planeX = 0;
	double planeY = 0.66; //version du plan de la camera
	double time = 0; // time of current frame
	double pretime = 0; // time of previous frame
	double cameraX = 0; // x-coordinate in camera space
	double rayDirX = 0;
	double rayDirY = 0;
	int x = 0;
	int  w = SCREEN_X;
	while (1) // gameloop that draws a whole frame and reads the input every time
	{
		while (x < w) // on dessine chaque pixel x pour dessiner chaque verticale, w etantla taille dune colonne de pixels
		{
			//calculate ray pos and direction
			cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
			rayDirX = dirX + planeX * cameraX;
			rayDirY = dirY + planeY * cameraX;
			x++;
		}
		//which box of the map we are include
		int mapX = (int)posX;
		int mapY = (int)posY;

		// lenght of ray from current position to the next x or y-side
		double sideDistX;
		double sideDistY;

		//lenght of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; // was there a wall hit ?
		int side; // was a NS or a EW wall hit ?
		//calculate step and initial sideDistX
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		//perform algo DDA
		while (hit == 0)
		{
			//ju;p to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldmap[mapX][mapY] > 0)
				hit = 1;
		}
		//calculate distance projected on camera direction 
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

}
