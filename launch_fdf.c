/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/17 20:50:44 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void launch_fdf(char *map_file)
{
	t_data	data;
    t_map map;

    map.height = get_height(map_file);
//	dprintf(STDOUT_FILENO, "height is : %d\n", map.height);
  	map.width = get_width(map_file);
//	dprintf(STDOUT_FILENO, "width is : %d\n", map.width);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My FdF");
	//generate_points(data.mlx_ptr, data.win_ptr, map.width, map.height);
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 0, 20, 0xFFFFFF); 
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 0, 40, 0xFFFFFF); 
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 0, 60, 0xFFFFFF); 
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 0, 80, 0xFFFFFF); 
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 20, 0, 0xFFFFFF); 
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 40, 0, 0xFFFFFF); 
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 60, 0, 0xFFFFFF); 
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 80, 0, 0xFFFFFF); 
	mlx_key_hook(data.win_ptr, key_hook, NULL);
	mlx_loop(data.mlx_ptr);
}
