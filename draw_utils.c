/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:03:57 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/20 16:26:25 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*line_to_points(char *line, int width, int row)
{
	char	**splitted_line;
	t_point	*points;
	int		i;

	splitted_line = ft_split(line, ' ');
	points = ft_calloc(sizeof(t_point) * width, 1);
	if (!points)
	{
		free_split(splitted_line);
		perror("Error");
		exit(1);
	}
	i = 0;
	while (i < width && splitted_line[i])
	{
		points[i].x = i * SCALE_X;
		points[i].y = row * SCALE_Y;
		points[i].z = ft_atoi(splitted_line[i]);
		i++;
	}
	free_split(splitted_line);
	return (points);
}
