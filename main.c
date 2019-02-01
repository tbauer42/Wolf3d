/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:19:44 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/29 15:04:52 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_algo(t_data *wolf)
{
	wolf->img_ptr[1] = 500 * 0x00FFFF;
}

void		put_pixel(int x, int y, int color, t_data *wolf)
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
	wolf->str[(x * 4) + ((int)SCREEN_X * 4 * y) + 3] = 0;
}

static int	deal_key(int key, t_data *wolf)
{
	if (key == KEY_ESC)
		exit(0);
	/*mlx_destroy_image(wolf->mlx, wolf->img);
	wolf->img = mlx_new_image(wolf->mlx, SCREEN_X, SCREEN_Y);
	wolf->img_ptr = (int*)mlx_get_data_addr(wolf->img, &key, &key, &key);
	render(wolf);*/
	return (0);
}

/*static int	mouse_hook(int button, int x, int y, t_data *wolf)
{
	if (button == 4 || button == 1)
	{
		wolf->xmouse = x / (double)wolf->zoom - (SCREEN_X
		/ (double)(wolf->zoom * 2) + wolf->position_x) + wolf->xmouse;
		wolf->ymouse = y / (double)wolf->zoom - (SCREEN_Y
		/ (double)(wolf->zoom * 2) + wolf->position_y) + wolf->ymouse;
		wolf->position_y = 0;
		wolf->position_x = 0;
		wolf->zoom = wolf->zoom * 2;
	}
	if (button == 5 || button == 2)
		wolf->zoom = wolf->zoom * 0.5;
	render(wolf);
	return (0);
}*/

int			main(int argc, char **argv)
{
	t_data	wolf;
	int		i;

	i = 5;
	if (argc == 2)
	{
		ft_verif(argv[1], &wolf);
		ft_init(&wolf);
		wolf.img_ptr = (int *)mlx_get_data_addr(wolf.img, &i, &i, &i);
		//render(&wolf);
		ft_algo(&wolf);
		mlx_key_hook(wolf.win, deal_key, &wolf);
		//mlx_mouse_hook(wolf.win, mouse_hook, &wolf);
		//mlx_hook(wolf.win, 6, (1L << 6), funct, &wolf);
		mlx_loop(wolf.mlx);
	}
	else
		ft_error(2);
	return (0);
}
