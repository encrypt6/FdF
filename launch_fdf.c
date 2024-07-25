/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/25 14:55:07 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	launch_fdf(char *map_file)
{
	//t_data	data;
    t_map *map_cpy;

	map_cpy = cpy_map_to_struct(map_file);
	fill_matrix(map_cpy);
	//data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My FdF");
	//generate_points(data.mlx_ptr, data.win_ptr, map.width, map.height);
	//mlx_key_hook(data.win_ptr, key_hook, NULL);
	//mlx_loop(data.mlx_ptr);
}
