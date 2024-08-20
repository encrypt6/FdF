/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/20 14:57:42 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_data *data, t_map *map_cpy)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_dprintf(STDERR_FILENO, "Error: mlx_init() failed\n");
		free_map(map_cpy);
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "My FdF");
	if (!data->win_ptr)
	{
		ft_dprintf(STDERR_FILENO, "Error: mlx_new_window() failed\n");
		free_map(map_cpy);
		exit(1);
	}
}

void	launch_fdf(char *map_file)
{
	t_data	*data;
	t_map	*map_cpy;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Error");
		exit(1);
	}
	map_cpy = cpy_map_to_list(map_file);
	if (!map_cpy)
	{
		ft_dprintf(STDERR_FILENO, "Error: failed to copy map\n");
		free_map(map_cpy);
		free(data);
		exit(1);
	}
	init(data, map_cpy);
	draw(map_cpy, data);
	free_map(map_cpy);
	mlx_key_hook(data->win_ptr, esc_exit, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
