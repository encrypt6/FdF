/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/25 19:03:09 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	isometric(t_point points, int map_width, int map_height)
{
	t_point	new_points;
	int	offset_x;
	int	offset_y;
	double	angle_x;
	double	angle_y;
	int	total_width;
	int	total_height;

	total_width = (map_width - 1) * SCALE_X;
	total_height = (map_height - 1) * SCALE_Y;
	offset_x = (WINDOW_WIDTH / 2) - (total_width / 2);	
	offset_y = (WINDOW_HEIGHT / 2) - (total_height / 2);
	angle_x = 30 * M_PI / 100;
	angle_y = 30 * M_PI / 100;
	new_points.x = (points.x - points.y) * cos(angle_x) * SCALE_X + offset_x;
	new_points.y = (points.x + points.y) * sin(angle_y) * SCALE_Y- points.z * SCALE_Y / 2 + offset_y;
	new_points.z = points.z;
	return(new_points);
}
