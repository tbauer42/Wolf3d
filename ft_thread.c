/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:08:15 by ochaar            #+#    #+#             */
/*   Updated: 2019/02/09 14:07:19 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	*thread(t_worker_arg *arg)
{
	const t_data	*wolf = arg->wolf;
	t_obstacle		ob;
	double			alpha;
	int				x;

	x = arg->start * 50;
	while (x < (arg->start + 1) * 50)
	{
		alpha = (wolf->player.dirx + (wolf->player.fov / 2)) -
			((wolf->player.fov / SCREEN_X) * x);
		ft_wall_detect(&ob, *wolf, alpha);
		draw(x, wolf, ob);
		x++;
	}
	return (NULL);
}
