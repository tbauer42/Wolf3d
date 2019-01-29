/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochaar <ochaar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:42:32 by ochaar            #+#    #+#             */
/*   Updated: 2019/01/29 14:24:59 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_count(char *line, char c)
{
	int i;
	int len;
	int nb;

	i = 0;
	nb = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
		{
			if (ft_isdigit(line[i]) == 1)
			{
				i++;
				nb++;
			}
		}
	}
	return (nb);
}

void	ft_free(char **dst)
{
	int		k;

	k = 0;
	while (dst[k])
	{
		free(dst[k]);
		k++;
	}
	free(dst);
}

void	ft_check_walls(t_map *data)
{
	int		i;

	i = 0;
	while (i < data->nb_num)
	{
		if (data->tab[0][i] != 1)
			ft_error(3);
		else if (data->tab[9][i] != 1)
			ft_error(3);
		i++;
	}
	i = 0;
	while (i < data->nb_num)
	{
		if (data->tab[i][0] != 1)
			ft_error(3);
		else if (data->tab[i][9] != 1)
			ft_error(3);
		i++;
	}
}

void	read_data(char *file, t_map *data)
{
	char	**dst;
	char	*line;
	int		fd;

	data->i = 0;
	fd = open(file, O_RDONLY);
	data->tab = (int**)malloc(sizeof(int*) * data->nb_lines);
	while (data->i < data->nb_lines)
	{
		data->j = 0;
		get_next_line(fd, &line);
		dst = ft_strsplit(line, ' ');
		data->tab[data->i] = (int*)malloc(sizeof(int) * (data->nb_num));
		while (dst[data->j])
		{
			data->tab[data->i][data->j] = ft_atoi(dst[data->j]);
			data->j++;
		}
		ft_free(dst);
		free(line);
		data->i++;
	}
	close(fd);
	ft_check_walls(data);
}

void	ft_verif(char *file, t_data *wolf)
{
	int		fd;
	char	*line;
	int		ret;
	t_map	data;

	data.nb_lines = 0;
	data.nb_num = 0;
	fd = open(file, O_RDONLY);
	/*if (fd <= 0)
		ft_error();*/
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		data.nb_num = ft_count(line, ' ');
		if (data.nb_num != 10)
			ft_error(1);
		data.nb_lines++;
		free(line);
	}
	if (data.nb_lines != 10)
		ft_error(0);
	close(fd);
	read_data(file, &data);
}

void	ft_init(t_data *frac)
{
	frac->xmouse = 0;
	frac->ymouse = 0;
	frac->zoom = (SCREEN_X + SCREEN_Y) / 8;
	frac->position_x = 0;
	frac->position_y = 0;
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, SCREEN_X, SCREEN_Y, "WOLF3D");
	frac->img = mlx_new_image(frac->mlx, SCREEN_X, SCREEN_Y);
}