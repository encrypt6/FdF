/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/12 17:44:09 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixels(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT)
		return ;
	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	process_lines(t_params *params, int i, int j)
{
	t_point	iso;
	t_point	next;
	t_point	below;

	iso = isometric(params->points[i][j], params->width, params->height);
	if (j < params->width - 1)
	{
		next = isometric(params->points[i][j + 1], params->width, params->height);
		ft_xiaolin_wu(iso, next, params->img);
	}
	if (i < params->height - 1)
	{
		below = isometric(params->points[i + 1][j], params->width, params->height);
		ft_xiaolin_wu(iso, below, params->img);
	}
}

void	process_points(t_params *params, int i, int j)
{
	t_point	iso;

	iso = isometric(params->points[i][j], params->width, params->height);
	if (iso.x >= 0 && iso.x < WINDOW_WIDTH && iso.y >= 0 && iso.y < WINDOW_HEIGHT)
		put_pixels(params->img, iso.x, iso.y, 0xFFFFFF);
}

void	points_linking(t_map *map_cpy, t_point **points, t_img *img)
{
	t_params	params;
	int		i;
	int		j;

	params.img = img;
	params.points = points;
	params.width = map_cpy->width;
	params.height = map_cpy->height;
	i = 0;
	while (i < map_cpy->height)
	{
		j = 0;
		while (j < map_cpy->width)
		{
			process_points(&params, i, j);
			process_lines(&params, i, j);
			j++;
		}
		i++;
	}
}

void	draw(t_map *map_cpy, t_data *data)
{
	t_img *img;
	t_map	*current;
	t_point	**points;
	int		i;
	
	img = init_img(data, WINDOW_WIDTH, WINDOW_HEIGHT);
	current = map_cpy->next;
	i = 0;
	points = malloc(sizeof(t_point *) * map_cpy->height);
	if (!points)
	{
		perror("Error:");
		exit(1);
	}
	while (current)
	{
		points[i] = line_to_points(current->line, map_cpy->width, i);
		current = current->next;
		i++;
	}
	points_linking(map_cpy, points, img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->image, 0, 0);
	clean_img(data, img);
	free_points(map_cpy->height, points);
}
