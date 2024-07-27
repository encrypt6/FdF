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

float fpart(float x)
{
    return x - floorf(x);
}

float rfpart(float x)
{
    return 1.0 - fpart(x);
}

void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void plot(t_data data, int x, int y, float brightness)
{
    int color = (int)(brightness * 255) << 16 | (int)(brightness * 255) << 8 | (int)(brightness * 255);
    mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, color);
}

void ft_xiaolin_wu(t_point p0, t_point p1, t_data data)
{
    int steep = abs(p1.y - p0.y) > abs(p1.x - p0.x);
    if (steep)
    {
        ft_swap(&p0.x, &p0.y);
        ft_swap(&p1.x, &p1.y);
    }
    if (p0.x > p1.x)
    {
        ft_swap(&p0.x, &p1.x);
        ft_swap(&p0.y, &p1.y);
    }

    float dx = (float)p1.x - (float)p0.x;
    float dy = (float)p1.y - (float)p0.y;
    float gradient = dy / dx;

    float xend = roundf(p0.x);
    float yend = p0.y + gradient * (xend - p0.x);
    float xgap = rfpart(p0.x + 0.5);
    int xpxl1 = xend;
    int ypxl1 = (int)yend;

    if (steep)
    {
        plot(data, ypxl1, xpxl1, rfpart(yend) * xgap);
        plot(data, ypxl1 + 1, xpxl1, fpart(yend) * xgap);
    }
    else
    {
        plot(data, xpxl1, ypxl1, rfpart(yend) * xgap);
        plot(data, xpxl1, ypxl1 + 1, fpart(yend) * xgap);
    }

    float intery = yend + gradient;

    xend = roundf(p1.x);
    yend = p1.y + gradient * (xend - p1.x);
    xgap = fpart(p1.x + 0.5);
    int xpxl2 = xend;
    int ypxl2 = (int)yend;

    if (steep)
    {
        plot(data, ypxl2, xpxl2, rfpart(yend) * xgap);
        plot(data, ypxl2 + 1, xpxl2, fpart(yend) * xgap);
    }
    else
    {
        plot(data, xpxl2, ypxl2, rfpart(yend) * xgap);
        plot(data, xpxl2, ypxl2 + 1, fpart(yend) * xgap);
    }

    if (steep)
    {
        for (int x = xpxl1 + 1; x < xpxl2; x++)
        {
            plot(data, (int)intery, x, rfpart(intery));
            plot(data, (int)intery + 1, x, fpart(intery));
            intery += gradient;
        }
    }
    else
    {
        for (int x = xpxl1 + 1; x < xpxl2; x++)
        {
            plot(data, x, (int)intery, rfpart(intery));
            plot(data, x, (int)intery + 1, fpart(intery));
            intery += gradient;
        }
    }
}

t_point	*line_to_points(char *line, int width, int row)
{
	char **splitted_line;
	t_point *points;
	int i;

	splitted_line = ft_split(line, ' ');
	points = malloc(sizeof(t_point) * width);
	//call check_malloc function
	if (!points)
		return (NULL);
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
	t_point **points;
	int	i;
	int	j;

	current = map_cpy->next;
	i = 0;
	points = malloc(sizeof(t_point *) * map_cpy->height);
	//call check_malloc function
	/*if (!points)
	{
		free_split(splitted_line);
		return NULL;
	}*/
	while (current)
	{
		points[i] = line_to_points(current->line, map_cpy->width, i);
		current = current->next;
		i++;
	}
	i = 0;
	//void	points_linking
	while (i < map_cpy->height)
	{
		j = 0;
		while (j < map_cpy->width)
		{
			printf("Drawing point at (%d, %d)\n", points[i][j].x, points[i][j].y);
			if (points[i][j].x >= 0 && points[i][j].x < WINDOW_WIDTH &&
				points[i][j].y >= 0 && points[i][j].y < WINDOW_HEIGHT)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, points[i][j].x, points[i][j].y, 0xFFFFFF);
			if (j < map_cpy->width - 1)
				ft_xiaolin_wu(points[i][j], points[i][j + 1], data);
			if (i < map_cpy->height- 1)
				ft_xiaolin_wu(points[i][j], points[i + 1][j], data);
			j++;
		}
		i++;
	}
	//put this in free_points function
	i = 0;
	while (i < map_cpy->height)
	{
		free(points[i]);
		i++;
	}
	free(points);
}
