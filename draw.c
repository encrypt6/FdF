/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/01 14:54:34 by elsikira         ###   ########.fr       */
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

t_img	*init_img(t_data *data, int win_width, int win_height)
{
	t_img	*img;
	int	endian;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->image = mlx_new_image(data->mlx_ptr, win_width, win_height);
	img->data = mlx_get_data_addr(img->image, &img->bpp, &img->size_line, &endian);
	img->width = win_width;
	img->height = win_height;
	return (img);
}

void	points_linking(t_data data, t_map *map_cpy, t_point **points)
{
	int	i;
	int	j;
	t_point	iso_points;
	t_point	next_iso_points;
	t_point	below_iso_points;
	t_img *img;
	
	img = init_img(&data, WINDOW_WIDTH, WINDOW_HEIGHT);
	i = 0;
	while (i < map_cpy->height)
	{
		j = 0;
		while (j < map_cpy->width)
		{
			iso_points = isometric(points[i][j], map_cpy->width,
					map_cpy->height);
			if (iso_points.x >= 0 && iso_points.x < WINDOW_WIDTH
				&& iso_points.y >= 0 && iso_points.y < WINDOW_HEIGHT)
				put_pixels(img, iso_points.x, iso_points.y, 0xFFFFFF);
			if (j < map_cpy->width - 1)
			{
				next_iso_points = isometric(points[i][j + 1],
						map_cpy->width, map_cpy->height);
				ft_xiaolin_wu(iso_points, next_iso_points, img);
			}
			if (i < map_cpy->height - 1)
			{
				below_iso_points = isometric(points[i + 1][j],
						map_cpy->width, map_cpy->height);
				ft_xiaolin_wu(iso_points, below_iso_points, img);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img->image, 0, 0);
	mlx_destroy_image(data.mlx_ptr, img->image);
	free(img);
}

t_point	*line_to_points(char *line, int width, int row)
{
	char	**splitted_line;
	t_point	*points;
	int		i;

	splitted_line = ft_split(line, ' ');
	points = malloc(sizeof(t_point) * width);
	if (!points)
	{
		free_split(splitted_line);
		return (NULL);
	}
	i = 0;
	while (i < width)
	{
		points[i].x = i * SCALE_X;
		points[i].y = row * SCALE_Y;
		points[i].z = ft_atoi(splitted_line[i]);
		i++;
	}
	free_split(splitted_line);
	return (points);
}

void	draw(t_map *map_cpy, t_data data)
{
	t_map	*current;
	t_point	**points;
	int	i;

	current = map_cpy->next;
	i = 0;
	points = malloc(sizeof(t_point *) * map_cpy->height);
	if (!points)
		return ;
	while (current)
	{
		points[i] = line_to_points(current->line, map_cpy->width, i);
		current = current->next;
		i++;
	}
	points_linking(data, map_cpy, points);
	i = 0;
	while (i < map_cpy->height)
	{
		free(points[i]);
		i++;
	}
	free(points);
}
