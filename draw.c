/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/25 19:03:09 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*line_to_points(char *line, int width)
{
	char **splitted_line;
	t_point *points;
	int i;

	splitted_line = ft_split(line, ' ');
	points = malloc(sizeof(t_point) * width);
	if (!points)
		return (NULL);
	i = 0;
	while (i < width)
	{
		points[i].x = i;
		points[i].y = 0;
		points[i].z = ft_atoi(splitted_line[i]);
		i++;
	}
	free_split(splitted_line);
	return (points);
}

void	draw(t_map *map_cpy, t_data data)
{
	t_map	*current;
	t_point **points;
	int	i;
	int	j;

	current = map_cpy->next;
	i = 0;
	points = malloc(sizeof(t_point *) * map_cpy->height);
	if (!points)
		return ;

	while (current)
	{
		points[i] = line_to_points(current->line, map_cpy->width);
		current = current->next;
		i++;
	}
	i = 0;
	while (i < map_cpy->height)
	{
		j = 0;
		while (j < map_cpy->width)
		{
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, points[i][j].x, points[i][j].y, 0xFFFFFF);
			//if (j < num_points - 1)
			//	ft_bresenham();
			j++;
		}
		//bresenham
		i++;
	}
	i = 0;
	while (i < map_cpy->height)
	{
		free(points[i]);
		i++;
	}
	free(points);
}
