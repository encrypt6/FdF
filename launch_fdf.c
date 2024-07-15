/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/15 20:35:08 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_points(t_map *map, void *mlx_ptr, void *win_ptr)
{
	int x, y;
	t_points *point;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			point = &(map->points[y][x]);
			mlx_pixel_put(mlx_ptr, win_ptr, point->screen_x, point->screen_y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

t_points *parse_line(char *line, int width, int y)
{
	t_points *points;
	char **split_line;
	int x;

	x = 0;
	points = malloc(sizeof(t_points) * width);
	if (!points)
		return (NULL);

	split_line = ft_split(line, ' ');
	while (x < width)
	{
		points[x].x = x;
		points[x].y = y;
		points[x].z = atoi(split_line[x]);
		points[x].screen_x = x;
        points[x].screen_y = y;
		x++;
	}
	free(split_line);
	return points;
}


int count_width(char *line, char space)
{
	int count = 0;
	int in_word = 0;

	while (*line)
	{
		if (*line != space && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*line == space)
			in_word = 0;
        line++;
    }
    return (count);
}


void	get_dimensions(char *map, int *width, int *height)
{
	int		fd;
	char	*line;

	*width = 0;
	*height = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*width == 0)
			*width = count_width(line, ' ');
		(*height)++;
		free(line);
	}
	close (fd);
}

t_map	*read_map(char *map)
{
	int		fd;
	char	*line;
	t_map	*map_struct;
	int		y;

	fd = open(map, O_RDONLY);
	map_struct = malloc(sizeof(t_map));
	if (!map_struct)
		return (NULL);
	get_dimensions(map, &map_struct->width, &map_struct->height);
	map_struct->points = malloc(sizeof(t_points *) * map_struct->height);
	if (!map_struct->points)
	{
		close(fd);
		free(map_struct);
		return (NULL);
	}
	printf("LOOOOOOOOOOL");
	fd = open(map, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_struct->points[y] = parse_line(line, map_struct->width, y);
		if (!map_struct->points[y])
		{
			while (y-- > 0)
				free(map_struct->points[y]);
			free(map_struct);
			close(fd);
			return (NULL);
		}
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map_struct);
}

void	launch_fdf(char *map)
{
	t_data	data;

	data.map = read_map(map);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My FdF");
    draw_points(data.map, data.mlx_ptr, data.win_ptr);
	mlx_key_hook(data.win_ptr, key_hook, NULL);
	mlx_loop(data.mlx_ptr);
	//free(points);
}
