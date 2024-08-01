/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/01 15:57:08 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	isometric(t_point points, int map_width, int map_height)
{
	t_point	new_points;
	double	angle;
	int		offset_x;
	int		offset_y;
	double	center_x;
	double	center_y;
	double	iso_center_x;
	double	iso_center_y;

	angle = 30 * M_PI / 180;
	center_x = (map_width - 1) / 2.0;
	center_y = (map_height - 1) / 2.0;
	iso_center_x = (center_x - center_y) * cos(angle) * SCALE_X;
    iso_center_y = (center_x + center_y) * sin(angle) * SCALE_Y;
	offset_x = (WINDOW_WIDTH / 2) - iso_center_x;	
	offset_y = (WINDOW_HEIGHT / 2) - iso_center_y;
	new_points.x = (points.x - points.y) * cos(angle) * SCALE_X + offset_x;
	new_points.y = (points.x + points.y) * sin(angle) * SCALE_Y - points.z * SCALE_Y / 2 + offset_y;
	new_points.z = points.z;
	return(new_points);
}
