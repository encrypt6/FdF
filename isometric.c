/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/12 19:52:52 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	isometric(t_point points, int map_width, int map_height)
{
	t_iso	params;	
	t_point	new_points;

	params.angle = 30 * M_PI / 180;
	params.center_x = (map_width - 1) / 2.0;
	params.center_y = (map_height - 1) / 2.0;
	params.iso_center_x = (params.center_x - params.center_y)
		* cos(params.angle) * SCALE_X;
	params.iso_center_y = (params.center_x + params.center_y)
		* sin(params.angle) * SCALE_Y;
	params.offset_x = (WINDOW_WIDTH / 2) - params.iso_center_x;
	params.offset_y = (WINDOW_HEIGHT / 2) - params.iso_center_y;
	new_points.x = (points.x - points.y) * cos(params.angle)
		* SCALE_X + params.offset_x;
	new_points.y = (points.x + points.y) * sin(params.angle)
		* SCALE_Y - points.z
		* SCALE_Y / 2 + params.offset_y;
	new_points.z = points.z;
	return (new_points);
}
