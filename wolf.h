/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/29 14:28:31 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "Libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define NBR_THREADS 4
# define KEY_PLUS 69
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define SCREEN_X 500
# define SCREEN_Y 500
typedef struct			s_env
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double pretime;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int x;
	int w;
	int mapX;
	int mapY;
	double deltaDistX;
	double deltaDistY;
	int hit;
	double sideDistX;
	double sideDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;

}						t_env;

typedef struct			s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_ptr;
	char	*str;

	double	zoom;
	double	position_y;
	double	position_x;

	double	xmouse;
	double	ymouse;
	int		x;
	int		y;
	double	screeny;
	double	screenx;
}						t_data;

typedef struct			s_map
{
	int		nb_lines;
	int		nb_num;
	int		i;
	int		j;
	int		**tab;
}						t_map;

void		ft_init(t_data *frac);
void		ft_verif(char *file, t_data *wolf);
void		ft_error(int x);

#endif
