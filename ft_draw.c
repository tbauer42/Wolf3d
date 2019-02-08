/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:59:33 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/07 16:41:13 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_pixel_image(int x, int y, int color, const t_data *wolf)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	wolf->str[(x * 4) + ((int)SCREEN_X * 4 * y)] = b;
	wolf->str[(x * 4) + ((int)SCREEN_X * 4 * y) + 1] = g;
	wolf->str[(x * 4) + ((int)SCREEN_X * 4 * y) + 2] = r;
}

void	draw(int x, const t_data *wolf, t_obstacle ob)
{
	int	y;

	y = SCREEN_Y / 2 - ob.h / 2;
	while (y < SCREEN_Y / 2 + ob.h / 2 && y < SCREEN_Y - 1)
	{
		if (y < SCREEN_Y && y >= 0)
			put_pixel_image(x, y, 0x00FFFF, wolf);
		y++;
	}
	y--;
	while (++y < SCREEN_Y)
		put_pixel_image(x, y, 0xFF0000, wolf);
}
