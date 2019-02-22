/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:59:33 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/21 14:55:28 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_put_pixel(int x, int y, int color, const t_data *wolf)
{
	int	i;

	i = x * 4 + wolf->sizel * y;
	wolf->str[i] = color & 0xff;
	wolf->str[++i] = (color >> 8) & 0xff;
	wolf->str[++i] = (color >> 16) & 0xff;
}

int		get_color(int y, t_data wolf, t_obstacle ob)
{
	int color;

	y = ((double)y / ob.h / 4) * PRES;
	color = wolf.str_w[(ob.col * 4) + ((int)PRES * 4 * y)];
	color += wolf.str_w[(ob.col * 4) + ((int)PRES * 4 * y) + 1] * 256;
	color += (wolf.str_w[(ob.col * 4) + ((int)PRES * 4 * y) + 2] * 256) * 256;
	return (color);
}

void	draw(int x, const t_data *wolf, t_obstacle ob)
{
	int	y;
	int	yim;
	unsigned int color;

	y = SCREEN_Y / 2 - ob.h / 2;
	yim = 0;
	while (y < SCREEN_Y / 2 + ob.h / 2 && y < SCREEN_Y - 1)
	{
		if (y < SCREEN_Y && y >= 0)
		{
			color = get_color(yim, *wolf, ob);
			ft_put_pixel(x, y, color, wolf);
		}
		y++;
		yim++;
	}
	y--;
	while (++y < SCREEN_Y)
		ft_put_pixel(x, y, 0x708090, wolf);
}
