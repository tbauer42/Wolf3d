/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:54:00 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/29 11:53:42 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error(int x)
{
	if (x == 0)
		ft_putstr("MAP ERROR: not a 10x10 map\n");
	if (x == 1)
		ft_putstr("Wrong line\n");
	if (x == 2)
		ft_putstr("usage : ./wolf3d <filename>\n");
	if (x == 3)
		ft_putstr("Border are not full of walls\n");
	exit(0);
}
