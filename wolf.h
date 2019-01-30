/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:58:31 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/29 15:46:04 by ochaar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "libft/libft.h"
# include <stdio.h>

# define NBR_THREADS 4
# define KEY_PLUS 69
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define SCREEN_X 500
# define SCREEN_Y 500

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
