/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/15 15:36:03 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	launch_fdf(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My FdF");
	mlx_pixel_put(mlx_ptr, win_ptr, 400, 300, 0xFFFFFF);

	mlx_key_hook(win_ptr, key_hook, NULL);
	mlx_loop(mlx_ptr);
}
