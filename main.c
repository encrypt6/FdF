/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:34:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/06/21 17:39:58 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define ESC_KEY 65307 // ESC keycode on Linux
#include "fdf.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	mlx_pixel_put(mlx_ptr, win_ptr, 400, 300, 0xFFFFFF);
	mlx_key_hook(win_ptr, key_hook, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
